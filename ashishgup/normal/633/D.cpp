#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int a[N];
map<int, int> m;

int func(int a, int b)
{
	if(m.find(a+b)==m.end()||m[a+b]==0)
		return 0;
	m[a+b]--;
	int ans=1 + func(b, a+b);
	m[a+b]++;
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	int ans=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i)
				continue;
			int p=a[i];
			int q=a[j];
			if(p==0 && q==0)
			{
				ans=max(ans, m[0]);
				continue;
			}
			m[p]--, m[q]--;
			ans=max(ans, 2 + func(p, q));
			m[p]++, m[q]++;
		}
	}
	cout<<ans;
	return 0;
}