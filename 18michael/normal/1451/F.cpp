#include<bits/stdc++.h>
using namespace std;
int n,m,Test_num;
int a[202];
inline void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+m;++i)a[i]=0;
	for(int i=1,x;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&x),a[i+j]^=x;
	for(int i=1;i<=n+m;++i)if(a[i])return (void)(puts("Ashish"));
	puts("Jeel");
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}