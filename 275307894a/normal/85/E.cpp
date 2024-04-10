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
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
#define db long double
#define N 5000
#define eps (1e-14)
#define mod 1000000007
#define U unsigned
using namespace std;
int n,x[N+5],y[N+5],col[N+5],l,r,mid,cnt=1,fl[N+5],flag;
I int dis(int a,int b){return abs(x[a]-x[b])+abs(y[a]-y[b]);}
I void dfs(int x,int w,int mid){
	if(!flag) return;if(col[x]){col[x]!=w&&(flag=0);return;}col[x]=w;
	for(int i=1;i<=n;i++)if(dis(x,i)>mid)dfs(i,w*-1,mid);
}
I int check(int mid){
	memset(col,0,sizeof(col));flag=1;for(int i=1;i<=n;i++) !col[i]&&(dfs(i,1,mid),0);return flag;
}
I void find(int x,int mid){
	if(fl[x]) return;fl[x]=1;for(int i=1;i<=n;i++)if(dis(x,i)>mid)find(i,mid);
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),l=max(l,x[i]),r=max(r,y[i]);r+=l+2;l=-1;
	while(l+1<r) mid=l+r>>1,(check(mid)?r:l)=mid;printf("%d\n",r);for(i=1;i<=n;i++) !fl[i]&&(find(i,r),cnt=cnt*2%mod);printf("%d\n",cnt);
}