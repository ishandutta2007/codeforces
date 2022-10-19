#include<bits/stdc++.h>
using namespace std;
const int A[]={2,13,193,1009,10007,786433,5767169,23068673,104857601};
int n,a,b,c;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		int p=A[a-c];
		int q=A[b-c];
		if (p==q)
			--p;
		for (int j=1;j<c;++j)
		{
			p*=10;
			q*=10;
		}
		printf("%d %d\n",p,q);
	}
	return 0;
}