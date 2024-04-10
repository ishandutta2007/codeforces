#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=110;

ll a[N], b[N];

int Main(){
    bitset<10010> bt;
    for(int i =0 ; i < 10010; i++) bt[i] = 0;
    bt[0] = 1;
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    if(n == 1) return cout << "0\n", 0;
    ll S = 0;
    for(int i = 0; i < n; i++){
        ans += 1ll * (n - 2) * a[i] * a[i];
        ans += 1ll * (n - 2) * b[i] * b[i];
        bt = (bt << a[i]) | (bt << b[i]);
        S += a[i] + b[i];
    }
    // debug(ans);
    ll mn = S * S;
    for(int i = 0; i <= S; i++){
        if(!bt[i]) continue;
        // debug(i);
        mn = min(mn, 1ll * i * i + (S - i) * (S - i));
    }
    cout << ans + mn << '\n';
    return 0;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc --) Main();
    return 0;
}