#include <bits/stdc++.h>
using namespace std;
#define ll int

ll q;
string s,a,b;
unordered_map <string,vector<ll> > mp;
map <pair<string,string>,ll> save;

int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		string ex;
		for(int j=i;j<min(i+4,(ll)s.size());j++)
			ex+=s[j],mp[ex].push_back(i);
	}
	cin>>q;
	while(q--)
	{
		ll ans=(ll)1e9;
		cin>>a>>b;
		if(save[{a,b}]){cout<<save[{a,b}]<<"\n";continue;}
		if(mp[a].size()==0 || mp[b].size()==0){cout<<"-1\n";continue;}
		if(mp[b].size()<mp[a].size())swap(a,b);
		for(auto x:mp[a])
		{
			ll ex=lower_bound(mp[b].begin(),mp[b].end(),x)-mp[b].begin();
			if(ex!=(ll)mp[b].size())ans=min(ans,mp[b][ex]-x+(ll)b.size());
			if(ex!=0)ex--,ans=min(ans,x-mp[b][ex]+(ll)a.size());
		}
		ans=max(ans,max((ll)a.size(),(ll)b.size()));
		save[{a,b}]=save[{b,a}]=ans;
		cout<<ans<<"\n";
	}
	return 0;
}