// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((101*1000))
#define INF ((ll)1e9)

ll n,x[N],y[N],ans;
vector <ll> mpx[N],mpy[N];
unordered_map <ll,bool> mp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		mp[x[i]*N+y[i]]=1;
		mpx[x[i]].push_back(y[i]);
		mpy[y[i]].push_back(x[i]);
	}
	for(auto &v:mpx)sort(v.begin(),v.end());
	for(auto &v:mpy)sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		ll sz_x=mpx[x[i]].size(),sz_y=mpy[y[i]].size();
		if(sz_x<sz_y)
		{
			for(auto y2:mpx[x[i]])
			{
				if(y2>=y[i])continue;
				ll new_x=x[i]+(y[i]-y2);
				if(mp[new_x*N+y[i]]==1 && mp[new_x*N+y2]==1)ans++;
			}
		}
		else
		{
			for(auto x2:mpy[y[i]])
			{
				if(x2<=x[i])continue;
				ll new_y=y[i]-(x2-x[i]);
				if(mp[x[i]*N+new_y]==1 && mp[x2*N+new_y]==1)ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}