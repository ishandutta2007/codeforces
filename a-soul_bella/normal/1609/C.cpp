#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],pd[1000005];
vector <int> v[200005];
inline int cal(vector <int> v)
{
	int rtn=0;
	for(int i=0;i<v.size();i++)
	{
		if(!pd[v[i]])
		{
			int l=1,r=1;
			for(int j=i-1;j>=0;j--)
			{
				if(v[j]==1) ++l;
				else break;
			}
			for(int j=i+1;j<v.size();j++)
			{
				if(v[j]==1) ++r;
				else break;
			}
			rtn+=l*r-1;
		}
	}
	return rtn;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pd[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!pd[i])
		{
			for(int j=i+i;j<=1000000;j+=i)
				pd[j]=1;
		}
	}
	int T;
	cin >> T;
	while(T--)
	{
		int n,e;
		cin >> n >> e;
		for(int i=0;i<e;i++) v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			v[i%e].push_back(x);
		}
		int ans=0;
		for(int i=0;i<e;i++) ans+=cal(v[i]);
		cout << ans << "\n";
	}
	return 0;
}