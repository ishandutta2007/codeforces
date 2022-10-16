#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,c[N],f[N],cnt,ans;
map <int,int> mp[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy)f[xx]=yy;
}
vector <int> z[N];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		merge(u,v);
	}
	for(int i=1;i<=n;i++)
		z[find(i)].push_back(i),mp[f[i]][c[i]]++;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=0;j<z[i].size();j++)
			cnt=max(cnt,mp[i][c[z[i][j]]]);
		ans+=z[i].size()-cnt;
	}
	cout<<ans<<endl;
	return 0;
}