#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  4e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test=1, n, ans1[N], ans2[N], x[N], y[N], m[N];
set <pll> s;

struct seg{
    int l, r, i;
    bool operator <(const seg & s1) const{
        return l < s1.l;
    }
};

vector <seg> a;

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
        a.pb({x[i],y[i],i});
    }
    sort(a.begin(), a.end());
    ll p = 0, f = 0;
    for(int i = 0; i < n; i++){
        int j = p;
        while(j < n && a[j].l == i+1){
            s.insert({a[j].r,a[j].i});
            j++;
        }
        p = j;
        auto it = s.begin();
        ans1[(*it).s] = i+1;
        ans2[(*it).s] = i+1;
        m[i+1] = (*it).s;
        s.erase(it);
    }
    for(int i = 1; i < n; i++){
        ll ind1 = m[i], ind2 = m[i+1];
        if(x[ind1] <= i+1 && i+1 <= y[ind1] && x[ind2] <= i && i <= y[ind2]){
            f = 1;
            swap(ans2[ind1],ans2[ind2]);
            break;
        }
    }
    if(f == 1){
        cout<<"NO"<<endl;
        for(int i = 0; i < n; i++) cout<<ans1[i]<<" ";
        cout<<endl;
        for(int i = 0; i < n; i++) cout<<ans2[i]<<" ";
    }
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++) cout<<ans1[i]<<" ";
    }
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}