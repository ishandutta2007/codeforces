#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
  
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
    change null_type to int if we want to use map instead
    find_by_order(k) returns an iterator to the k-th element (0-indexed)
    order_of_key(k) returns numbers of item being strictly smaller than k
*/
template<typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 400005;
const int MOD = 998244353;

vector<int> fac, ifac;

void run_case() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    ordered_set<int> os;
    for (int i = 0; i < m; i++) {
        cin >> p[i].first >> p[i].second;
    }
    vector<int> inc_pos;
    for (int i = m - 1; i >= 0; i--) {
        int id_need = p[i].second;
        int l = 1, r = n;
        int true_id = 0;
        while (r >= l) {
            int mid = (l + r) / 2;
            int cnt = mid - os.order_of_key(mid + 1); // find the number of integer not in os <= mid
            if (cnt >= id_need) {
                true_id = mid;
                r = mid - 1; 
            } else l = mid + 1;
        }
        if (os.find(true_id + 1) == os.end()) inc_pos.push_back(true_id);
        os.insert(true_id);
    }
    cout << 1LL * fac[2 * n - inc_pos.size() - 1] * ifac[n] % MOD * ifac[n - inc_pos.size() - 1] % MOD << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif

    auto power = [](int x, int y) {
        int res = 1;
        while (y) {
            if (y % 2) res = 1LL * res * x % MOD;
            y >>= 1;
            x = 1LL * x * x % MOD;
        }
        return res;
    };

    fac.resize(N, 1), ifac.resize(N, 1);
    for (int i = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
    ifac[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;

    int tests = 1;
    cin >> tests;
    while (tests--) run_case();
    return 0;
}