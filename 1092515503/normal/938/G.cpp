#include<bits/stdc++.h>
using namespace std;
int n,m,q,qwq;
pair<int,int>p[200100];
struct edge{
	int x,y,z,st,ed;
}e[400100];
//-----------------------Linear Basis Below----------------
int tms[40],d[40];
void ins(int now,int x){
    for(int i=30;i>=0;i--){
        if(!(x&(1<<i)))continue;
        if(tms[i]<now)swap(tms[i],now),swap(x,d[i]);
        if(!now)break;
        x^=d[i];
    }
}
int ask(int now,int x){
    for(int i=30;i>=0;i--)if(tms[i]>now&&(x^d[i])<x)x^=d[i];
    return x;
}
void print(){
	for(int i=0;i<=30;i++)if(d[i])printf("%d:%d\n",i,d[i]);
}
//------------------Linear Basis Above---------------------
//------------------LCT Below------------------------------
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct LCT{
    int fa,ch[2],mn,del,sum,val;
    bool rev;
}t[600100];
inline int identify(int x){
    if(x==t[t[x].fa].ch[0])return 0;
    if(x==t[t[x].fa].ch[1])return 1;
    return -1;
}
inline void pushup(int x){
    t[x].mn=x;
    t[x].sum=t[x].val;
    if(lson){
        if(t[t[x].mn].del>t[t[lson].mn].del)t[x].mn=t[lson].mn;
        t[x].sum^=t[lson].sum;
    }
    if(rson){
        if(t[t[x].mn].del>t[t[rson].mn].del)t[x].mn=t[rson].mn;
        t[x].sum^=t[rson].sum;
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
inline void access(int x){for(register int y=0;x;x=t[y=x].fa)splay(x),rson=y,pushup(x);}
inline void makeroot(int x){access(x),splay(x),REV(x);}
inline int split(int x,int y){makeroot(x),access(y),splay(y);return t[y].sum;}
inline void link(int x,int y){makeroot(x),t[x].fa=y;}
inline void cut(int x,int y){split(x,y),t[y].ch[0]=t[x].fa=0,pushup(y);}
inline int findroot(int x){
    access(x),splay(x);
    pushdown(x);
    while(lson)x=lson,pushdown(x);
    splay(x);
    return x;
}
inline void LINK(int ip){
	t[ip+n].val=e[ip].z;
	t[ip+n].del=e[ip].ed;
	pushup(ip+n);
	if(findroot(e[ip].x)!=findroot(e[ip].y)){link(e[ip].x,ip+n),link(e[ip].y,ip+n);return;}
	split(e[ip].x,e[ip].y);
	int id=t[e[ip].y].mn;
	if(t[id].del>t[ip+n].del){ins(t[ip+n].del,t[e[ip].y].sum^t[ip+n].val);return;}
	
	cut(e[id-n].x,id),cut(e[id-n].y,id);
	link(e[ip].x,ip+n),link(e[ip].y,ip+n);
	ins(t[id].del,split(e[id-n].x,e[id-n].y)^t[id].val);
}
//-----------------LCT above-------------------------------
map<pair<int,int>,int>mp;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)t[i].del=0x3f3f3f3f,t[i].val=0;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),mp[make_pair(e[i].x,e[i].y)]=i;
	scanf("%d",&q);
	for(int i=1,tp,x,y,z;i<=q;i++){
		scanf("%d%d%d",&tp,&x,&y);
		if(tp==1)scanf("%d",&z),++m,e[m].x=x,e[m].y=y,e[m].z=z,e[m].st=i,mp[make_pair(x,y)]=m;
		if(tp==2)e[mp[make_pair(x,y)]].ed=i,mp.erase(make_pair(x,y));
		if(tp==3)p[i]=make_pair(x,y);
	}
	for(int i=1;i<=m;i++)if(!e[i].ed)e[i].ed=q+1;
//	for(int i=1;i<=m;i++)printf("(%d,%d,%d):[%d,%d]\n",e[i].x,e[i].y,e[i].z,e[i].st,e[i].ed);
	for(int i=1,j=1;i<=q;i++){
		while(j<=m&&e[j].st<=i)LINK(j++);
		if(p[i]!=make_pair(0,0))printf("%d\n",ask(i,split(p[i].first,p[i].second)));
	}
	return 0;
}