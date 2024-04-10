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
ll p2[N];
ll mod=998244353;
ll n,x;
ll mx=0;
ll solve(pair <vector <int> ,vector <int> > q,int I){
    if (I==-1) return 0;
    vector <int> v0,v1,w0,w1;
    vector <int> g=q.F,y=q.S;
    ll ans=0;
    for (auto u : g){
        if ((u & ((ll)1<<I))) v1.pb(u);
        else v0.pb(u);
    }
    for (auto u : y){
        if ((u & ((ll)1<<I))) w1.pb(u);
        else w0.pb(u);
    }
    if ((x & (1<<I))){
        ans+=p2[v0.size()+w0.size()]+p2[v1.size()+w1.size()]-p2[v0.size()]-p2[v1.size()]-p2[w1.size()]-p2[w0.size()];
        ans%=mod;
        ans+=mod;
        ans%=mod;
        if (I==mx){
            ans+=p2[v0.size()]+p2[v1.size()]+p2[w0.size()]+p2[w1.size()];
            ans%=mod;
            if (v0.size()+v1.size()) ans+=solve({v0,v1},I-1);
            if (w0.size()+w1.size()) ans+=solve({w0,w1},I-1);
        }
        else {
            ll s=0,t=0;
            if (v0.size()+w1.size()) s=solve({v0,w1},I-1);
            if (v1.size()+w0.size()) t=solve({v1,w0},I-1);
            ans+=s*t%mod;
            ans+=s;
            ans+=s*(p2[w0.size()]+p2[v1.size()])%mod;
            ans+=t;
            ans+=t*(p2[w1.size()]+p2[v0.size()])%mod;
            ans%=mod;
            ans+=mod;
            ans%=mod;
        }
    }
    else{
        if (v1.size()+w1.size()) ans+=solve({v1,w1},I-1);
        if (v0.size()+w0.size()) ans+=solve({v0,w0},I-1);
        ans%=mod;
    }
    return ans;
           // if (I>mx) ans=0;

}
int32_t main(){
    sync;
    p2[0]=1;
    for (int i=1;i<N;i++){
        p2[i]=p2[i-1]*2%mod;
    }
    for (int i=0;i<N;i++) p2[i]--;
    cin >> n >> x;
    x++;
    vector <pair <vector <int> ,vector <int> > > a;
    vector <int> B,C;
    for (int i=1;i<=n;i++){
        ll z;
        cin >> z;
        B.pb(z);
    }
    a.pb({B,C});
    ll ans=0;
    for (int i=0;i<=30;i++){
        if ((x & ((ll)1<<i))) mx=i;
    }
    ans=solve({B,C},30);
    ans%=mod;
    ans+=mod;
    ans%=mod;

    cout << ans << endl;
}