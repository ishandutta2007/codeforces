#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)101*1000)
#define SQ ((int)310)
#define QS ((int)N/SQ+10)

int n,q,a[N],nxt[N];
set <int> s[N];
pair <int,int> data[N];
ll prt[N];

void recalc(int x)
{
	int l=x*SQ,r=min(n,(x+1)*SQ);
	for(int i=l;i<r;i++)
	{
		auto it=s[a[i]].upper_bound(i);
		ll id;
		if(it==s[a[i]].end())id=i-1;
		else id=*it-1;
		nxt[i]=id;
		data[i]={id,i};
	}
	sort(data+l,data+r);
	prt[l]=data[l].first-data[l].second+1;
	for(int i=l+1;i<r;i++)
		prt[i]=prt[i-1]+data[i].first-data[i].second+1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i],s[a[i]].insert(i);
	for(int i=0;i<(n+SQ-1)/SQ;i++)recalc(i);
	while(q--)
	{
		int t,l,r,x,val;
		ll ans=0;
		cin>>t;
		if(t==1)
		{
			cin>>x>>val;x--;
			vector <int> change;
			auto it=s[a[x]].lower_bound(x);
			if(it!=s[a[x]].begin()){it--;change.push_back((*it)/SQ);}
			it=s[val].lower_bound(x);
			if(it!=s[val].begin()){it--;change.push_back((*it)/SQ);}
			s[a[x]].erase(x);
			a[x]=val;
			s[a[x]].insert(x);
			change.push_back(x/SQ);
			sort(change.begin(),change.end());change.resize(unique(change.begin(),change.end())-change.begin());
			for(auto u:change)recalc(u);
		}
		if(t==2)
		{
			cin>>l>>r;l--;
			int end=r;
			while(l<r && l%SQ)
			{
				//cout<<l<<" "<<nxt[l]<<"\n";
				if(nxt[l]<end-1)ans+=nxt[l]-l+1;
				l++;
			}
			while(l<r && r%SQ)
			{
				r--;
			//	cout<<r<<" "<<nxt[r]<<"\n";
				if(nxt[r]<end-1)ans+=nxt[r]-r+1;
			}
			//cout<<ans<<"\n";
			for(int i=l/SQ;i<r/SQ;i++)
			{
				pair <int,int> hlp;hlp={end-1,-1};
				int id=lower_bound(data+i*SQ,data+min(n,(i+1)*SQ),hlp)-data-1;
			//	for(int j=i*SQ;j<min(n,(i+1)*SQ);j++)cout<<data[j].first<<" "<<data[j].second<<"\n";
			//	cout<<id<<"\n";
				if(id>=i*SQ)ans+=prt[id];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}