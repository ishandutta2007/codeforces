#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int r=(n-1)/4+1;
		for(int i=1;i<=n-r;i++)printf("9");
		for(int i=1;i<=r;i++)printf("8");
		puts("");
	}
	return 0;
}