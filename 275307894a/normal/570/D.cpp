#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,x,y,z,bg[500039],dh,en[500039],ans[500039],sf[500039],d[500039],dfn[500039];
char c,a[500039];
static char buf[10000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
struct yyy{int to,z;};
struct ljb{
	int head,h[500039];
	yyy f[500039];
	inline void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
struct ques{int x,num;}tmp;
vector<ques> f[500039];
inline void dfs(int x,int last){
	yyy tmp;d[x]=d[last]+1;dfn[++dh]=x;bg[x]=dh;
	for(int cur=s.h[x];cur;cur=tmp.z)tmp=s.f[cur],dfs(tmp.to,x);
	en[x]=dh;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	read(n);read(m);
	for(i=2;i<=n;i++)read(x),s.add(x,i);
	for(i=1;i<=n;i++){
		c=getchar();
		while(c<'a'||c>'z') c=getchar();
		a[i]=c;
	} 
	dfs(1,0);
	for(i=1;i<=m;i++){
		read(x);read(y);
		f[bg[x]-1].push_back((ques){y,i});f[en[x]].push_back((ques){y,i});
	}
	for(i=1;i<=n;i++){
		sf[d[dfn[i]]]^=(1<<(a[dfn[i]]-'a'));
		for(j=0;j<f[i].size();j++)tmp=f[i][j],ans[tmp.num]^=sf[tmp.x];
	}
	for(i=1;i<=m;i++){
		if(ans[i]==(ans[i]&-ans[i])) putchar('Y'),putchar('e'),putchar('s'),putchar('\n');
		else putchar('N'),putchar('o'),putchar('\n');
	}
}