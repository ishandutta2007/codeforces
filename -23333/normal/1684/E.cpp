#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int b[N],a[N];
map<int,int> M,use;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		M.clear(); use.clear();
		rep(i,1,n)
		{ 
		  cin>>a[i];
		  M[a[i]]++;
		} 
		if (m>=n)
		{
			cout<<0<<endl;
			continue;
	    }
		int cnt=0,cnt2=0,cnt3=0;
		vector<pair<int,int>> ve;
		for(auto v:M) cnt2++,ve.push_back({v.second,v.first});
		sort(ve.begin(),ve.end());
		int now=0,pos=-1;
		for(int i=0;i<ve.size();i++)
		  if (now+ve[i].first<=m)
		  {
		     now+=ve[i].first; pos=i;	use[ve[i].second]=1;
		     cnt++;
		  } else break;
		int ans=1e9;
		rep(i,0,n+m+100)
		{
			if (cnt3>m) break;
			ans=min(ans,cnt2-cnt);
			if (use[i])
			{
				now-=M[i]; cnt--;
				for (int i=pos+1;i<ve.size();i++)
				{
				  if (use[ve[i].second])
				  {
				    pos=i; continue;
				  }
				  if (now+ve[i].first<=m)
				  {
				  	now+=ve[i].first; pos=i; use[ve[i].second]=1;
				  	cnt++;
				  } else break;
			    }
			}
			if (M[i]==0) cnt3++; else cnt++;
			use[i]=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}