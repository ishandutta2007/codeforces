#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (2100*2000)
ll n,m,nex[N],trm[N],dis[N],mark[N];

void dfs(ll x)
{
	mark[x]=1;
	if(mark[nex[x]]==1 && trm[nex[x]])
	{
		cout<<-1;
		exit(0);
	}
	if(trm[nex[x]] && !mark[nex[x]])
		dfs(nex[x]);
	dis[x]=dis[nex[x]]+(trm[x]);
	mark[x]=2;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	{
    		char c;
    		cin>>c;
    		if(c=='<')
    			nex[i*m+j]=i*m+j-1,trm[i*m+j]=1;
    		else if(c=='>')
				nex[i*m+j]=i*m+j+1,trm[i*m+j]=1;
			else if(c=='^')
				nex[i*m+j]=(i-1)*m+j,trm[i*m+j]=1;
			else if(c=='v')
				nex[i*m+j]=(i+1)*m+j,trm[i*m+j]=1;				
		}
	for(int i=0;i<n*m;i++)
		dfs(i);	
	ll maxi_in=0;
	for(int i=0;i<n*m;i++)
		if(dis[i]>dis[maxi_in])
			maxi_in=i;		
	ll ans=dis[maxi_in];
	while(maxi_in)
		trm[maxi_in]=0,maxi_in=nex[maxi_in];
		
	memset(dis,0,sizeof dis);
	memset(mark,0,sizeof mark);
	for(int i=0;i<n*m;i++)
		dfs(i);
	maxi_in=0;
	for(int i=0;i<n*m;i++)
		if(dis[i]>dis[maxi_in])
			maxi_in=i;			
	cout<<max(ans*2-1,ans+dis[maxi_in]);		
    return 0;
}