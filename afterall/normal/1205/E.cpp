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
ll mod=1e9+7;
ll power(ll n,ll k){
    if (k<0) k+=mod-1;
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
vector <int> t[N];
vector <int> m[N];
int32_t main(){
    sync;
    ll n,k;
    cin >> n >> k;
    ll ans=0;
   // cout << power(k,1-1) << " " << power(k,-1) << endl;
    for (int i=1;i<n;i++){
        for (int j=i;j<2*n;j+=i) m[j].pb(i);
    }
    for(int i=1;i<N;i++){
        reverse(m[i].begin(),m[i].end());
    }
    for (int i=1;i<n;i++){
        ans+=power(k,-i)%mod;
    }
   // cout << ans%mod << endl;
    for (int i=1;i<n;i++){
        for (int j=i;j<2*n;j+=i){
            ll z=(n-1)/i;
            ll o=0;
            if (j/i%2==0) o=-1;
            t[i].pb(j/i-1-(max((ll)0,j/i-1-z))*2+o);
         //   cout << i << "  f  " << j << " " << t[i].back() << endl;
        }
    }

    for (int i=1;i<n;i++){
        for (int j=0;j<t[i].size();j++){
       //     cout << i << " kir " << i*(j+1) << " " << t[i][j] << endl;
        }
    }
    ll cnt=0;
    for (int i=n-1;i;i--){
        for (int j=1;j<t[i].size();j++){
            ll u=i*(j+1);
            for (int p=0;p<m[u/i].size();p++){
                ll z=m[u/i][p]*i;
                if (z>=n || z==i) continue;
               // cout << i << " " << z << " " << u << endl;
          //      if (m[u][p]<=i) break;
                cnt++;
            //    if (z%i!=0) continue;
                ll y=u/z-1;
                t[i][j]-=t[z][y];
            }
            /*
            for (int p=u;p<n;p+=u){
                ll z=u/p-1;
                t[i][j]-=t[p][z];
            }
            */
        }
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<t[i].size();j++){
            ll p1=0;
            ll s=i*(j+1);

      //      cout << i << " " << s << " " << t[i][j] << " " << p1<< endl;
            //if (p1!=t[i][j]) kill("KIR");
            ll z=max(s-n,i);
            ans+=power(k,z-n)*t[i][j];
            ans%=mod;
        }
    }
    cout << ans << endl;
}