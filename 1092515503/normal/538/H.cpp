#include<bits/stdc++.h>
using namespace std;
int l[100100],r[100100],L,R,a,b=0x3f3f3f3f,n,m,col[100100];
vector<int>v[100100];
bool one[100100],two[100100];
void dfs(int x){
	for(auto y:v[x]){
		if(!col[y])col[y]=col[x]^3,dfs(y);
		else if(col[y]==col[x]){puts("IMPOSSIBLE");exit(0);}
	}
}
int main(){
	scanf("%d%d%d%d",&L,&R,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]),a=max(l[i],a),b=min(b,r[i]);
	if(a+b<L)a=L-b;
	if(a+b>R)b=R-a;
	if(a<0||b<0){puts("IMPOSSIBLE");return 0;}
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=1;i<=n;i++)one[i]=(l[i]<=a&&a<=r[i]),two[i]=(l[i]<=b&&b<=r[i]);
	for(int i=1;i<=n;i++){
		if(one[i]&&two[i])continue;
		if(!one[i]&&!two[i]){puts("IMPOSSIBLE");return 0;}
		if(one[i]){
			if(!col[i])col[i]=1,dfs(i);
			else if(col[i]!=1){puts("IMPOSSIBLE");return 0;}
		}
		if(two[i]){
			if(!col[i])col[i]=2,dfs(i);
			else if(col[i]!=2){puts("IMPOSSIBLE");return 0;}
		}
	}
	for(int i=1;i<=n;i++){
		if(!one[i]||!two[i])continue;
		if(col[i])continue;
		col[i]=1,dfs(i);
	}
	puts("POSSIBLE");
	printf("%d %d\n",a,b);
	for(int i=1;i<=n;i++)printf("%d",col[i]);
	return 0;
}