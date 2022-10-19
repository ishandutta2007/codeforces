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
const int N=2e5+100;
map <int,int> mp;
ll mod=1e9+7;
ll dp[N];
void Main(){
    vector <int> a;
    ll n,p;
    cin >> n >> p;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
        mp[x]=1;
    }
    dp[0]=1;
    for (int i=1;i<N;i++){
        dp[i]=1+dp[i-1];
        if (i-2>=0) dp[i]+=dp[i-2];
        dp[i]%=mod;
    }
    ll ans=0;
    for (auto u : a){
      // /  cout << u << " jrn " << endl;
        ll p1=0;
        ll x=u;
        while(x%2==1 || x%4==0){
            if (x%2==1){
                x/=2;
            }
            else x/=4;
            if (mp[x]) p1=1;
            if (x==0) break;
        }
        if (p1) continue;
        ll z=0;
        x=u;
        while(x){
            x/=2;
            z++;
        }
        if (z<=p) {
         //   cout << dp[p-z] << " " << p-z << " " << z << " " << u << endl;
            ans+=dp[p-z];
        }
        ans%=mod;
    }
    cout << ans << endl;
    return ;



}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--) Main();
}