#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

//int inv(int x) {
//    return bp(x, mod - 2);
//}

int n;
const int maxN = 1e5 + 10;
ll pref[maxN];
ll A[maxN];
int fenw[maxN];
int get(int r) {
    int ans = 0;
    while (r > 0) {
        ans += fenw[r];
        r &= (r - 1);
    }
    return ans;
}
void upd(int v, int by) {
    while (v < maxN) {
        fenw[v] += by;
        v = (v | (v - 1)) + 1;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = pref[i - 1] + A[i];
    }
    for (int i = 1; i < n; i++) {
        if (pref[i] < 0 || pref[i] > pref[n]) {
            cout << -1;
            return ;
        }
    }
    if (pref[n] < 0) {
        cout << -1;
        return;
    }
    vector<pair<ll,int>> gg;
    for (int i = 1; i < n; i++) {
        gg.emplace_back(pref[i], i);
    }
    sort(gg.begin(), gg.end());
    reverse(gg.begin(), gg.end());
    ll inv = 0;
    for (auto& it : gg) {
        inv += get(it.second);
        upd(it.second, +1);
    }
    cout << inv << '\n';
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}