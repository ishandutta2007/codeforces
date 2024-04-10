#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int,int> mp;
const int inf=1e9;
pair <int,int> a[200005];
priority_queue <int,vector<int>,greater<int> > q;
int b[200005];
pair <int,int> c[200005];
vector <int> p[200005];
int nxt[200005],lst[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		mp.clear();
		int cntmp=0;
		for(int i=1;i<=n;i++) p[i].clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			if(!mp[x]) mp[x]=++cntmp;
			b[i]=mp[x];
			if(p[b[i]].size()) nxt[p[b[i]].back()]=i,lst[i]=p[b[i]].back();
			p[b[i]].push_back(i);
		}
		int cnt=0;
		for(int i=1;i<=m;i++)
			cin >> c[i].first >> c[i].second;
		sort(c+1,c+m+1);
		for(int i=1;i<=m;i++)
			c[i].second=max(c[i].second,c[i-1].second);
		int L=n+1,R=0;
		for(int i=1;i<=n;i++)
		{
			int x=lower_bound(c+1,c+m+1,make_pair(i+1,0ll))-c-1;
			if(x&&c[x].first<=i&&c[x].second>=i)
			{
		//	cout << i << " " << x << " " << c[x].first << " " << c[x].second << "*\n";
				int l=i,r=p[b[i]][upper_bound(p[b[i]].begin(),p[b[i]].end(),c[x].second)-p[b[i]].begin()-1];
				if(l==r) continue;
				a[++cnt]={l,r};
				if(nxt[l]==r) continue;
				l=nxt[l],r=lst[r];
				L=min(L,l),R=max(R,r);
			}
		}
		sort(a+1,a+cnt+1);
		int nw=0;
		for(int i=1;i<=cnt;i++)
			nw=max(nw,a[i].first);
		if(!cnt)
		{
			cout << "0\n";
			continue;
		}
		int ans=max(nw,R)-min(a[1].first,L)+1,l=a[1].first;
		while(!q.empty()) q.pop();
		for(int i=1;i<=cnt;i++) q.push(a[i].first);
		for(int i=1;i<=cnt;i++)
		{
			if(q.top()!=a[i].first) break;
			q.pop();
			nw=max(nw,a[i].second),q.push(a[i].second);
			
			ans=min(ans,max(nw,R)-min(q.top(),L)+1);
		}
		cout << ans << "\n";
	}
	return 0;
}