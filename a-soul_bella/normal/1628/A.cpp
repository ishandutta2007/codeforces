#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200005],hzh[200005],a[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=0;i<=n+1;i++) cnt[i]=0;
		int mex=0;
		for(int i=n;i>=1;i--)
		{
			++cnt[a[i]];
			while(cnt[mex]) ++mex;
			hzh[i]=mex;
		}
		for(int i=0;i<=n+1;i++) cnt[i]=0;
		mex=0;
		int nxt=hzh[1];
		vector <int> v;
		for(int i=1;i<=n;i++)
		{
			++cnt[a[i]];
			while(cnt[mex]) ++mex;
			if(mex==nxt)
			{
				v.push_back(mex);
				for(int j=0;j<=mex+1;j++) cnt[j]=0;
				mex=0;
				nxt=hzh[i+1];
			}
		}
		cout << v.size() << "\n";
		for(auto t:v)
			cout << t << " ";
		cout << "\n";
	}
	return 0;
}