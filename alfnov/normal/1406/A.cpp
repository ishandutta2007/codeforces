#include<bits/stdc++.h>
using namespace std;
int gs[105],a[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(gs,0,sizeof(gs));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],gs[a[i]]++;
		int fi=-1,si=-1;
		for(int i=0;i<=100;i++)
		{
			if(si>=0||gs[i]>=2)continue;
			if(gs[i]==1)
			{
				if(fi==-1)fi=i;
				else;
			}else
			{
				if(fi==-1)fi=i;
				if(si==-1)si=i;
			}
		}
		cout<<fi+si<<endl;
	}
	return 0;
}