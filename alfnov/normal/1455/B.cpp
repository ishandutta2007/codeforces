#include<bits/stdc++.h>
using namespace std;
int f[10005];
int main()
{
	for(int i=1;i<=10000;i++)f[i]=i*(i+1)/2;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int pp=lower_bound(f+1,f+10001,n)-f;
		if(f[pp]==n)printf("%d\n",pp);
		else
		{
			n+=2;
			int pp2=lower_bound(f+1,f+10001,n)-f;
			printf("%d\n",pp2);
		}
	}
	return 0;
}