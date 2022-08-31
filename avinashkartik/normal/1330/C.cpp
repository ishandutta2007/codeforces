#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,m,x,a[N],suf[N],ans[N];
set <ll> s;
vpll c;

void solve(){
    cin>>m>>n;
    memset(ans,0,sizeof(ans));
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }
    suf[n-1] = a[n-1];
    for(int i = n-2 ; i >= 0; i--){
        suf[i] = suf[i+1]+a[i];
    }
    ll j = 0;
    ll fin = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > m-j){
            cout<<-1<<endl;
            return;
        }
        if(i == 0){
            ans[i] = j;
            fin = a[i];
        }
        else{
            if(suf[i] >= m-j+1) j += 1;
            else j += m-j-suf[i];
            if(j == ans[i-1]) j++;
            if(j > fin){
                cout<<-1<<endl;
                return;
            }
            ans[i] = j;
            fin = max(fin,j+a[i]);
        }
        //cout<<j<<" "<<fin<<endl;
    }
    if(fin != m){
        cout<<-1<<endl;
        return;
    }
    for(int i = 0 ; i < n; i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}