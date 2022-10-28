#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, k, ans=0, neg=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
			a[i]=0;
		else
			a[i]=-1;
		neg+=(a[i]==-1);
	}
	if(neg>k)
	{
		cout<<"-1";
		return 0;
	}
	int check=0, cntsum=0;
	vector<pair<int, int> > v;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			ans++;
		if(a[i]>=0)
			cntsum++;
		else
		{
			k--;
			if(cntsum>0 && check>=1)
				v.push_back({cntsum, check});
			check++;
			cntsum=0;
		}
	}
	if(cntsum>0 && check>=1)
		v.push_back({cntsum, check});
	sort(v.begin(), v.end());
	int storelast=-1;
	for(auto it:v)
	{
		if(it.second==check)
		{
			storelast=it.first;
			continue;
		}
		if(it.first<=k)
		{
			k-=it.first;
			ans-=2;
		}
	}
	if(storelast!=-1 && storelast<=k)
		ans--;
	cout<<ans;
}