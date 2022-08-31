#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  65;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n = 0,m = 0,r[N],c[N];
string s[N];

int main(){
    fastio;
    ll te;
    cin>>te;
    while(te--){
        fill_n(r,n+1,0);
        fill_n(c,m+1,0);
        cin>>n>>m;
        ll cp = 0,ca = 0;
        ll ans = 4;
        for(int i = 0; i < n; i++){
            cin>>s[i];
            for(int j = 0; j < m; j++){
                if(s[i][j] == 'A'){
                    ca++;
                    r[i] += 1;
                    c[j] += 1;
                }
                else cp++;
            }
        }
        if(ca == n*m){
            cout<<0<<endl;
            continue;
        }
        if(cp == n*m){
            cout<<"MORTAL"<<endl;
            continue;
        }

        if(r[0] == m || r[n-1] == m || c[0] == n || c[m-1] == n)
            cout<<1<<endl;
        else{
            for(int i = 0; i < n; i++)
                if(r[i] == m) ans = 2;
            for(int i = 0; i < m; i++)
                if(c[i] == n) ans = 2;
            if(s[0][0] == 'A' || s[0][m-1] == 'A' || s[n-1][0] == 'A' || s[n-1][m-1] == 'A')
                ans = 2;
            if(r[0] >= 1 || r[n-1] >= 1 || c[0] >= 1 || c[m-1] >= 1)
                ans = min(ans,3ll);
            cout<<ans<<endl;
        }
    }

    
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}