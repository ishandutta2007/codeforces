//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
#define int ll

const int maxn = 5e5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, q; cin >> n >> q;
    ll ad = (1LL * n * n + 1) / 2;
    while(q--) {
        int i, j; cin >> i >> j;
        if((i + j) % 2 == 0) {
            if(n % 2 == 0) {
                cout << 1LL * (n / 2) * (i - 1) + (j + 1) / 2 << '\n';
            } else {
                int one = (n + 1) / 2 + n / 2;
                ll me = 1LL * ((i - 1) / 2) * one;
                if(i % 2 == 0) cout << me + (n + 1) / 2 + j / 2 << '\n';
                else cout << me + (j + 1) / 2 << '\n';
            }
        } else {
            if(n % 2 == 0) {
                cout << ad + 1LL * (n / 2) * (i - 1) + (j + 1) / 2 << '\n';
            } else {
                int one = n / 2  + (n + 1) / 2;
                ll me = 1LL * ((i - 1) / 2) * one;
                if(i % 2 == 0) cout << ad + me + n / 2 + (j + 1) / 2 << '\n';
                else cout << ad + me + j / 2 << '\n';
             }
        }
    }
}