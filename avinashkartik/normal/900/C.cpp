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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e8;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,a[N],p[N];
set <ll> s;

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    s.insert(a[0]);
    p[a[0]] -= 1;
    for(int i = 1; i < n; i++){
        auto it = s.end();
        it--;
        auto find = s.upper_bound(a[i]);
        if(find == it) p[*it]++;
        else if(find == s.end()) p[a[i]]--;
        s.insert(a[i]);
    }
    ll ans  = 1;
    for(int i = 1; i <= n; i++){
        //cout<<p[i]<<" ";
        if(p[i] > p[ans]) ans = i;
    }
    cout<<ans<<endl;
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}