#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=3e5+5;

int n, a, b;
int p[N], q[N];
int ans=0;
priority_queue<pair<int, int>, vector<pair<int, int> > > pq;

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>q[i];
		ans+=q[i];
	}
	if(b==0)
	{
		cout<<ans;
		return 0;
	}
	int store=pow(2LL, a, 1e18);
	for(int i=1;i<=n;i++)
	{
		if(p[i]>q[i])
		{
			pq.push({p[i]-q[i], i});
		}
	}
	set<int> vis;
	vector<int> v;
	map<int, int> m;
	int index=0;
	while(!pq.empty() && b>0)
	{
		pair<int, int> cur=pq.top();
		ans+=cur.first;
		vis.insert(cur.second);
		v.push_back(cur.first);
		m[cur.second]=cur.first;
		index=cur.second;
		b--;
		pq.pop();
	}
	int finans=ans;
	for(int i=1;i<=n;i++)
	{
		int newp=p[i] * store;
		int newq=q[i];
		if(newp<=newq)
			continue; 
		if(vis.find(i)!=vis.end())
		{
			int curans=ans - m[i] + newp - newq;
			finans=max(finans, curans);
		}
		else
		{
			int curans;
			if(b==0)
				curans=ans - m[index] + newp - newq;
			else
				curans=ans + newp - newq;
			finans=max(finans, curans);
		}
	}
	cout<<finans;
	return 0;
}