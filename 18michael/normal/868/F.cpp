#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k,L=1,R=0;LL res=0;
int a[100002],cnt[100002]={};
LL f[22][100002];
inline LL calc(int l,int r)
{
	while(L>l)--L,res+=cnt[a[L]],++cnt[a[L]];
	while(R<r)++R,res+=cnt[a[R]],++cnt[a[R]];
	while(L<l)--cnt[a[L]],res-=cnt[a[L]],++L;
	while(R>r)--cnt[a[R]],res-=cnt[a[R]],--R;
	return res;
}
inline void solve(int x,int l,int r,int l1,int r1)
{
	if(l>r)return ;int mid=((l+r)>>1),num;f[x][mid]=inf;
	for(int i=l1;i<=r1 && i<=mid;++i)if(f[x-1][i]+calc(i+1,mid)<f[x][mid])f[x][mid]=f[x-1][num=i]+calc(i+1,mid);
	solve(x,l,mid-1,l1,num),solve(x,mid+1,r,num,r1);
}
int main()
{
	scanf("%d%d",&n,&k),f[0][0]=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),f[0][i]=inf;
	for(int i=1;i<=k;++i)calc(1,0),solve(i,0,n,0,n);
	return 0&printf("%lld",f[k][n]);
}