#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

int query(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

unordered_map<long long, int, custom_hash> done;

int zeros(int l, int r) {
    if (done.find(r) != done.end()) {
        return done[r];
    }
    int ones = query(l, r);
    int ans = r - l + 1 - ones;
    done[r] = ans;
    return ans;
}

int bin_search(int n, int k) {
    int l = -1, r = n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (zeros(0, m) >= k)
            r = m;
        else
            l = m;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, t;
    cin >> n >> t;
    forn (iter, 0, t) {
        int k;
        cin >> k;
        int ans = bin_search(n, k);
        cout << "! " << ans + 1 << endl;
        for (auto& [r, val] : done) {
            if (r >= ans) {
                --val;
            }
        }
    }
    return 0;
}