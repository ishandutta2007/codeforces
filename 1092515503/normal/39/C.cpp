#include<bits/stdc++.h>
using namespace std;
int n,f[4010][4010],t1,t2,cnt;
bool cir[4010][4010],ans[4010];
pair<int,int>p[4010],srt[4010];
vector<pair<int,int> >v[4010];
void dfs(int l,int r){
	if(!f[l][r])return;
	if(cir[l][r])for(int i=0;i<v[r].size();i++)if(v[r][i].first==l)ans[v[r][i].second]=true;
	if(f[l][r]==cir[l][r]+f[l][r-1]){dfs(l,r-1);return;}
	for(int i=0;i<v[r].size();i++)if(v[r][i].first>l&&f[l][r]==cir[l][r]+f[l][v[r][i].first]+f[v[r][i].first][r]){dfs(l,v[r][i].first),dfs(v[r][i].first,r);return;}
}
int main(){
	scanf("%d",&n),srt[0].first=-2e9;
	for(int i=1;i<=n;i++)scanf("%d%d",&t1,&t2),p[i]=make_pair(t1-t2,t1+t2),srt[i*2-1]=make_pair(t1-t2,i*2),srt[i*2]=make_pair(t1+t2,i*2+1);
	sort(srt+1,srt+n*2+1);
	for(int i=1;i<=n*2;i++){
		cnt+=srt[i].first!=srt[i-1].first;
		if(srt[i].second&1)p[srt[i].second/2].second=cnt;
		else p[srt[i].second/2].first=cnt;
	}
//	puts("");
//	for(int i=1;i<=n;i++)printf("%d %d\n",p[i].first,p[i].second);
	for(int i=1;i<=n;i++)v[p[i].second].push_back(make_pair(p[i].first,i)),cir[p[i].first][p[i].second]=true;
	for(int l=0;l<cnt;l++){
		for(int i=1;i+l<=cnt;i++){
			int j=i+l;
			f[i][j]=cir[i][j];
			if(i+1<j)f[i][j]+=f[i][j-1];
			for(int k=0;k<v[j].size();k++)if(v[j][k].first>i)f[i][j]=max(f[i][j],cir[i][j]+f[i][v[j][k].first]+f[v[j][k].first][j]);
		}
	}
	printf("%d\n",f[1][cnt]);
	dfs(1,cnt);
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
	return 0;
}
/*
4
1 1
2 2
4 1
5 1
*/