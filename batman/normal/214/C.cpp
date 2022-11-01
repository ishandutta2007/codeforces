#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (202)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,room[N],num[N],tmp[N],ans=INF;
bool mark[N];
vector <ll> e[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>room[i],room[i]--;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		for(int j=0;j<num[i];j++)
		{
			ll a;
			cin>>a;
			e[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		if(!num[i])
		{
			for(int j=1;j<=n;j++)tmp[j]=num[j];
			ll p=room[i],res=0;
			bool did=1;
			queue <ll> q[3];
			for(int j=1;j<=n;j++)if(!tmp[j])q[room[j]].push(j);
			while(did)
			{
				did=0;
				if((ll)q[p].size())
				{
					did=1;
					ll x=q[p].front();q[p].pop();
					for(int j=0;j<e[x].size();j++)
					{
						tmp[e[x][j]]--;
						if(tmp[e[x][j]]==0)q[room[e[x][j]]].push(e[x][j]);
					}
					p=room[x];
				}
				else if((ll)q[(p+1)%3].size())
				{
					did=1;
					res++;
					ll x=q[(p+1)%3].front();q[(p+1)%3].pop();
					for(int j=0;j<e[x].size();j++)
					{
						tmp[e[x][j]]--;
						if(tmp[e[x][j]]==0)q[room[e[x][j]]].push(e[x][j]);
					}
					p=room[x];
				}
				else if((ll)q[(p+2)%3].size())
				{
					did=1;
					res+=2;
					ll x=q[(p+2)%3].front();q[(p+2)%3].pop();
					for(int j=0;j<e[x].size();j++)
					{
						tmp[e[x][j]]--;
						if(tmp[e[x][j]]==0)q[room[e[x][j]]].push(e[x][j]);
					}
					p=room[x];
				}
			}
			ans=min(ans,res);
		}
	cout<<ans+n;	
    return 0;
}