#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct LCT{
	int fa,ch[2],si,sr,mx,val;
	bool rev;
}t[400100];
inline int identify(int x){
	if(x==t[t[x].fa].ch[0])return 0;
	if(x==t[t[x].fa].ch[1])return 1;
	return -1;
}
inline void pushup(int x){
	t[x].sr=t[x].si,t[x].mx=x;
	if(lson){
		t[x].sr+=t[lson].sr;
		if(t[t[x].mx].val<t[t[lson].mx].val)t[x].mx=t[lson].mx;
	}
	if(rson){
		t[x].sr+=t[rson].sr;
		if(t[t[x].mx].val<t[t[rson].mx].val)t[x].mx=t[rson].mx;
	}
}
inline void REV(int x){
	t[x].rev^=1,swap(lson,rson);
}
inline void pushdown(int x){
	if(!t[x].rev)return;
	if(lson)REV(lson);
	if(rson)REV(rson);
	t[x].rev=0;
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
inline void pushall(int x){
	if(identify(x)!=-1)pushall(t[x].fa);
	pushdown(x);
}
inline void splay(int x){
	pushall(x);
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
		t[x].si+=t[rson].sr-t[y].sr;
		rson=y;
		pushup(x);
	}
}
inline void makeroot(int x){
	access(x),splay(x),REV(x);
}
inline int findroot(int x){
	access(x),splay(x);
	pushdown(x);
	while(lson)x=lson,pushdown(x);
	splay(x);
	return x;
}
inline void split(int x,int y){
	makeroot(x),access(y),splay(y);
}
inline void link(int x,int y){
	split(x,y);
	tot-=(t[x].sr&1);
	tot-=(t[y].sr&1);
	t[x].fa=y;
	t[y].si+=t[x].sr;
	pushup(y);
	tot+=(t[y].sr&1);
}
inline void cut(int x,int y){
	split(x,y);
	tot-=(t[y].sr&1);
	t[y].ch[0]=t[x].fa=0,pushup(y);
	tot+=(t[x].sr&1);
	tot+=(t[y].sr&1);
}
struct edge{
	int x,y,z;
}e[300100];
struct op{
	int id;
	op(int x=0){id=x;}
	friend bool operator<(const op&x,const op&y){
		return e[x.id].z<e[y.id].z;
	}
};
priority_queue<op>q;
bool era[300100];
int main(){
	scanf("%d%d",&n,&m),tot=n;
	for(int i=1;i<=n;i++)t[i].sr=t[i].si=1;
	for(int i=1,res=0x3f3f3f3f;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),t[i+n].val=e[i].z;
		if(findroot(e[i].x)!=findroot(e[i].y))link(e[i].x,i+n),link(e[i].y,i+n),q.push(op(i));
		else{
			split(e[i].x,e[i].y);
			int tmp=t[e[i].y].mx;
			if(t[tmp].val>e[i].z){
				era[tmp-n]=true;
				cut(tmp,e[tmp-n].x),cut(tmp,e[tmp-n].y);
				link(e[i].x,i+n),link(e[i].y,i+n);
				q.push(op(i));
			}else era[i]=true;
		}
		while(!tot){
			while(era[q.top().id])q.pop();
			int tmp=q.top().id;
			cut(e[tmp].x,tmp+n),cut(e[tmp].y,tmp+n),era[tmp]=true;
			res=min(res,e[tmp].z);
			q.pop();
		}
		printf("%d\n",res==0x3f3f3f3f?-1:res);
	}
	return 0;
}