#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)printf("PRL");
		putchar('R');
	}
	scanf("%d",&x);
	for(int i=1;i<=x;i++)printf("PLR");puts("");
	return 0;
}