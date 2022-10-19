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

const int N=2e5+5, INF=1e9+5, mod=1e6+3;
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
int odw(int a){return pot(a, mod-2);}
int main(){
    int k=11;
    vector<vi> V(k+1);
    for(int i=1; i<=k; i++){
        cout<<"? "<<i<<endl;
        V[i].resize(k+1);
        cin>>V[i][k];
        //V[i][k]=i*i+1000002;
        V[i][0]=1;
        for(int j=1; j<k; j++){
            V[i][j]=(V[i][j-1]*i)%mod;
        }
    }
    vi V2(k), V3(k);
    //int b=0;
    for(int i=1; i<=k; i++){
        //if(b==k)break;
        /*for(int j=1; j<=k; j++){
            for(int l=0; l<=k; l++){
                cout<<V[j][l]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";*/
        //if(V[i][i-1]==0){cout<<i<<"a";continue;}
        for(int j=1; j<=k; j++){
            if(j==i)continue;
            int c=(V[j][i-1]*1ll*odw(V[i][i-1]))%mod;
            for(int l=i-1; l<=k; l++){
                V[j][l]-=(c*1ll*V[i][l])%mod;
                V[j][l]+=mod;
                V[j][l]%=mod;
            }
        }
    }
    for(int i=1; i<=k; i++){
        V2[i-1]=(V[i][k]*1ll*odw(V[i][i-1]))%mod;
        //cout<<V2[i-1]<<" ";
    }
    for(int i=0; i<mod; i++){
        int t=1;
        ll ans=0;
        //cout<<"a";
        for(int j=0; j<k; j++){
            ans+=(V2[j]*1ll*t)%mod;
            //cout<<ans<<" ";
            t=(t*1ll*i)%mod;
        }
        //cout<<"b";
        ans=ans%mod;
        if(!ans){
            cout<<"! "<<i<<endl;
            return 0;
        }
    }
    cout<<"! "<<-1<<endl;
}