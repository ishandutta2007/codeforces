#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n, m, ans=0;
int a[N], b[N], prefgcd[N];
set<int> badprimes;
map<int, int> store;

int diff(int k)
{
	if(store.find(k)!=store.end())
		return store[k];
	int storek=k;
	int ct=0;
	for(int i=2;i*i<=k;i++)
	{
		while(k%i==0)
		{
			if(badprimes.find(i)==badprimes.end())
				ct++;
			else
				ct--;
			k/=i;
		}
	}
	if(k>1 && badprimes.find(k)==badprimes.end())
		ct++;
	else if(k>1)
		ct--;
	return store[storek]=ct;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		prefgcd[i]=__gcd(prefgcd[i-1], a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		badprimes.insert(b[i]);
	}
	int div=1;
	for(int i=n;i>=1;i--)
	{
		ans+=diff(a[i]);
		int cur=prefgcd[i]/div;
		if(diff(cur)<0)
		{
			ans+=abs(diff(cur))*i;
			div*=cur;
		}
	}
	cout<<ans;
	return 0;
}