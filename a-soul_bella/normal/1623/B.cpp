#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int> a[1005];
int vis[1005];
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second-x.first<y.second-y.first;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i].first >> a[i].second;
		sort(a+1,a+n+1,cmp);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			for(int j=a[i].first;j<=a[i].second;j++)
			{
				if(!vis[j])
				{
					vis[j]=1;
					cout << a[i].first << " " << a[i].second << " " << j << "\n";
					break;
				}
			}
		}
	//	cout << "\n";
	}
	return 0;
}