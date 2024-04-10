#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=55;
const double eps=1e-9;

int n, w, m;
int cnt[N];
vector<pair<int, double> > ans[N];
double have[N], reqd[N];

int32_t main()
{
	IOS;
	cin>>n>>w>>m;
	for(int i=1;i<=n;i++)
		have[i]=w;
	double total=n*w;
	total/=m;
	for(int i=1;i<=m;i++)
	{
		reqd[i]=total;
		for(int j=1;j<=n;j++)
		{
			if(reqd[i]<eps)
				break;
			if(have[j]>eps)
			{
				double take=min(reqd[i], have[j]);
				have[j]-=take;
				reqd[i]-=take;
				cnt[j]++;
				ans[i].push_back({j, take});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>2)
		{
			cout<<"NO";
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(reqd[i]>eps)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	cout<<fixed<<setprecision(9);
	for(int i=1;i<=m;i++)
	{
		for(auto &it:ans[i])
			cout<<it.first<<" "<<it.second<<" ";
		cout<<endl;
	}
	return 0;
}