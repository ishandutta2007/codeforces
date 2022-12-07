#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int> >g[100003];
long long dp[53][200003],nwlen,x,y;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		x--;y--;
		g[x].push_back(make_pair(y,w));
		g[y].push_back(make_pair(x,w));
	}
	for(int i=0;i<53;i++)
		for(int j=0;j<200003;j++)
			dp[i][j]=1145141919810;
	priority_queue<pair<long long,pair<int,int> > >Q;
	dp[0][0]=0;
	Q.push(make_pair(0,make_pair(0,0)));
	while(Q.size()){
		nwlen=-Q.top().first,x=Q.top().second.first,y=Q.top().second.second;Q.pop();
		if(nwlen!=dp[x][y])continue;
		for(int i=0;i<g[y].size();i++){
			int nw=0;if(x==0)nw=g[y][i].second;
			long long newlen=nwlen;
			if(nw==0)newlen+=(g[y][i].second+x)*(g[y][i].second+x);
//			cout<<newlen<<' '<<nw<<' '<<g[y][i].first<<endl; 
			if(dp[nw][g[y][i].first]>newlen){
				dp[nw][g[y][i].first]=newlen;
				Q.push(make_pair(-newlen,make_pair(nw,g[y][i].first)));
			}
		}
	}
	for(int i=0;i<n;i++)
		if(dp[0][i]==1145141919810)
			printf("-1 ");
		else
			printf("%lld ",dp[0][i]);
}