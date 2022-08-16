#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  205;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,sz,dp[N][N][2*N],go[N][N][2*N];
string s,t,ans;

ll mem(ll i, ll j, ll bal){
    if(i == n && j == m){
        if(bal == 0)
            return 0;
        else{
            dp[i][j][bal] = mem(i,j,bal-1)+1;
            go[i][j][bal] = -1;
            return dp[i][j][bal];
        }
    }
    if(dp[i][j][bal] != -1) return dp[i][j][bal];
    ll res=INFi;
    for(auto ch : {'(',')'}){
        ll ni=i,nj=j,nbal=bal;
        if(i != n && s[i] == ch) ni=i+1;
        if(j != m && t[j] == ch) nj=j+1;
        if(ch == '(') nbal = bal+1;
        else nbal = bal-1;
        if(nbal < 0) continue;
        if(ni == i && nj == j && bal != 0) continue;
        ll x = mem(ni,nj,nbal)+1;
        if(res > x){
            res = x;
            go[i][j][bal] = nbal-bal;
        }
    }
    return dp[i][j][bal]=res;
}

void construct(ll ind, ll i, ll j, ll bal){
    //cout<<ind<<" "<<i<<" "<<j<<" "<<go[i][j][bal]<<endl;
    if(ind == sz)
        return;
    ll ni=i,nj=j,nbal=bal+go[i][j][bal];
    char ch;
    if(go[i][j][bal] == 1) ch = '(';
    else ch = ')';
    if(i != n && s[i] == ch) ni++;
    if(j != m && t[j] == ch) nj++;
    ans += ch;
    construct(ind+1,ni,nj,nbal);
}


void solve(){
    mset(dp,-1);
    cin>>s>>t;
    n = s.size();
    m = t.size();
    sz = mem(0,0,0);
    //cout<<sz<<endl;
    construct(0,0,0,0);
    cout<<ans<<endl;
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