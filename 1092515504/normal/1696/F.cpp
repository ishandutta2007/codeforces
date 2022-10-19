/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char s[110][110][110];
vector<pair<int,int> >res;
bool era[110];
int num[110];
vector<int>v[110];
int fa[110],ord[110];
vector<int>u[110];
int dis[110];
void dfs(int x,int ft){
	dis[x]=dis[ft]+1;
	for(auto y:u[x])if(y!=ft)dfs(y,x);
}
void mina(){
	res.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)scanf("%s",s[i][j]+1);
	for(int i=1;i<=n;i++)era[i]=false,num[i]=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=1;k<=n;k++)if(s[i][j][k]=='1')num[k]++;
	for(m=1;m+1<n;m++){
		int x=-1;for(int i=1;i<=n;i++)if(!era[i]&&(x==-1||num[i]<num[x]))x=i;
		era[x]=true,ord[m]=x;
		for(int y=1;y<x;y++)if(!era[y])for(int z=1;z<=n;z++)if(s[y][x][z]=='1')num[z]--;
		for(int y=x+1;y<=n;y++)if(!era[y])for(int z=1;z<=n;z++)if(s[x][y][z]=='1')num[z]--;
	}
	for(int i=1;i<=n;i++)if(!era[i])ord[m++]=i;
	res.emplace_back(ord[n-1],ord[n]),fa[ord[n-1]]=ord[n],fa[ord[n]]=ord[n-1];
	for(int i=n-2;i;i--){
		fa[ord[i]]=-1;
		for(int j=i+1;j<=n;j++){
			int x=ord[i],y=ord[j],z=fa[y];
			if(x>z)swap(x,z);
			if(s[x][z][y]=='1'){fa[ord[i]]=y,res.emplace_back(ord[i],y);break;}
		}
		if(fa[ord[i]]==-1){puts("No");return;}
	}
	for(int i=1;i<=n;i++)u[i].clear();
	for(auto x:res)u[x.first].push_back(x.second),u[x.second].push_back(x.first);
	for(int i=1;i<=n;i++){
		dfs(i,0);
		for(int x=1;x<=n;x++)for(int y=x+1;y<=n;y++)if((s[x][y][i]=='1')!=(dis[x]==dis[y])){puts("No");return;}
	}
	puts("Yes");
	for(auto x:res)printf("%d %d\n",x.first,x.second);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
5
00000 01001 00000 01100
00000 10000 00000
00000 11010
00000
*/