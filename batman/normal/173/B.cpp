#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N (1331)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,m,d[2][N];
char c;
vector <ll> e[2][N];

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d%d",&n,&m);
	//cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			//cin>>c;
			scanf(" %c",&c);
			if(c=='#')
				e[0][i].push_back(j),e[1][j].push_back(i);
		}
	queue <pair <bool,ll> > q;
	for(int i=0;i<N;i++)d[0][i]=d[1][i]=-1;
	d[0][0]=0;
	q.push({0,0});
	while(q.size())
	{
		ll x=q.front().second;
		bool p=q.front().first;
		q.pop();
		for(int i=0;i<e[p][x].size();i++)
			if(d[!p][e[p][x][i]]==-1)
				d[!p][e[p][x][i]]=d[p][x]+1,q.push({!p,e[p][x][i]});	
	}	
	printf("%d",d[0][n-1]);
	//cout<<d[0][n-1];
		
	return 0;
}