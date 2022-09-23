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
ll L[maxN], R[maxN];
int Q;
int ans[35];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    cin >> Q;
    for (int bit = 0; bit < 30; bit++) {
        int add = 0;
        ll F = (1 << bit);
        vector<pair<ll,ll>> segs;
        vector<ll> cur;
        for (int i = 1; i <= n; i++) {
            ll len = R[i] - L[i] + 1;
            if (len >= F) {
                add++;
            }
            else {
                ll from = L[i] % F;
                //add++
                ll to = R[i] % F;
                segs.emplace_back(from, to);
                cur.emplace_back(from);
                cur.emplace_back((to + 1) % F);
            }
        }
        sort(cur.begin(), cur.end());
        cur.erase(unique(cur.begin(), cur.end()), cur.end());
        vector<int> delta(cur.size() + 1);
        for (auto& it : segs) {
            int pos1 = lower_bound(cur.begin(), cur.end(), it.first) - cur.begin() + 1;
            int pos2 = lower_bound(cur.begin(), cur.end(), (it.second + 1) % F) - cur.begin() + 1;
            if (it.first <= it.second) {
                delta[pos1] += 1;
                if (it.second != (F - 1)) {
                    delta[pos2] -= 1;
                }
            }
            else {
                delta[0] += 1;
                delta[pos2] -= 1;
                delta[pos1] += 1;
            }
        }
        int mx = add;
        for (int i = 1; i <= cur.size(); i++) {
            delta[i] += delta[i - 1];
            mx = max(mx, delta[i] + add);
        }
        ans[bit] = mx;
    }
    while (Q--) {
        ll W;
        cin >> W;
        for (int c = 0; c < 30; c++) {
            if (W & (1LL << c)) {
                cout << ans[c] << '\n';
                break;
            }
        }
    }
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}