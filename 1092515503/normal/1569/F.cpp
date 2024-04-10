#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K,fac[12];
ll res;
int blk[12],num,BLK[12],mun;
int Hsh(){
	mun=0;for(int i=0;i<n;i++)if(!BLK[blk[i]])BLK[blk[i]]=mun++;
	int ret=0;for(int i=0;i<n;i++)ret=6*ret+BLK[blk[i]];
	for(int i=0;i<n;i++)BLK[blk[i]]=0;
	return ret;
}
unordered_map<int,bool>mp;
bool f[6][1<<6],g[12][12];
vector<int>v[6];
bool che(){
	memset(f,false,sizeof(f));
	for(int i=0;i<num;i++)if(g[v[i][0]][v[i][1]])f[i][1<<i]=true;
	for(int i=1;i<(1<<num);i++)for(int j=0;j<num;j++){
		if(!(i&(1<<j))||!f[j][i])continue;
		for(int k=0;k<num;k++){
			if(i&(1<<k))continue;
			if(g[v[j][0]][v[k][0]]&&g[v[j][1]][v[k][1]])f[k][i|(1<<k)]=true;
			if(g[v[j][0]][v[k][1]]&&g[v[j][1]][v[k][0]])f[k][i|(1<<k)]=true;
		}
	}
	for(int i=0;i<num;i++)if(f[i][(1<<num)-1])return true;
	return false;
}
void dfs(int pos){
	if(num>(n>>1))return;
	if(pos==n){
		for(int i=0;i<num;i++)v[i].clear();
		for(int i=0;i<n;i++)v[blk[i]].push_back(i);
		for(int i=0;i<num;i++)if(v[i].size()&1)return;
//		for(int i=0;i<n;i++)printf("%d ",blk[i]);puts("");
		int x=Hsh();
		if(num==(n>>1)){if(che())mp[x]=true;}
		else{
			int id=num-1;while(v[id].size()==2)id--;
			for(int i=1;i+1<v[id].size();i++){
				blk[v[id][i]]=blk[v[id].back()]=num;
				int y=Hsh();
				blk[v[id][i]]=blk[v[id].back()]=id;
				if(mp.find(y)!=mp.end()){mp[x]=true;break;}
			}
			for(int i=1;i+1<v[id].size();i++)blk[v[id][i]]=num;
			int y=Hsh();
			for(int i=1;i+1<v[id].size();i++)blk[v[id][i]]=id;
			if(mp.find(y)!=mp.end())mp[x]=true;
		}
		if(mp.find(x)!=mp.end())res+=fac[num];
		return;
	}
	blk[pos]=num++;dfs(pos+1),num--;
	for(int i=num-1;i>=0;i--)blk[pos]=i,dfs(pos+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	fac[1]=K;for(int i=2;i<=(n>>1);i++)fac[i]=fac[i-1]*(K-i+1);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),g[x-1][y-1]=g[y-1][x-1]=true;
	dfs(0);
	printf("%lld\n",res);
	return 0;
}
/*
6 0 1
*/