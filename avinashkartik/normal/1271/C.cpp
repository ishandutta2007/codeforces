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
 
ll n,m,m1,ans,ans1,u1,v,x,y;
string s[N];



int main(){
    fastio;
    cin>>n>>x>>y;
    ll u = 0,l = 0,d = 0,r = 0;
    for(int i = 0; i < n; i++){
        cin>>u1>>v;
        if(u1 < x)
            l += 1;
        else if(u1 > x)
            r += 1;
        if(v < y)
            d += 1;
        else if(v > y)
            u += 1;
    }
    if(x == 0){
        m = 1;
        ans = r;
    }
    else if(x == MAXN){
        m = -1;
        ans = l;
    }
    else{
        if(r > l){
            m = 1;
            ans = r;
        }
        else{
            m = -1;
            ans = l;
        }
    }
    if(y == 0){
        m1 = 1;
        ans1 = u;
    }
    else if(y == MAXN){
        m1 = -1;
        ans1 = d;
    }
    else{
        if(u > d){
            m1 = 1;
            ans1 = u;
        }
        else{
            m1 = -1;
            ans1 = d;
        }
    }
    if(ans > ans1){
        printf("%lld\n%lld %lld",ans,x+m,y);
    }
    else{
        printf("%lld\n%lld %lld",ans1,x,y+m1);
    }

}