#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,mnc[1001][1001],q[1001],l,r;
ll cost[1001][1001],mn[1001][1001],h[1001][1001];
bool g[1001][1001];
struct node{
	int x,y;
	ll val;
	friend bool operator <(const node &lhv,const node &rhv){
		if(lhv.val!=rhv.val)return lhv.val<rhv.val;
		if(lhv.x!=rhv.x)return lhv.x<rhv.x;
		return lhv.y<rhv.y;
	}
}tmp;
vector<node>v,pq;
inline void prepare(){
	for(register int i=1;i<=n;i++){
		l=1,r=0;
		for(register int j=1;j<=m;j++){
			while(l<=r&&q[l]<=j-b)l++;
			while(l<=r&&h[i][q[r]]>=h[i][j])r--;
			q[++r]=j;
			if(j>=b)mnc[i][j]=h[i][q[l]];
		}
	}
	for(register int i=1;i<=m;i++){
		l=1,r=0;
		for(register int j=1;j<=n;j++){
			while(l<=r&&q[l]<=j-a)l++;
			while(l<=r&&mnc[q[r]][i]>=mnc[j][i])r--;
			q[++r]=j;
			if(j>=a)mn[j][i]=mnc[q[l]][i];
		}
	}
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++){
			cost[i][j]=cost[i][j-1]+h[i][j];
			if(j>b)cost[i][j]-=h[i][j-b];
		}
	}
	for(register int i=1;i<=m;i++){
		for(register int j=1;j<=n;j++){
			h[j][i]=h[j-1][i]+cost[j][i];
			if(j>a)h[j][i]-=cost[j-a][i];
		}
	}
	for(register int i=a;i<=n;i++)for(register int j=b;j<=m;j++)tmp.x=i,tmp.y=j,tmp.val=h[i][j]-mn[i][j]*a*b,pq.push_back(tmp);
	sort(pq.begin(),pq.end());
}
inline int read(){
	register int x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
char c[20];
inline void write(ll x){
	if(!x)putchar('0');
	register int cnt=0;
	while(x)c[cnt++]=x%10+'0',x/=10;
	while(cnt--)putchar(c[cnt]);
}
inline void fil(int x,int y){
	for(int i=x-a+1;i<=min(x+a-1,n);i++)for(int j=y-b+1;j<=min(y+b-1,m);j++)g[i][j]=true;
}
int main(){
	n=read(),m=read(),a=read(),b=read();
	for(register int i=1;i<=n;i++)for(register int j=1;j<=m;j++)h[i][j]=read();
	prepare();
	for(register int i=0;i<pq.size();i++)if(!g[pq[i].x][pq[i].y])fil(pq[i].x,pq[i].y),v.push_back(pq[i]);
	write(v.size()),putchar('\n');
	for(register int i=0;i<v.size();i++)write(v[i].x-a+1),putchar(' '),write(v[i].y-b+1),putchar(' '),write(v[i].val),putchar('\n');
	return 0;
}
/*
10 10 5 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/