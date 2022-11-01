#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)300)

ll n,m,q,p,ans[N][N];
string s[N];
ll dx[4]={0,0,1,-1};
ll dy[4]={-1,1,0,0};
bool mark[N][N];

bool ok(ll x,ll y)
{
	if(x<0 || x>=n || y<0 || y>=m || s[x][y]=='*' || mark[x][y])return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q>>p;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]>='A' && s[i][j]<='Z')
			{
				ll cost=q*(s[i][j]-'A'+1);
				memset(mark,0,sizeof mark);
				queue <pair<pair<ll,ll>,ll> > q;q.push({{i,j},cost});mark[i][j]=1;
				while(q.size())
				{
					ll x=q.front().first.first,y=q.front().first.second,val=q.front().second;
					q.pop();
					ans[x][y]+=val;
					val/=2;
					if(val==0)continue;
					for(int i=0;i<4;i++)
						if(ok(x+dx[i],y+dy[i]))
						{
							mark[x+dx[i]][y+dy[i]]=1;
							q.push({{x+dx[i],y+dy[i]},val});
						}
				}
			}
	ll res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(ans[i][j]>p)
				res++;
	}
	cout<<res<<"\n";
	return 0;
}