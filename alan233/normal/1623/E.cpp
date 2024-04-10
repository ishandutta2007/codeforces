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

const int N=200005;
const int inf=1e9;

char s[N];
int ls[N],rs[N];
int a[N],pat[N],p[N],ans[N],c;
int n,k;

void dfs(int u){
    if(!u)return;
    dfs(ls[u]);
    ++c,pat[c]=s[u],p[u]=c;
    dfs(rs[u]);   
}

void dfs0(int u){
    if(!u)return;
    dfs0(ls[u]);
    if(a[u])printf("%c%c",s[u],s[u]);
    else printf("%c",s[u]);
    dfs0(rs[u]);
}

int g(int u,int d){
    if(ls[u]&&g(ls[u],d+1))a[u]=1;
    if(rs[u]){
        if(a[u]||(ans[p[u]]&&k>=d)){
            if(!a[u])a[u]=1,k-=d;
            if(g(rs[u],1))a[u]=1;
        }else{
            if(g(rs[u],inf))a[u]=1;
        }
    }else{
        if(a[u]||!(ans[p[u]]&&k>=d));
        else a[u]=1,k-=d;
    }
    return a[u];
}

int main(){
    scanf("%d%d%s",&n,&k,s+1);
    rep(i,1,n)ls[i]=read(),rs[i]=read();
    dfs(1);
    rep(i,1,c)pat[i]-='a';
    per(i,n-1,0)ans[i]=pat[i]!=pat[i+1]?(pat[i]<pat[i+1]):ans[i+1];
    g(1,1);
    dfs0(1);
    return 0;
}