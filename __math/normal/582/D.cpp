#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long ll;
const int  mod=1e9+7;
const ll MX=ll(mod)*mod;
inline void add(ll &x,ll y){
    x+=y;
    if(x>=MX) x-=MX;
    if(x<-MX) x+=MX;
}

inline ll sum(ll x){
    return x*(x+1)/2%mod;
}
vector<ll> Basep(string s,ll p){
    int L=s.size();
    int up=4000;
    vector<ll> ret(up,0);
    int N=0;
    rep(i,L){
        rep(j,N) ret[j]*=10;
        ret[0]+=s[i]-'0';
        int j=0;
        while(j<N-1||ret[j]>=p){
            ret[j+1]+=ret[j]/p;
            ret[j]%=p;
            j++;
        }
        N=j+1;
    }
    ret.erase(ret.begin()+N,ret.end());
    return ret;
}
ll dp[2][4000][3][2];
int main(){
    ll p;
    int e;
    string A;
    cin>>p>>e>>A;
    vector<ll> ds=Basep(A,p);
    int N=ds.size();
    ll pp=p*p%mod;
    dp[0][0][1][0]=1;
    rep(i,N){
        rep(j,N+1) rep(k,3) rep(l,2) dp[1-i%2][j][k][l]=0;
        rep(j,i+1){
            rep(c,2){
                ll d=ds[i]-c;
                ll mat[3][3][2]={};
                ll ncar=sum(p-c);
                mat[0][0][0]=sum(d+1);
                mat[0][2][0]=ncar-mat[0][0][0];
                mat[0][2][1]=sum(p-2-d);
                mat[0][0][1]=pp-ncar-mat[0][2][1];

                mat[1][0][0]=sum(d);
                mat[1][1][0]=d+1;
                mat[1][2][0]=ncar-mat[1][0][0]-mat[1][1][0];
                mat[1][1][1]=p-1-d;
                mat[1][2][1]=sum(p-2-d);
                mat[1][0][1]=pp-ncar-mat[1][1][1]-mat[1][2][1];

                mat[2][0][0]=sum(d);
                mat[2][2][0]=ncar-mat[2][0][0];
                mat[2][2][1]=sum(p-1-d);
                mat[2][0][1]=pp-ncar-mat[2][2][1];
                rep(x,3){
                    if(dp[i%2][j][x][c]==0) continue;
                    rep(y,3) rep(z,2){
                        add(dp[1-i%2][j+z][y][z],dp[i%2][j][x][c]%mod*mat[x][y][z]);
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=e;i<=N;i++) add(ans,dp[N%2][i][0][0]+dp[N%2][i][1][0]);
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
}