#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, s, ans=0;
int a[N], f[N], bit[N];
multiset<int> d;

int32_t main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	if(a[s])
	{
		f[a[s]]--;
		a[s]=0;
		ans++;	
		f[a[s]]++;
	}
	queue<int> missing;
	for(int i=0;i<=n-1;i++)
	{
		if(!f[i])
			missing.push(i);
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
		d.insert(a[i]);
	int ct=0;
	while(d.size() && *d.begin() == 0)
	{
		ct++;
		d.erase(d.begin());
	}
	for(int i=1;i<=ct-1;i++)
	{
		d.insert(missing.front());
		missing.pop();
	}
	if(ct==0)
	{
		ans++;
		d.erase(--d.end());
	}
	int cur=1;
	while(!d.empty())
	{
		int k=*(d.begin());
		if(k!=cur && k!=cur-1)
		{
			ans++;
			d.erase(--d.end());
			cur++;
		}
		else if(k==cur)
		{
			cur++;
			d.erase(d.find(k));
		}
		else
		{
			d.erase(d.find(k));
		}
	}
	ans+=max(0LL, ct-1);
	cout<<ans;
}