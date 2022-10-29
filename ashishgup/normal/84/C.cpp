#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
int x[N], r[N], ans[N], cnt=0;
map<int, int> getR, idx;
vector<int> v;

void check(int i, int x, int x1, int y1)
{
	int r=getR[x];
	int lhs=(x-x1)*(x-x1) + y1*y1;
	int rhs=r*r;
	if(lhs<=rhs)
	{
		if(!ans[idx[x]])
		{
			cnt++;
			ans[idx[x]]=i;
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>r[i];
		getR[x[i]]=r[i];
		v.push_back(x[i]);
		idx[x[i]]=i;
	}
	cin>>m;
	sort(v.begin(), v.end());
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		auto it=lower_bound(v.begin(), v.end(), x);
		if(it!=v.end())
			check(i, *it, x, y);
		if(it!=v.begin())
		{
			it--;
			check(i, *it, x, y);
			it++;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		if(!ans[i])
			ans[i]=-1;
		cout<<ans[i]<<" ";
	}
	return 0;
}