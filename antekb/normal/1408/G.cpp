#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=3005, INF=1e9+5, mod=998244353;
int siz[N], dp[N][N], r[N], ile[N];
int wsk;
int find(int x){
    if(r[x]==x)return x;
    return r[x]=find(r[x]);
}
void Union(int a ,int b){
    a=find(a), b=find(b);
    if(a==b){
        if(++ile[a]==siz[a]*(siz[a]-1)/2){
            dp[a][1]=1;
        }
    }
    else{
        r[wsk]=wsk;
        r[a]=wsk;
        r[b]=wsk;
        siz[wsk]=siz[a]+siz[b];
        for(int i=1; i<=siz[a]; i++){
            for(int j=1; j<=siz[b]; j++){
                dp[wsk][i+j]=(dp[wsk][i+j]+dp[a][i]*1ll*dp[b][j])%mod;
            }
        }
        ile[wsk]=ile[a]+ile[b]+1;
        if(siz[a]==1 && 1==siz[b])dp[wsk][1]=1;
        wsk++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<int, pii> > tab;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++){
        int x;
        cin>>x;
        if(i<j)tab.pb(mp(x, mp(i, j)));
    }
    sort(all(tab));
    for(int i=0; i<n; i++){
        r[i]=i;
        dp[i][1]=1;
        siz[i]=1;
    }
    wsk=n;
    for(auto i:tab){
        Union(i.nd.st, i.nd.nd);
    }
    wsk--;
    for(int i=1; i<=n; i++)cout<<dp[wsk][i]<<" ";
}