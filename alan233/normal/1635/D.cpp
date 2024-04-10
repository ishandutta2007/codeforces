// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=200005;
const int M=30*N;
const int mod=1e9+7;

int a[N],f[N];
int n,p;

int ch[M][2],End[M],tot;
void ins(int x){
    int rt=0,pos=-1,i;
    for(i=29;i>=0;i--){
        if(x>>i&1)break;
    }
    for(;i>=0;i--){
        int &tmp=ch[rt][x>>i&1];
        if(!tmp)tmp=++tot;
        rt=tmp;
        // printf("when i=%d,rt=%d\n",i,rt);
    }
    End[rt]=1;
}
void chk(int x){
    int rt=0,pos=-1,i;
    for(i=29;i>=0;i--){
        if(x>>i&1)break;
    }
    static bool fuck[30];
    memset(fuck,0,sizeof(fuck));
    bool ok=0;
    int las=-1,len=0;
    for(int j=0;j<=i;j++){
        if(x>>j&1){
            if(las==0){
                if(len&1)ok=1;
                las=1,len=0;
            }
            las=1;
            len++;
        }else{
            if(las==1)las=0,len=0;
            las=0;
            len++;
        }
        fuck[j]=ok;
        if(las==0&&(len&1))fuck[j]=1;
    }

    bool failed=0;
    for(;i>=0;i--){
        int &tmp=ch[rt][x>>i&1];
        rt=tmp;
        if(i>0&&End[rt]){
            // printf("i=%d\n",i);
            if(!fuck[i-1]){
                failed=1;
            }
        }
    }
    // printf("x=%d,failed=%d\n",x,failed);
    if(failed)End[rt]=0;
}  

int ans;
void dfs(int u,int dep){
    if(dep>p)return;
    if(End[u]){
        // printf("u=%d,dep=%d\n",u,dep);
        // printf("f=%d\n",f[p-dep]);
        ans=(ans+f[p-dep])%mod;
    }
    if(ch[u][0])dfs(ch[u][0],dep+1);
    if(ch[u][1])dfs(ch[u][1],dep+1);
}

int main(){
    n=read(),p=read();
    f[0]=1,f[1]=1;
    rep(i,2,p){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    rep(i,1,p)f[i]=(f[i]+f[i-1])%mod;
    rep(i,1,n)a[i]=read();
    rep(i,1,n)ins(a[i]);
    rep(i,1,n)chk(a[i]);
    dfs(0,0);
    print(ans,'\n');
    return 0;
}