#include <bits/stdc++.h>
using namespace std;
 
#define int long long

const int N=505;
const int MOD=998244353;

int n;
int a[N];
vector<int> v;
map<int, int> cnt;

pair<int, int> check(int x)
{
	int k=sqrt(x);
	int check3=0;
	int store=-5;
	for(int d=k-1;d<=k+1;d++)
	{
		if(d*d==x)
		{
			store=d;
			check3=1;
		}
	}
	if(store<0)
		return {4, 0};
	k=sqrt(store);
	for(int d=k-1;d<=k+1;d++)
	{
		if(d*d==store)
		{
			return {5, d};
		}
	}
	if(check3)
		return {3, store};
	return {4, 0};
}

int checker(int val, int k)
{
	int store=k;
	for(int j=1;j<=2;j++)
	{
		store*=k;
		if(store>=val)
			return 1;
	}
	return 0;
}	

int bin_search(int val, int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(checker(val, mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pair<int, int> cur=check(a[i]);
		if(cur.first!=4)
			cnt[cur.second]+=(cur.first-1);
		else
		{
			int temp=bin_search(a[i], 1, 1259921);
			if(temp*temp*temp==a[i])
				cnt[temp]+=3;
			else
				v.push_back(a[i]);
		}
	}
	while(true)
	{
		int changes=0;
		multiset<int> del;
		for(auto &it:v)
		{
			for(auto &prime:cnt)
			{
				if(__gcd(prime.first, it)>1)
				{
					int q=__gcd(prime.first, it);
					cnt[q]++;
					cnt[it/q]++;
					del.insert(it);
					changes=1;
					break;
				}
			}
		}
		vector<int> newv;
		for(auto &it:v)
		{
			if(del.find(it)==del.end())
				newv.push_back(it);
			else
				del.erase(del.find(it));
		}
		v=newv;
		if(!v.size())
			break;
		del.clear();
		int sz=v.size();
		vector<int> vis(sz, 0);
		for(int i=0;i<sz;i++)
		{
			for(int j=i+1;j<sz;j++)
			{
				if(v[i]==v[j])
					continue;
				int cur=__gcd(v[i], v[j]);
				if(cur>1)
				{
					int q=cur;
					int p=v[i]/q;
					int r=v[j]/q;
					if(!vis[i])
					{
						vis[i]=1;
						del.insert(v[i]);
						cnt[p]++;
						cnt[q]++;
						changes=1;
					}
					if(!vis[j])
					{
						vis[j]=1;
						del.insert(v[j]);
						cnt[q]++;
						cnt[r]++;
						changes=1;
					}
				}
			}
		}
		newv.clear();
		for(auto &it:v)
		{
			if(del.find(it)==del.end())
				newv.push_back(it);
			else
				del.erase(del.find(it));
		}
		v=newv;
		if(!changes)
			break;
	}
	int ans=1;
	for(auto &it:cnt)
	{
		ans*=(it.second+1);
		ans%=MOD;
	}
	map<int, int> m;
	for(auto &it:v)
		m[it]++;
	for(auto &it:m)
	{
		int fac=(it.second+1)*(it.second+1);
		fac%=MOD;
		ans*=fac;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}