#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define ls ch[x][0]
#define rs ch[x][1]
inline int rd() 
{
int x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
if(c=='-')w=-1,c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*w;
}
const int N=200005;
int n,cc,tt,p1[N],p2[N],rt[N],dl[N],dep[N],cnt[N],dfn[2*N],lg[2*N],st[20][2*N];ll ans;char s[N];vi g1[N],g2[N];
struct SAM
{
int cc,lst,lk[N],mx[N],ch[N][26];
inline void init(){cc=lst=1;mx[0]=-1;}
inline int extend(int c)
{
int p=lst,np=lst=++cc;mx[np]=mx[p]+1;
for(;!ch[p][c];p=lk[p])ch[p][c]=np;
if(!p)lk[np]=1;
else
{
int q=ch[p][c];
if(mx[p]+1==mx[q])lk[np]=q;
else
{
int nq=++cc;lk[nq]=lk[q];
memcpy(ch[nq],ch[q],sizeof(ch[q]));
mx[nq]=mx[p]+1;lk[q]=lk[np]=nq;
for(;ch[p][c]==q;p=lk[p])ch[p][c]=nq;
}
}
return np;
}
}T1,T2;
void dfs1(int x,int p)
{
dfn[++tt]=x;dl[x]=tt;dep[x]=dep[p]+1;cnt[x]=T2.mx[x]+1;
for(int y:g2[x]){dfs1(y,x);dfn[++tt]=x;}
}
inline int gtmn(int a,int b){return dep[a]<dep[b]?a:b;}
inline int rmq(int l,int r)
{
l=dl[l];r=dl[r];if(l>r)swap(l,r);int t=lg[r-l+1];
return gtmn(st[t][l],st[t][r-(1<<t)+1]);
}
struct tr{int l,r,lp,rp;ll w;}T[N*20];
inline void up(int x)
{
int l=T[x].l,r=T[x].r;T[x].lp=l?T[l].lp:T[r].lp;T[x].rp=r?T[r].rp:T[l].rp;
T[x].w=T[l].w+T[r].w;if(l&&r)T[x].w-=cnt[rmq(T[l].rp,T[r].lp)];
}
void ins(int&x,int l,int r,int p)
{
x=!x?++cc:x;if(l==r){T[x].lp=T[x].rp=dfn[p];T[x].w=cnt[dfn[p]];return;}
int m=l+r>>1;p<=m?ins(T[x].l,l,m,p):ins(T[x].r,m+1,r,p);up(x);
}
int merge(int x,int y)
{
if(!x||!y)return x|y;
T[x].l=merge(T[x].l,T[y].l);
T[x].r=merge(T[x].r,T[y].r);
up(x);return x;
}
void dfs2(int x)
{
for(int y:g1[x]){dfs2(y);rt[x]=merge(rt[x],rt[y]);}
ans+=T[rt[x]].w*(T1.mx[x]-T1.mx[T1.lk[x]]);
}
int main()
{
scanf("%s",s+1);n=strlen(s+1);T1.init();T2.init();
p1[0]=1;rep(i,1,n)p1[i]=T1.extend(s[i]-'a');
p2[n+1]=1;per(i,n,1)p2[i]=T2.extend(s[i]-'a');
rep(i,2,T1.cc)g1[T1.lk[i]].pb(i);
rep(i,2,T2.cc)g2[T2.lk[i]].pb(i);
rep(i,2,T1.cc)ans+=T1.mx[i]-T1.mx[T1.lk[i]];
dfs1(1,0);
rep(i,2,tt)lg[i]=lg[i>>1]+1;
rep(i,1,tt)st[0][i]=dfn[i];
rep(j,1,19)rep(i,1,tt-(1<<j)+1)st[j][i]=gtmn(st[j-1][i],st[j-1][i+(1<<j-1)]);
rep(i,1,n)ins(rt[p1[i-1]],1,tt,dl[p2[i+1]]);
dfs2(1);printf("%lld\n",ans+1);return 0;
}