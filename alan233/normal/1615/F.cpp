#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
#define poly vector<int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=2005;
const int mod=1e9+7;

inline void add(int &x,int y){
    if((x+=y)>=mod)x-=mod;
}

char a[N],b[N];
int f[N][N][2],g[N][N][2],n;

void solve(){
    scanf("%d%s%s",&n,a+1,b+1);
    rep(i,0,n)rep(j,0,i)f[i][j][0]=f[i][j][1]=g[i][j][0]=g[i][j][1]=0;
    rep(i,1,n){
        if(a[i]=='1')a[i]=0;
        else if(a[i]=='0')a[i]=1;
        if(b[i]=='1')b[i]=0;
        else if(b[i]=='0')b[i]=1;
    }
    ***g=1;
    rep(i,1,n)rep(j,0,i-1)rep(k,0,1){
        rep(x,0,1)
            rep(y,0,1){
                if(x==(a[i]^1)||y==(b[i]^1))continue;
                int coef=(1ll*g[i-1][j][k]*j+f[i-1][j][k])%mod;
                int gok=x,goj=j;
                if(j&&gok==k){
                    gok^=1;
                    if(gok==y)goj--;
                }else{
                    if(gok!=y)++goj;
                }
                add(f[i][goj][gok],coef),add(g[i][goj][gok],g[i-1][j][k]);
            }
    }
    print((f[n][0][0]+f[n][0][1])%mod,'\n');
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}