#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
#define For(i,a,b) for(register int i=(int)(a),i_E=(int)(b);i<=i_E;++i)
#define Fod(i,a,b) for(register int i=(int)(a),i_E=(int)(b);i>=i_E;--i)
#define cross(i,a) for(register int i=hd[(a)];i;i=pr[i])
using namespace std;
inline LL Max(LL a,LL b){return a>b?a:b;}
inline LL Min(LL a,LL b){return a<b?a:b;}
inline LL Abs(LL a){return a>=0?a:-a;}
#define IN_MAX 1000000
inline char GetChar(){
    static char buf[IN_MAX],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,IN_MAX,stdin),p1==p2)?EOF:*p1++;
}
#define CH ch=getchar()
inline LL read(){
    LL x=0;int f=1,ch;
    for(CH;!isdigit(ch)&&ch!='-'&&ch!=EOF;CH);
    if(ch=='-') f=-1,CH;
    for(;isdigit(ch);CH) x=(x<<3)+(x<<1)+ch-48;
    return x*f;
}
inline void write(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x<10) putchar(x+48);
    else write(x/10),putchar(x%10+48);
}
#define N 100005
int n,m,h[50];
LL a[N],pre[N],suf,ans;
struct node{
    node *son[2];
}*root;
inline node* build(){
    node *k=new(node);
    k->son[0]=k->son[1]=NULL;
    return k;
}
inline void change(LL x){
    int n=40;
    memset(h,0,sizeof h);
    while(x) h[n--]=x&1,x>>=1;
}
inline void ins(LL x){
    change(x);
    node *r=root;
    For(i,1,40){
        int id=h[i];
        if(!r->son[id]) r->son[id]=build();
        r=r->son[id];
    }
}
inline LL find(LL x){
    change(x);
    node *r=root;
    LL s=0;
    For(i,1,40){
        int id=h[i];
        if(r->son[!id]) id=!id;
        r=r->son[id];
        s=(s<<1)+id;
    }
    return s;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("e.in","r",stdin);
    freopen("e.out","w",stdout);
#endif
    root=build();
    n=read();
    For(i,1,n) a[i]=read(),pre[i]=pre[i-1]^a[i];
    suf=0,ins(0);
    Fod(i,n,0) ans=Max(ans,find(pre[i])^pre[i]),suf^=a[i],ins(suf);
    write(ans);
}