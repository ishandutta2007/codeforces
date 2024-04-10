#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1090005],vis[1000005],nxt[1000005];
vector<int> s[1000005];
bool cmp(int x,int y)
{
	return vis[x]<vis[y];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k=0;
		cin >> n;
		for(int i=0;i<=n+1;i++) nxt[i]=0,s[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			s[a[i]].push_back(i);
			if(a[i]>i) k=i;
			nxt[a[i]]=i;
		}
		cout << k << "\n";
		for(int i=0;i<=n+1;i++) vis[i]=0;
		for(int i=1;i<=n;i++) vis[a[i]]=1;
		for(int i=0;i<=n+1;i++) sort(s[i].begin(),s[i].end(),cmp);
		if(nxt[0])
		{
			int nw=0;
			while(nw<=n)
			{
				int lst=0;
				for(auto t:s[nw])
				{
					cout << t << " ";
					lst=t;
				}
				nw=lst;
				if(!nw) break;
			}
			cout << "\n";
		}
		else
		{
			int nw=n+1;
			while(1)
			{
				int lst=0;
				for(auto t:s[nw])
				{
					cout << t << " ";
					lst=t;
				}
				nw=lst;
				if(!nw||nw==n+1) break;
			}
			cout << "\n";
		}
	}
	return 0;
}