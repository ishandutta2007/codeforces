#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,M=31;
ll cnt[40];
ll a[N];
vector <int> p[N];
ll ted[N];
int Main(){
    ll n;
    cin >> n;
    //cout << n << endl;
    memset(cnt,0,sizeof cnt);
    for (int i=1;i<=n;i++) ted[i]=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        for (int j=0;j<M;j++){
            if ((a[i] & (1<<j))) cnt[j]++;
        }
    }
    ll mx=0;
    for (int i=0;i<M;i++){
        if (cnt[i]!=0) mx++;
        for (auto u : p[cnt[i]]) ted[u]++;
    }
    for (int i=1;i<=n;i++){
        if (ted[i]==mx) cout << i << " ";
    }
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j+=i) p[j].pb(i);
    }
    ll t=1;
    cin >> t;
    while(t--) Main();
}