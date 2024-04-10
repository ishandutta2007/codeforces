#include <iostream>
#include <cstdio>
using namespace std;
const int N=200000;

int a[N+100],b[N+100],n,m,k;
int main()
{
	int i,j,l,r;
	cin>>n>>k>>m;
	for(i=0;i<n;++i)
	{
		scanf("%d%d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	j=0;
	for(i=0;i<=N+1;++i)
	{
		j+=a[i];
		b[i]=b[i-1]+(j>=k);
	}
	for(i=0;i<m;++i)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",b[r]-b[l-1]);
	}
//	system("pause");
	return 0;
}