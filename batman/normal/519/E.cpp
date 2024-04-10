#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define K (51)

ll n,dp[N][K],dis,d[N],sub[N],now_dis,last;
vector <ll> e[N];
bool mark[N];

void dfs(ll x)
{
	mark[x]=1;
	d[x]=++dis;
	sub[x]=1;
	for(int i=1;i<K;i++)
		dp[x][i]=dp[dp[x][i-1]][i-1];
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dp[e[x][i]][0]=x,dfs(e[x][i]),sub[x]+=sub[e[x][i]];
	dis--;		
	mark[x]=0;				
}

ll query(ll x,ll num)
{
	for(int i=0;num;i++,num/=2)
		if(num%2)x=dp[x][i];
	return x;
}

ll par(ll x,ll y,ll k=K)
{
	ll i=k-1;
	for(;i>=0;i--)
		if(dp[x][i]!=dp[y][i])
			break;
	if(i<0){last=x;return dp[x][0];}
	now_dis+=(ll)(1ll<<i);
	return par(dp[x][i],dp[y][i],i);
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	ll x,y,m;
	cin>>m;
	while(m--)
	{
		ll tmp=0;
		now_dis=0;
		cin>>x>>y;
		if(x==y){cout<<n<<"\n";continue;}
		if(d[x]>d[y])
			swap(x,y);
		if(query(y,d[y]-d[x])!=x)
		{
			now_dis=1;
			x=par(x,query(y,d[y]-d[x]));
			if(now_dis==d[y]-d[x])
				tmp=sub[x]-n+sub[last];
			//cout<<now_dis<<endl;
		}
		//cout<<d[x]<<" "<<d[y]<<"\n";
		if((d[y]-d[x]+now_dis)%2==1){cout<<"0\n";continue;}
		cout<<sub[query(y,(d[y]-d[x]+now_dis)/2)]-sub[query(y,(d[y]-d[x]+now_dis)/2-1)]-tmp<<"\n";
		//cout<<n-sub[ans1]-sub[ans2]<<"\n";
	}
		
	
    return 0;
}