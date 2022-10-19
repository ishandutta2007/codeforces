#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,cnt,sz,blk[5010],usage[5010];
bool f[5010][5010],frm[5010][5010];
vector<int>v[5010];
int col[5010];
vector<pair<int,int> >bin;
void dfs(int x){
	cnt+=col[x]-1,sz++,blk[x]=bin.size();
	for(auto y:v[x]){
		if(!col[y])col[y]=col[x]^3,dfs(y);
		else if(col[x]==col[y]){puts("NO");exit(0);}
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=1;i<=n;i++){
		if(col[i])continue;
		cnt=sz=0,col[i]=1;
		dfs(i);
		bin.push_back(make_pair(cnt,sz-cnt));
	}
	f[0][0]=true;
	for(int i=1;i<=bin.size();i++){
		for(int j=b;j>=0;j--){
			if(j>=bin[i-1].first&&f[i-1][j-bin[i-1].first])f[i][j]=true,frm[i][j]=false;
			if(j>=bin[i-1].second&&f[i-1][j-bin[i-1].second])f[i][j]=true,frm[i][j]=true;
		}
	}
	if(!f[bin.size()][b]){puts("NO");exit(0);}
	puts("YES");
	for(int i=bin.size(),j=b;i;i--)if(frm[i][j])usage[i-1]=true,j-=bin[i-1].second;else usage[i-1]=false,j-=bin[i-1].first;
	for(int i=1;i<=n;i++){
		if(usage[blk[i]]){
			if(col[i]==1)printf("2");
			else if(a)printf("1"),a--;
			else printf("3",c--);
		}else{
			if(col[i]==2)printf("2");
			else if(a)printf("1"),a--;
			else printf("3",c--);
		}
	}
	return 0;
}