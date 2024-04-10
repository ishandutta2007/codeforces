#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		set<int>s;
		for(int i=1;i<=n;i++)
		{
			int tt=s.size();
			s.insert(a[i]);
			if(tt==s.size())s.insert(a[i]+1);
		}
		cout<<s.size()<<endl;
	}
	return 0;
}