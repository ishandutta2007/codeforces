#include<cstdio>
#define l(x) x<<1
#define r(x) x<<1|1
using namespace std;
int n,m,k,x,y,z,f[27][400039],flag[27][400039],ans[100039],fs[27],now;
inline void push(int l,int r,int now,int z){
	int m=l+r>>1;
	flag[z][l(now)]=flag[z][r(now)]=flag[z][now];
	f[z][l(now)]=(flag[z][now]==1?m-l+1:0);
	f[z][r(now)]=(flag[z][now]==1?r-m:0);
	flag[z][now]=0;
}
inline void get(int x,int y,int z,int fl,int l,int r,int now){
	if(x<=l&&r<=y){flag[z][now]=fl;f[z][now]=(fl==1?r-l+1:0);return;}
	if(flag[z][now])push(l,r,now,z);int m=l+r>>1;
	if(x<=m) get(x,y,z,fl,l,m,l(now));
	if(y>m) get(x,y,z,fl,m+1,r,r(now));
	f[z][now]=f[z][l(now)]+f[z][r(now)];
}
inline int find(int x,int y,int z,int l,int r,int now){
	if(x<=l&&r<=y) return f[z][now];
	int m=l+r>>1,fs=0;if(flag[z][now])push(l,r,now,z); 
	if(x<=m&&f[z][l(now)]) fs+=find(x,y,z,l,m,l(now));
	if(y>m&&f[z][r(now)]) fs+=find(x,y,z,m+1,r,r(now));
	return fs;
}
inline void dfs(int z,int l,int r,int now){
	if(l==r) {if(f[z][now])ans[l]=z;return;}
	if(flag[z][now])push(l,r,now,z);int m=l+r>>1;
	dfs(z,l,m,l(now));dfs(z,m+1,r,r(now));
}
char s;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		s=getchar();
		while(s<'a'||s>'z') s=getchar();
		get(i,i,s-'a'+1,1,1,n,1);
	}
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		for(i=1;i<=26;i++) fs[i]=find(x,y,i,1,n,1),get(x,y,i,-1,1,n,1);
		now=x;
		if(z){for(i=1;i<=26;i++)if(fs[i])get(now,now+fs[i]-1,i,1,1,n,1),now+=fs[i];}
		else for(i=26;i;i--)if(fs[i])get(now,now+fs[i]-1,i,1,1,n,1),now+=fs[i];
	}
	for(i=1;i<=26;i++) dfs(i,1,n,1);
	for(i=1;i<=n;i++) putchar(ans[i]+96);
}