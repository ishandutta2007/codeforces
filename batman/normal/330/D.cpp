#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (1111)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,m,d[N][N];
string s[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='E')
			{
				queue <pair <ll,ll> > q;	
				d[i][j]=1;
				q.push({i,j});
				
				while(q.size())
				{
					ll a=q.front().first,b=q.front().second;
					q.pop();
					if(a>0 && !d[a-1][b] && s[a-1][b]!='T')d[a-1][b]=d[a][b]+1,q.push({a-1,b});
					if(a<n-1 && !d[a+1][b] && s[a+1][b]!='T')d[a+1][b]=d[a][b]+1,q.push({a+1,b});
					if(b>0 && !d[a][b-1] && s[a][b-1]!='T')d[a][b-1]=d[a][b]+1,q.push({a,b-1});
					if(b<m-1 && !d[a][b+1] && s[a][b+1]!='T')d[a][b+1]=d[a][b]+1,q.push({a,b+1});
				}
				ll now,ans=0;
				for(int k1=0;k1<n;k1++)
					for(int k2=0;k2<m;k2++)
						if(s[k1][k2]=='S')
						{
							now=d[k1][k2];
							break;
						}
				for(int k1=0;k1<n;k1++)
					for(int k2=0;k2<m;k2++)
						if('0'<s[k1][k2] && s[k1][k2]<='9' && d[k1][k2]<=now && d[k1][k2])
							ans+=s[k1][k2]-'0';
				cout<<ans;
				break;	
			}	
	return 0;
}