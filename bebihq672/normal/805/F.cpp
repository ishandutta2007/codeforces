#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> v[101010];
vector<int> dis[101010];
map<pair<int,int> , double> ans;
int cc[101010],cn;
int mxd[101010],diam[101010];
vector<int> Dis[101010],sum[101010];
int dfs(int x,int fx){
    cc[x]=cn;
    int Dist=0;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(y==fx)continue;
        dis[x][i]=dfs(y,x)+1;
        Dist=max(Dist,dis[x][i]);
    }return Dist;
}
void dfs2(int x,int fx,int Dis){
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(y!=fx)continue;
        dis[x][i]=Dis+1;
    }if(dis[x].size()==0){mxd[x]=0;diam[cc[x]]=0;return;}
    vector<pair<int,int> > Dists(dis[x].size());
    for(int i=0;i<Dists.size();i++)Dists[i]=make_pair(dis[x][i],i);
    sort(Dists.rbegin(),Dists.rend());
    mxd[x]=Dists[0].first;
    diam[cc[x]]=max(mxd[x],diam[cc[x]]);
    if(Dists.size()>1)diam[cc[x]]=max(diam[cc[x]],Dists[0].first+Dists[1].first);
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(y==fx)continue;
        if(Dists[0].second!=i)dfs2(y,x,Dists[0].first);
        else if(Dists.size()>1)dfs2(y,x,Dists[1].first);
        else dfs2(y,x,0);
    }
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		dis[x].push_back(-1);
		dis[y].push_back(-1);
	}
	cn=0;
    for(int i=1;i<=n;i++)
	if(!cc[i])
	{
		cn++;
		dfs(i,-1);
		dfs2(i,-1,0);
	}
    for(int i=1;i<=n;i++)
		Dis[cc[i]].push_back(mxd[i]);
    for(int i=1;i<=cn;i++)
	{
        sort(Dis[i].begin(),Dis[i].end());
        sum[i].resize(Dis[i].size()+1);
        sum[i][Dis[i].size()]=0;
        for(int j=Dis[i].size()-1;j>=0;j--)
			sum[i][j]=sum[i][j+1]+Dis[i][j];
    }
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=cc[x];
		y=cc[y];
		if(x==y)
			puts("-1");
		else if(ans.count(make_pair(x,y)))
			printf("%.8f\n",ans[make_pair(x,y)]);
		else
		{  
			if(Dis[x].size()>Dis[y].size())
				swap(x,y);
			long long tmp=0;
		    for(int i=0;i<Dis[x].size();i++)
			{
		        long long len=lower_bound(Dis[y].begin(),Dis[y].end(),max(diam[x],diam[y])-Dis[x][i])-Dis[y].begin();
		        tmp+=len*max(diam[x],diam[y])+(Dis[y].size()-len)*(Dis[x][i]+1)+sum[y][len];
		    }
			ans[make_pair(x,y)]=1.0*tmp/(1.0*Dis[x].size()*Dis[y].size());
			ans[make_pair(y,x)]=1.0*tmp/(1.0*Dis[x].size()*Dis[y].size());
			printf("%.8f\n",1.0*tmp/(1.0*Dis[x].size()*Dis[y].size()));
		}
	}
	return 0;
}