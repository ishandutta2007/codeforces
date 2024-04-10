#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
const int N=5005;
int n,m,ans;
char s[N][N];
bool vs[N][N],tn[N],tm[N];
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
il void dfs(ct x,ct y){
	if(x<1||x>n||y<1||y>m||vs[x][y]||s[x][y]!='#') return;
	vs[x][y]=1;
	for(it k=0;k<4;++k) dfs(x+dx[k],y+dy[k]);
}
int main(){
	scanf("%d%d",&n,&m);it i,j;
	for(i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]=='#'){
				if((s[i-1][j]=='.'&&tm[j]) || (s[i][j-1]=='.'&&tn[i])) return puts("-1"),0;
				tn[i]=tm[j]=1;
			}
	it tx=0,ty=0;
	for(i=1;i<=n;++i) tx+=tn[i];
	for(i=1;i<=m;++i) ty+=tm[i];
	if((tx==n)!=(ty==m)) return puts("-1"),0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]=='#'&&(!vs[i][j])) dfs(i,j),++ans;
	printf("%d",ans);
	return 0;
}