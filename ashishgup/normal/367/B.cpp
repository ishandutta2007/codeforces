#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, p;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	vector<int> v;
	for(int i=1;i<=min(n, p);i++)
	{
		int cur=i;
		if(i+(m-1)*p>n)
			continue;
		map<int, int> reqd;
		for(int j=1;j<=m;j++)
			reqd[b[j]]++;
		int tot=reqd.size();
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			if(cur>n)
				break;
			if(reqd.find(a[cur])!=reqd.end())
			{
				reqd[a[cur]]--;
				if(reqd[a[cur]]==0)
					cnt++;
			}
			cur+=p;
		}
		if(cnt==tot)
			v.push_back(i);
		while(cur<=n)
		{
			int idx=(cur-m*p);
			if(reqd.find(a[idx])!=reqd.end())
			{
				reqd[a[idx]]++;
				if(reqd[a[idx]]==1)
					cnt--;
			}
			if(reqd.find(a[cur])!=reqd.end())
			{
				reqd[a[cur]]--;
				if(reqd[a[cur]]==0)
					cnt++;
			}
			if(cnt==tot)
				v.push_back(idx+p);
			cur+=p;
		}
	}
	sort(v.begin(), v.end());
	cout<<v.size()<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}