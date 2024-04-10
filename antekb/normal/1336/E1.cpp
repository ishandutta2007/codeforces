//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, INF=1e9+5, mod=998244353;
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
ll dp[40][1<<15];
int main(){
    int n, m;
    cin>>n>>m;
    vector<ll> V(n);
    for(auto &i:V)cin>>i;
    vector<ll> B(m);
    vector<ll> B2;
    int b=0;
    for(int i=0; i<n; i++){
        //cout<<V[i]<<"\n";
        for(int j=0; j<m; j++){
            if(!(V[i]&(1ll<<j)))continue;
            if(B[j]==0){
                //cout<<bitset<5>(V[i])<<"\n";
                for(int k=i; k<n; k++){
                    //cout<<bitset<5>(V[k])<<" ";
                    if((!!((1ll<<j)&V[k]))^(!!((1ll<<b)&V[k]))){
                        V[k]^=(1ll<<j);
                        V[k]^=(1ll<<b);
                    }
                    //cout<<bitset<5>(V[k])<<"\n";
                }
                for(int k=0; k<b; k++){
                    //cout<<bitset<5>(B[k])<<" ";
                    if((!!((1ll<<j)&B[k]))^(!!((1ll<<b)&B[k]))){
                        B[k]^=(1ll<<j);
                        B[k]^=(1ll<<b);
                    }
                    //cout<<bitset<5>(B[k])<<"\n";
                }
                for(int k=0; k<b; k++){
                    if(B[k]&(1ll<<b))B[k]^=V[i];
                }
                B[b]=V[i];
                b++;
                //cout<<B[j]<<"a\n";
                break;
            }
            else{
                //cout<<bitset<5>(V[i])<<" ";
                V[i]^=B[j];
            }
        }
    }
    if(b<=20){
        vector<ll> ans(m+1);
        for(int i=0; i<(1<<b); i++){
            ll k=0;
            for(int j=0; j<b; j++){
                if(i&(1ll<<j))k^=B[j];
            }
            //cout<<k<<" ";
            ans[__builtin_popcountll(k)]++;
        }
        //cout<<"\n";
        for(int i=0; i<=m; i++){
            cout<<(ans[i]*1ll*pot(2, n-b))%mod<<" ";
        }
        return 0;
    }
    int t=(1<<(m-b));
    dp[0][0]=1;
    for(int i=0; i<b; i++){
        //cout<<bitset<4>(B[i])<<"\n";
        int l=B[i]>>b;
        for(int k=i; k>=0; k--){
            for(int j=0; j<t; j++){
                dp[k+1][j^l]+=dp[k][j];
            }
        }
    }
    vector<ll> ans(m+1);
    for(int i=0; i<t; i++){
        for(int k=0; k<=m; k++){
            ans[k+__builtin_popcountll(i)]+=dp[k][i]%mod;
        }
    }
    for(auto i:ans){
        cout<<((i%mod)*1ll*pot(2, n-b))%mod<<" ";
    }
}