#include<bits/stdc++.h>
using namespace std;
const int N=8192;
int f[N][N];
set<int> s[N];
int n,x;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		s[x].insert(i);
	}
	for (int i=0;i<N;++i)
		s[i].insert(n+1);
	for (int i=0;i<=5001;++i)
		for (int j=0;j<N;++j)
			f[i][j]=n+1;
	f[0][0]=0;
	for (int i=0;i<=5000;++i)
		for (int j=0;j<N;++j)
			if (f[i][j]<=n)
			{
				f[i+1][j]=min(f[i+1][j],f[i][j]);
				f[i+1][j^i]=min(f[i+1][j^i],*(s[i].upper_bound(f[i][j])));
			}
	vector<int> ans;
	for (int i=0;i<N;++i)
		if (f[5001][i]<=n)
			ans.push_back(i);
	cout<<ans.size()<<endl;
	for (int x:ans)
		cout<<x<<' ';
	return 0;
}