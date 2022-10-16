#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n,m,k,sum,c,tp[100002],f[100002],dis[502][502],l[502],r[502];
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c,dis[i][i]=0;
		l[i]=sum+1,r[i]=sum+c;
		for(int j=sum+1;j<=sum+c;j++)tp[j]=i;
		sum+=c;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(w==0)f[get(u)]=get(v);
		dis[tp[u]][tp[v]]=min(dis[tp[u]][tp[v]],w);
		dis[tp[v]][tp[u]]=min(dis[tp[v]][tp[u]],w);
	}
	for(int i=1;i<=k;i++){
		int pd=get(r[i]),pdd=1;
		for(int j=l[i];j<r[i];j++)
			if(get(j)!=pd)pdd=0;
		if(!pdd)cout<<"No",exit(0);
	}
	cout<<"Yes\n";
	for(int l=1;l<=k;l++)
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			int d=min(dis[i][j],dis[j][i]);
			cout<<(d==0x3f3f3f3f?-1:d)<<" ";
		}
		cout<<endl;
	}
	return 0;
}