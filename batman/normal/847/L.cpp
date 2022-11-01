#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1100)

ll n,cnt_comp[N],pos[N];
set <ll> v[N][N];
vector <pair<ll,ll> > ans;
bool dead[N];

int main()
{
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		ll j=0;
//		cout<<i<<"||| \n";
		while(j<s.size())
		{
			ll cnt=0;
			while(s[j]!=':')cnt*=10,cnt+=(s[j]-'0'),j++;
			j++;
			for(int k=0;k<cnt;k++)
			{
				ll x=0;
				while(j<s.size() && s[j]!=',' && s[j]!='-')x*=10,x+=(s[j]-'0'),j++;
				if(x<=0 || x>n)return cout<<"-1\n",0;
				j++;
				v[i][cnt_comp[i]].insert(x);
//				cout<<x<<" ";
			}
//			cout<<"\n";
			cnt_comp[i]++;
		}
	}
	for(int t=1;t<n;t++)
	{
		ll now=-1;
		for(int i=1;i<=n;i++)
			if(!dead[i])
			{
				ll cnt=0;
				for(int j=0;j<cnt_comp[i];j++)
					if(v[i][j].size())
						cnt++;
//				cout<<i<<" "<<cnt_comp[i]<<"\n";
				if(cnt==1)
				{
					now=i;
					break;
				}
			}
		if(now==-1)return cout<<"-1\n",0;
		dead[now]=1;
		ll par=-1;
		for(int i=1;i<=n;i++)
			if(!dead[i])
			{
				for(int j=0;j<cnt_comp[i];j++)
				{
					if(!v[i][j].count(now))continue;
					pos[i]=j;
					v[i][j].erase(now);
					if(v[i][j].size()==0)
					{
						if(par!=-1)return cout<<"-1\n",0;
						par=i;
					}
				}
			}
		if(par==-1)return cout<<"-1\n",0;
		for(int i=1;i<=n;i++)
			if(!dead[i] && i!=par && !v[i][pos[i]].count(par))
				return cout<<"-1\n",0;
		ans.push_back({now,par});
	}
	cout<<ans.size()<<"\n";
	for(auto u:ans)cout<<u.first<<" "<<u.second<<"\n";
	return 0;
}