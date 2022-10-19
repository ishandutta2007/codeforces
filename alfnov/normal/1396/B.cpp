#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,ss=0,mx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			ss+=a;
			mx=max(mx,a);
		}
		if(ss&1)puts("T");
		else if(mx*2>ss)puts("T");
		else puts("HL");
	}
	return 0;
}