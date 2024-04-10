#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define M 100000
#define eps (1e-5)
#define mod (1<<31)
#define U unsigned int
using namespace std;
int n,m,fa[N+5],siz[N+5],x,y,cnt;ll Ans=1,p;
I ll mpow(ll x,int y){ll Ans=1;while(y) (y&1)&&(Ans=Ans*x%p),y>>=1,x=x*x%p;return Ans;}
I int Getfa(int x){return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d%lld",&n,&m,&p);for(i=1;i<=n;i++) fa[i]=i;while(m--)scanf("%d%d",&x,&y),fa[Getfa(x)]=Getfa(y);
	for(i=1;i<=n;i++) siz[Getfa(i)]++;for(i=1;i<=n;i++) siz[i]&&(cnt++,Ans=Ans*siz[i]%p);printf("%lld\n",cnt==1?1%p:Ans*mpow(n,cnt-2)%p);
}