#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ld>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,a[N];
void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    ll p = 1, m = a[n];
    bool f = 1;
    for(int i = n; i > 0; i--){
        if(a[i] == p) p = m+1,m = a[i-1];
        else{
            if(a[i] != a[i-1]+1){
                f = 0;
                break;
            }
        }
    }
    if(f == 0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}