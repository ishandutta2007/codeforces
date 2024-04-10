#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5;
int n,m,a[N],st[N][21];
LL b[N],c[N],p[N],q[N],ans[N];
inline int mnn(int x,int y){return a[x]<a[y]?x:y;}
inline int query(int l,int r)
{
	int k=log2(r-l+1);
	return mnn(st[l][k],st[r-(1<<k)+1][k]);
}
void solve(int l,int r)
{
	if(l>r)return;
	int pos=query(l,r),x=min(pos-l+1,r-pos+1),y=max(pos-l+1,r-pos+1),z=r-l+1;
	b[1]+=a[pos];b[x+1]-=a[pos];
	c[x+1]+=(LL)a[pos]*x,c[y+1]-=(LL)a[pos]*x;
	p[y+1]+=a[pos];p[z+1]-=a[pos];
	q[y+1]+=(LL)a[pos]*(z+1);q[z+1]-=(LL)a[pos]*(z+1);
	solve(l,pos-1);solve(pos+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),st[i][0]=i;
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)if(i+(1<<j)-1<=n)st[i][j]=mnn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	solve(1,n);
	for(int i=1;i<=n;i++)b[i]+=b[i-1],c[i]+=c[i-1],p[i]+=p[i-1],q[i]+=q[i-1];
	for(int i=1;i<=n;i++)ans[i]=b[i]*i+c[i]-p[i]*i+q[i];
	scanf("%d",&m);
	while(m--){int x;scanf("%d",&x);printf("%.10lf\n",(double)ans[x]/(n-x+1));}
	return 0;
}