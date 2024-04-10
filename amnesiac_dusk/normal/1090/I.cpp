#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
const int N = 1e7 + 5;
int b[N], a[N];
void solve(){
    int n, l, r, x, y, z;
    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
    // cin >> n;
    int m = (1LL << 32);
    fr(i, 3, n){
        b[i] = (((unsigned int)b[i - 2] * x) % m + ((unsigned int)b[i - 1] * y) % m + z) % m;
        b[i] = (b[i] + m) % m;
    }
    int mini = 5e18;
    int ans = 5e18;
    fr(i, 1, n){
        a[i] = (b[i] % (r - l + 1)) + l;
        // cin >> a[i];
        if(a[i] >= 0){
            if(mini < a[i]){
                ans = min(ans, a[i] * mini);
            }
        }
        mini = min(mini, a[i]);
    }
    mini = 5e18;
    for(int i = n; i >= 1; i--){
        if(a[i] < 0){
            if(mini < (-a[i]))
                ans = min(ans, (-a[i]) * mini);
            mini = min(mini, (-a[i]));
        }
    }
    if(ans == 5e18)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
}
signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t = 1;
    cin >> t;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
}