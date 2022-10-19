#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>heng[505][505],zong[505][505];
long long z1[505],z2[505][505];
long long f[505][505],s1[505][505],s2[505][505];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i){
		int x,y,d,t,e;
		scanf("%d%d%d%d%d",&x,&y,&d,&t,&e);
		bool o1=0,o2=0,o3=0,o4=0;
		if((x+y-t)%4==0&&x+y>=t)o1=1,s1[x][y]+=e,s2[y][x]+=e;
		if((x+y-t-1)%4==0&&x+y>=t+1)o2=1,s1[x+d][y-d]+=e,s2[y-d][x+d]+=e;
		if((x+y+d-t-2)%4==0&&x+y+d>=t+2)o3=1,s1[x+d][y]+=e,s2[y][x+d]+=e;
		if((x+y+d-t-3)%4==0&&x+y+d>=t+3)o4=1,s1[x][y+d]+=e,s2[y+d][x]+=e;
		if(o1&&o4)heng[x][y+d].emplace_back(make_pair(y,e));
		if(o1&&o3)zong[x+d][y].emplace_back(make_pair(x,e));
		if(o2&&o3)heng[x+d][y].emplace_back(make_pair(y-d,e));
	}
	for(int i=0;i<n;++i)for(int j=1;j<m;++j)s1[i][j]+=s1[i][j-1];
	for(int j=0;j<m;++j)for(int i=1;i<n;++i)s2[j][i]+=s2[j][i-1];
	memset(f,63,sizeof(f));
	for(int j=0;j<m;++j){
		f[0][j]=s1[0][j];
		if(j)f[0][j]+=f[0][j-1]-s1[0][j-1];
		for(auto cu:heng[0][j])f[0][j]-=cu.second;
	}
	for(int i=0;i<n;++i){
		f[i][0]=s2[0][i];
		if(i)f[i][0]+=f[i-1][0]-s2[0][i-1];
		for(auto cu:zong[0][i])f[i][0]-=cu.second;
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<m;++j)z1[j]=0;
		for(int j=1;j<m;++j){
			for(auto pi:heng[i][j])z1[pi.first]-=pi.second;
			for(auto pi:zong[i][j])z2[j][pi.first]-=pi.second;
			long long a1=0,a2=0;
			for(int k=j-1;k>=0;--k){
				a1+=z1[k];
				long long bb=s1[i][j]+a1;
				if(k!=0)bb-=s1[i][k-1];
				f[i][j]=min(f[i][j],f[i][k]-(s2[k][i]-s2[k][i-1])+bb);
			}
			for(int k=i-1;k>=0;--k){
				a2+=z2[j][k];
				long long bb=s2[j][i]+a2;
				if(k!=0)bb-=s2[j][k-1];
				f[i][j]=min(f[i][j],f[k][j]-(s1[k][j]-s1[k][j-1])+bb);
			}
		}
	}
	cout<<f[n-1][m-1]<<endl;
	return 0;
}