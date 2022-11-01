#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using ull = unsigned long long;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 1e6;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;
const int BL = 317;

int cnt[maxn];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; cnt[x - 1]++;
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x; cnt[x - 1]--;
    }
    ll ans = 0;
    bool one = true;
    for(int i = maxn - 1; i >= 0; i--) {
        while(cnt[i] != 0) {
            if(one) {
                if(cnt[i] > 0) ans += i, cnt[i]--;
                else cnt[i]++;
                one = !one;
            } else {
                if(cnt[i] < 0) ans -= i, cnt[i]++;
                else cnt[i]--;
                one = !one;
            }
        }
    }
    cout << ans;
}