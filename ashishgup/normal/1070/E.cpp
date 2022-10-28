#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, t;
int a[N];
vector<int> v;

int calc(int k)
{
	int cnt=0, tim=0, grp=0, prevtim=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k)
			continue;
		if(tim+a[i]>t)
			return cnt;
		tim+=a[i];
		cnt++;
		grp++;
		prevtim+=a[i];
		if(grp>=m)
		{
			tim+=prevtim;
			grp=0;
			prevtim=0;
		}
	}
	return cnt;
}


int ternary_search(int lo, int hi)
{
	while(hi-lo>2)
	{
		int m1=(lo*2+hi)/3;
		int m2=(lo+2*hi)/3;
		if(calc(v[m1])>=calc(v[m2]))
			hi=m2;
		else
			lo=m1;
	}
	int ans=calc(v[lo]), store=v[lo];
	for(int i=max(0LL, lo-10);i<=min((int)v.size()-1, hi+10);i++)
	{
		if(calc(v[i])>ans)
		{
			ans=calc(v[i]);
			store=v[i];
		}
	}
	return store;
}

int32_t main()
{
	IOS;
	int tt;
	cin>>tt;
	while(tt--)
	{
		v.clear();
		cin>>n>>m>>t;
		set<int> s;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		for(auto &it:s)
			v.push_back(it);
		int ans=ternary_search(0, v.size()-1);
		ans=min(ans, t);
		cout<<calc(ans)<<" "<<ans<<endl;
	}
	return 0;
}