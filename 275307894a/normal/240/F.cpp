#include<cstdio>
#define l(x) x<<1
#define r(x) x<<1|1
using namespace std;
int n,m,k,x,y,z,f[27][500039],sum[27][500039],fs[27],flag,l,r,tot,ans[100039];
char s;
inline void push(int z,int l,int r,int now){
	int m=l+r>>1;
	sum[z][l(now)]=sum[z][r(now)]=sum[z][now];
	f[z][l(now)]=(sum[z][now]==1?m-l+1:0);f[z][r(now)]=(sum[z][now]==1?r-m:0);
	sum[z][now]=0;
}
inline void get(int x,int y,int z,int g,int l,int r,int now){
	if(x<=l&&r<=y){f[g][now]=(z==1?r-l+1:0);sum[g][now]=z;return;}
	int m=l+r>>1;
	if(sum[g][now]) push(g,l,r,now);
    if(x<=m)get(x,y,z,g,l,m,l(now));
	if(y>m) get(x,y,z,g,m+1,r,r(now));
	f[g][now]=f[g][l(now)]+f[g][r(now)]; 
}
inline int find(int x,int y,int g,int l,int r,int now){
	if(x<=l&&r<=y) return f[g][now];
	int m=l+r>>1,fs=0;
	if(sum[g][now]) push(g,l,r,now);
	if(x<=m)fs+=find(x,y,g,l,m,l(now));
	if(y>m) fs+=find(x,y,g,m+1,r,r(now)); 
	return fs;
}
inline void dfs(int g,int l,int r,int now){
	if(l==r) {if(f[g][now]) ans[l]=g;return;}
	if(sum[g][now])push(g,l,r,now);
	int m=l+r>>1;
	dfs(g,l,m,l(now));dfs(g,m+1,r,r(now));
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		s=getchar();
		while(s<'a'||s>'z') s=getchar();
		get(i,i,1,s-'a'+1,1,n,1);
	}
	while(m--){
		scanf("%d%d",&x,&y);tot=0;
		for(i=1;i<=26;i++) fs[i]=find(x,y,i,1,n,1);
		for(i=1;i<=26;i++) tot+=fs[i]&1;
		if(tot<=1){
			l=x;r=y;
			for(i=1;i<=26;i++) get(x,y,-1,i,1,n,1);
			for(i=1;i<=26;i++){
				if(fs[i]){
					if(fs[i]==1)get((x+y)/2,(x+y)/2,1,i,1,n,1);
					else{
						if(fs[i]&1)get((x+y)/2,(x+y)/2,1,i,1,n,1),get(l,l+fs[i]/2-1,1,i,1,n,1),get(r-fs[i]/2+1,r,1,i,1,n,1),l+=fs[i]/2,r-=fs[i]/2;
						else get(l,l+fs[i]/2-1,1,i,1,n,1),get(r-fs[i]/2+1,r,1,i,1,n,1),l+=fs[i]/2,r-=fs[i]/2;
					}
				}
			}
		}
	}
	for(i=1;i<=26;i++) dfs(i,1,n,1);
	for(i=1;i<=n;i++) putchar(ans[i]+96);
}