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
 
const ll   N     =  2e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,k,a[N],ch[N],val,go[N][N],dp[N][N],ans[128][10];

void convert(ll ind, ll x){
    if(ind == 0){
        if(ch[val] < ch[x]) val = x;
        return;
    }
    for(int i = 0; i < 7; i++){
        ll y = 1<<i;
        if(x&y) continue;
        convert(ind-1,x+y);
    }
}

bool rec(ll ind, ll k){
    if(ind == n){
        return k == 0;
    }
    if(dp[ind][k] != -1) return dp[ind][k];
    ll prev = -1;
    dp[ind][k] = 0;
    for(int i = 0; i <= min(7ll,k); i++){
        if(ch[ans[a[ind]][i]] != -1){
            ll x = rec(ind+1,k-i);
            if(x == 1){
                if(ch[ans[a[ind]][i]] > prev){
                    prev = ch[ans[a[ind]][i]];
                    go[ind][k] = i;
                }
                dp[ind][k] = 1;
            }
        }
    }
    return dp[ind][k];
}

void construct(ll ind, ll k){
    if(ind == n) return;
    val = 0;
    convert(go[ind][k],a[ind]);
    cout<<ch[val];
    construct(ind+1,k-go[ind][k]);
}

ll toint(string s){
    ll res = 0;
    for(int i = 0; i < 7; i++){
        if(s[i] == '1')
            res += 1<<(6-i);
    }
    return res;
}

void solve(){
    mset(ch,-1);
    mset(dp,-1);
    string nos[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" }; 
    for(int i = 0; i < 10; i++){
        ll no = toint(nos[i]);
        ch[no] = i;
    }
    for(int i = 0; i < 128; i++){
        for(int j = 0; j < 8; j++){
            val = 0;
            convert(j,i);
            ans[i][j] = val;
        }
    }
    cin>>n>>k;
    string x;
    for(int i = 0; i < n; i++){
        cin>>x;
        a[i] = toint(x);
    }
    if(rec(0,k) == 0) cout<<-1<<endl;
    else{
        construct(0,k);
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