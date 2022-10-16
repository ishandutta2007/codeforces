
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	vector<int> in(n+1,0);
	vector<int> out(n+1,0);
	int a,b,c;

	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b>>c;
		out[a]+=c;
		in[b]+=c;
	}

	int ans=0;
	for (int i = 1; i <= n; ++i)
	{
		if(in[i]<out[i])
		{
			ans+=out[i]-in[i];
		}
	}
	cout<<ans;
	return 0;
}