#include<bits/stdc++.h>
#define N 20
#define Mx 1048576
using namespace std;
int n,mx,Test_num;
char A[100002],B[100002];
int one[Mx],rt[Mx];
bool f[Mx];
bool ok[Mx][N];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void solve()
{
	scanf("%d%s%s",&n,A+1,B+1),memset(ok,0,sizeof(ok)),memset(f,0,sizeof(f)),f[0]=1,mx=0;
	for(int i=0;i<N;++i)rt[i]=i;
	for(int i=1;i<=n;++i)ok[1<<(A[i]-='a')][B[i]-='a']=1,getroot(A[i]),getroot(B[i]),rt[rt[A[i]]]=rt[B[i]];
	for(int i=1;i<Mx;++i)
	{
		for(int j=0;j<N;++j)ok[i][j]=ok[i^lowbit(i)][j]|ok[lowbit(i)][j];
		for(int j=0;j<N;++j)if((i>>j)&1 && !ok[i^(1<<j)][j])f[i]|=f[i^(1<<j)];
		if(f[i])mx=max(mx,one[i]);
	}
	for(int i=0;i<N;++i)if((getroot(i),rt[i])==i)++mx;
	printf("%d\n",2*N-mx);
}
int main()
{
	for(int i=1;i<Mx;++i)one[i]=one[i>>1]+(i&1);
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}