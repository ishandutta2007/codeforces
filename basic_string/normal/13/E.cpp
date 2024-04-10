#include<bits/stdc++.h>
using namespace std;
struct T{
	int s,f,c[2],a;
}s[200009];
inline bool nrt(int x){
	return s[s[x].f].c[0]==x||s[s[x].f].c[1]==x;
}
inline void up(int x){
	s[x].s=s[s[x].c[0]].s+s[s[x].c[1]].s+1;
	s[x].a=max(x,max(s[s[x].c[0]].a,s[s[x].c[1]].a));
}
void rot(int x){
	register int y=s[x].f,z=s[y].f;
	register bool f=s[y].c[0]==x;
	register int w=s[x].c[f];
	if(nrt(y))s[z].c[s[z].c[1]==y]=x;
	if(w)s[w].f=y;
	s[x].f=z,s[y].c[!f]=w,s[x].c[f]=y,s[y].f=x;
	up(y);
}
void splay(int x){
	register int y;
	while(nrt(x)){
		y=s[x].f;
		if(nrt(y))rot((s[y].c[0]==x)^(s[s[y].f].c[0]==y)?x:y);
		rot(x);
	}
	up(x);
}
void access(int x){
	register int y=0;
	while(x)splay(x),s[x].c[1]=y,up(x),y=x,x=s[x].f;
}
int main(){
	register int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&j),s[i].s=1,s[i].a=i;
		if(i+j<=n)s[i].f=i+j;
	}
	while(m--){
		scanf("%d%d",&i,&j);
		if(i==1)access(j),splay(j),printf("%d %d\n",s[j].a,s[j].s);
		else scanf("%d",&i),access(j),splay(j),s[j].c[0]=s[s[j].c[0]].f=0,s[j].f=(i+j<=n)?(i+j):0,up(j);
	}
	return 0;
}