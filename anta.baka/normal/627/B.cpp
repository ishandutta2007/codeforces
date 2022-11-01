//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;

struct fen {
    int n; vector<int> t;
    fen(int n) : n(n), t(n, 0) {}
    void upd(int v, int x) {
        for(int i = v; i < n; i |= i + 1) t[i] += x;
    }
    int get(int v) {
        int ret = 0;
        for(int i = v; i >= 0; i = (i & (i + 1)) - 1) ret += t[i];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, k, a, b, q; cin >> n >> k >> a >> b >> q;
    fen t1(n), t2(n);
    while(q--) {
        int ty; cin >> ty;
        if(ty == 1) {
            int d, ai; cin >> d >> ai;
            d--;

            t1.upd(d, ai);
            int cur = t1.get(d) - t1.get(d - 1);
            if(cur > a) t1.upd(d, a - cur);

            t2.upd(d, ai);
            cur = t2.get(d) - t2.get(d - 1);
            if(cur > b) t2.upd(d, b - cur);
        } else {
            int l; cin >> l; l--; int r = l + k - 1;
            cout << t2.get(l - 1) + t1.get(n - 1) - t1.get(r) << '\n';
        }
    }
}