#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)5010)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

string s;
ll dp[N],id[N],ans;
vector <pair<ll,ll> > v;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=1;i<N;i++)
	{
		set <ll> s;
		for(int j=1;j<=i;j++)
			s.insert((dp[max(0,j-2)]^dp[max(0,i-j-1)]));
		for(int j=0;;j++)
			if(!s.count(j))
			{
				dp[i]=j;
				break;
			}
	}
	for(int i=0,now=0;i<s.size();i++)
	{
		if(i==0 || i==(ll)s.size()-1 || s[i-1]!=s[i+1])
		{
			if(!now)continue;
			ans^=dp[now];
			v.push_back({i-now,now});
			now=0;
		}
		else now++;
	}
	if(!ans)return cout<<"Second",0;
	ll res=-1;
	for(auto u:v)
	{
		for(int i=1;i<=u.second;i++)
			if((dp[max(0,i-2)]^dp[max(0,u.second-i-1)]^dp[u.second]^ans)==0)
			{
				res=u.first+i;
				break;
			}
		if(res!=-1)break;		
	}
	cout<<"First\n"<<res;
	return 0;
}