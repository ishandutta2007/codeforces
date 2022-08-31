#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<pll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

int test=1,a[N];
string s,t;

ll solve(){
    t = "";
    cin>>s;
    int m = 0, n = s.size(), i = 0;
    while(i < n){
        int j = i;
        t += s[j];
        while(j < n and s[j] == s[i])j++;
        a[m++] = j-i;
        i = j;
    }
    int ans = n+1;
    for(int i = 0 ; i < m-2; i++){
        if((t[i]-'0')*(t[i+1]-'0')*(t[i+2]-'0') == 6){
            ans = min(ans,a[i+1]+2);
        }
    }
    if(ans == n+1) ans = 0;
    return ans;
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        deb1(solve());
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}