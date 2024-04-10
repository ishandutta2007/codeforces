#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;
using ull = unsigned long long;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 2e5;
const int mod = 998244353;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;
const int BL = 317;

bool ask(ll l, ll r) {
    cout << l << ' ' << r << endl;
    string s; cin >> s;
    if(s[0] == 'B') exit(0);
    return s[0] == 'Y';
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    srand(time(0));
    ll n, k; cin >> n >> k;
    ll lf = 1, rg = n;
    while(true) {
        while(rg - lf > 4 * k + 1) {
            ll md = (lf + rg) / 2;
            if(ask(lf, md)) lf = max(1LL, lf - k), rg = min(n, md + k);
            else lf = max(1LL, md + 1 - k), rg = min(n, rg + k);
        }
        ll id = lf + rand() % (rg - lf + 1);
        if(ask(id, id)) return 0;
        lf = max(1LL, lf - k);
        rg = min(n, rg + k);
    }
}