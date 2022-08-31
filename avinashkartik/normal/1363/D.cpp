#include<bits/stdc++.h>

using namespace std;
 
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, ans[N];
vll s[N];

void q(ll l, ll r){
    cout<<"? "<<(r-l+1);
    for(int i = l; i <= r; i++) cout<<" "<<i;
    cout<<endl;
    fflush(stdout);
}

void solve(){
    cin>>n>>k;
    for(int i = 0; i < k; i++){
        int c,x;
        cin>>c;
        for(int j = 0 ; j < c; j++){
            cin>>x;
            s[i].pb(x);
        }
    }
    q(1,n);
    int m = 0,ip,ind;
    cin>>m;
    ll l = 1, r = n;
    while(l < r){
        ll mid = (l+r)/2;
        q(l,mid);
        cin>>ip;
        if(ip != m){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    ind = l;
    set <ll> ss;
    for(int i = 1; i <= n; i++){
        ss.insert(i);
    }
    for(int i = 0; i < k; i++){
        int c = s[i].size(), f = 0;
        for(int j = 0 ; j < c; j++){
            if(s[i][j] == ind)
                f = 1;
        }
        if(f == 1){
            for(auto it : s[i]) ss.erase(it);
            cout<<"? "<<ss.size();
            for(auto it : ss) cout<<" "<<it;
            cout<<endl;
            fflush(stdout);
            cin>>ip;
            ans[i] = ip;
        }
        else ans[i] = m;
    }
    cout<<"!";
    for(int i = 0; i < k; i++){
        cout<<" "<<ans[i];
        s[i].clear();
    }
    cout<<endl;
    fflush(stdout);
}

int main(){
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
        string txt;
        cin>>txt;
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}