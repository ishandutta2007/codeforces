#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,head[50100],cnt,FA[50100],res;
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct LCT{
	int fa,ch[2],val,szi,szr,sqi,sumi,sumr,all;
}t[50100];
inline int identify(int x){
	if(x==t[t[x].fa].ch[0])return 0;
	if(x==t[t[x].fa].ch[1])return 1;
	return -1;
}
inline void pushup(int x){
	t[x].szr=t[x].szi+t[lson].szr+t[rson].szr,t[x].sumr=t[x].sumi+t[lson].sumr+t[rson].sumr;
	t[x].all=t[lson].all+t[rson].all+t[x].szi*t[x].val;
	t[x].sumr+=t[x].val*(t[x].szi*t[x].szi-t[x].sqi);
	t[x].sumr+=2*t[x].val*t[x].szi*t[rson].szr;
	t[x].sumr+=2*t[lson].all*(t[x].szr-t[lson].szr); 
}
inline void rotate(int x){
	register int y=t[x].fa;
	register int z=t[y].fa;
	register int dirx=identify(x);
	register int diry=identify(y);
	register int b=t[x].ch[!dirx];
	if(diry!=-1)t[z].ch[diry]=x;t[x].fa=z;
	if(b)t[b].fa=y;t[y].ch[dirx]=b;
	t[y].fa=x,t[x].ch[!dirx]=y;
	pushup(y),pushup(x);
}
inline void splay(int x){
	while(identify(x)!=-1){
		register int fa=t[x].fa;
		if(identify(fa)==-1)rotate(x);
		else if(identify(x)==identify(fa))rotate(fa),rotate(x);
		else rotate(x),rotate(x);
	}
}
inline void access(int x){
	for(register int y=0;x;x=t[y=x].fa){
		splay(x);
		t[x].sqi+=t[rson].szr*t[rson].szr;
		t[x].sumi+=t[rson].sumr;
		t[x].szi+=t[rson].szr;
		rson=y;
		t[x].sqi-=t[rson].szr*t[rson].szr;
		t[x].sumi-=t[rson].sumr;
		t[x].szi-=t[rson].szr;
		pushup(x);
	}
}
struct Edge{
	int to,next;
}edge[50100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs(int x){
	t[x].szi=1;
	for(int i=head[x];i!=-1;i=edge[i].next)dfs(edge[i].to),t[x].szi+=t[edge[i].to].szr,t[x].sumi+=t[edge[i].to].sumr,t[x].sqi+=t[edge[i].to].szr*t[edge[i].to].szr;
	pushup(x);
}
void cut(int x){
	access(FA[x]),splay(FA[x]),splay(x);
	t[x].fa=0;
	t[FA[x]].szi-=t[x].szr;
	t[FA[x]].sumi-=t[x].sumr;
	t[FA[x]].sqi-=t[x].szr*t[x].szr;
	pushup(FA[x]);
}
void link(int x,int y){
	access(y),splay(y),access(x),splay(x);
	t[y].fa=x;
	t[t[y].fa].szi+=t[y].szr;
	t[t[y].fa].sumi+=t[y].sumr;
	t[t[y].fa].sqi+=t[y].szr*t[y].szr;
	pushup(t[y].fa);	
}
bool che(int x,int y){
	access(y),splay(y),splay(x);
	return identify(y)!=-1;
}
void qwq(int x,int y){
	if(FA[x]==y||FA[y]==x)return;
	if(che(x,y))swap(x,y);
	cut(x);
	FA[x]=y;
	link(y,x);
}
void qaq(int x,int y){
	access(x),splay(x),t[x].val=y,pushup(x);
}
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
signed main(){
	read(n),memset(head,-1,sizeof(head));
	for(int i=2;i<=n;i++)read(FA[i]),ae(FA[i],i),t[i].fa=FA[i];
	for(int i=1;i<=n;i++)read(t[i].val),t[i].szi=1;
	dfs(1),res=t[1].sumr,printf("%.9lf\n",1.0*res/(n*n));
//	for(int j=1;j<=n;j++)printf("(F:%d,L:%d,R:%d,SQ:%d,AI:%d,AR:%d,SI:%d,SR:%d,V:%d)\n",t[j].fa,t[j].ch[0],t[j].ch[1],t[j].sqi,t[j].sumi,t[j].sumr,t[j].szi,t[j].szr,t[j].val);
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		char s[3];
		scanf("%s",s),read(x),read(y);
		if(s[0]=='P')qwq(x,y);
		else qaq(x,y);
		access(1),splay(1),res=t[1].sumr;
		printf("%.9lf\n",1.0*res/(n*n));
	}
	return 0;
}