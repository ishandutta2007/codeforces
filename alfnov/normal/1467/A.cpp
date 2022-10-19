#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,ss=9;
		cin>>n;
		if(n==1)
		{
			printf("9");
		}else printf("98");
		for(int i=3;i<=n;i++)printf("%d",ss),ss=(ss+1)%10;
		puts("");
	}
	return 0;
}