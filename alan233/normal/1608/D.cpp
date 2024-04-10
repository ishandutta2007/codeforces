#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
inline int read(){
    int x=0;char ch=getchar();
    int f=0;
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char let){
    print(x),putchar(let);
}
template<typename T1,typename T2>void ckmin(T1&x,T2 y){
    if(x>y)x=y;
}

const int mod=998244353;
const int N=100005;

inline int qpow(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
int fac[N],ifac[N];
inline void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n],mod-2);
    per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    else return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}

char tmp[5];
int dp[N][4];
int white[2],black[2];
int n;

bool flag;
int ok,qwq;

int main(){
    init(1e5);
    scanf("%d",&n);
    dp[0][0]=1;
    rep(i,1,n){
        scanf("%s",tmp);
        if(tmp[0]=='B')black[0]++;
        else if(tmp[0]=='W')white[0]++;
        if(tmp[1]=='B')black[1]++;
        else if(tmp[1]=='W')white[1]++;
        
        if(tmp[0]=='B'&&tmp[1]=='B')flag=1;
        if(tmp[0]=='W'&&tmp[1]=='W')flag=1;
        
        if(tmp[0]=='B'||tmp[1]=='W')ok|=1;
        if(tmp[1]=='B'||tmp[0]=='W')ok|=2;
        if(tmp[0]=='?'&&tmp[1]=='?')qwq++;
    }
//    printf("ok=%d,qwq=%d\n",ok,qwq);
    int ans=0;
    rep(wh,white[0],n-black[0]){
        ans=(ans+1ll*C(n-white[0]-black[0],wh-white[0])*C(n-white[1]-black[1],wh-black[1]))%mod;
//        printf("white = %d,ans=%d\n",wh,ans);
    }
    if(!flag){
        if(ok==3){
            ans=(ans+mod-qpow(2,qwq))%mod;
        }else if(ok==1||ok==2){
            ans=(ans+mod-qpow(2,qwq)+1)%mod;
//            ans=(ans+1)%mod;
        }else{
            ans=(ans+mod-qpow(2,qwq)+2)%mod;
//            ans=(ans+2)%mod;
        }
    }
    print(ans,'\n');
    return 0;
}