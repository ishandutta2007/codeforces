#include<cstdio>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct fhq{int l,r,sum,key,siz;}f[1100039];
int cnt,root1,root2,root,root3;
inline void up(int x){f[x].siz=f[f[x].l].siz+f[f[x].r].siz+1;}
inline int newnode(int x){f[++cnt].siz=1;f[cnt].sum=x;f[cnt].key=rand();return cnt;}
inline void split(int now,int x,int &a,int &b){
	if(!now) a=b=0;
	else{
		if(f[now].sum<=x)a=now,split(f[now].r,x,f[now].r,b);
		else b=now,split(f[now].l,x,a,f[now].l);
		up(now);
	}
}
inline int merge(int x,int y){
	if(!x||!y) return x+y;
	if(f[x].key<f[y].key){f[x].r=merge(f[x].r,y),up(x);return x;}
	else {f[y].l=merge(x,f[y].l),up(y);return y;}
}
inline int find(int x){
	split(root,x-1,root1,root2);
	int now=f[root1].siz+1;
	root=merge(root1,root2);
	return now;
}
inline int query(int x,int now){
	while(x){
		if(f[f[now].l].siz+1==x)break;
		if(f[f[now].l].siz>=x) now=f[now].l;
		else  x-=f[f[now].l].siz+1,now=f[now].r;
	}
	return f[now].sum;
}
inline int las(int x){
	split(root,x-1,root1,root2);
	int now=root1,sum=0;
	while(now){
		sum=f[now].sum;
		now=f[now].r;
	}
	merge(root1,root2);
	return sum;
}
inline int net(int x){
	split(root,x,root1,root2);
	int now=root2,sum=0;
	while(now){
		sum=f[now].sum;
		now=f[now].l;
	}
	merge(root1,root2);
	return sum;
}
int n,m,k,x,y,z,p[200039],w[200039],now,ss[200039],he;
struct yyy{int x,num;}g[200039];
inline bool cmp(yyy x,yyy y){return x.x<y.x;}
char s;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1;i<=2*n;i++){
		s=getchar();
		while(s!='+'&&s!='-') s=getchar();
		if(s=='-') scanf("%d",&x),g[++he]=(yyy){x,i},ss[i]=x;
		else root=merge(root,newnode(i)),p[i]=1;
	}
	sort(g+1,g+n+1,cmp);
	for(i=1;i<=n;i++){
		now=las(g[i].num);
		if(!now){printf("NO\n");return 0;}
		w[now]=g[i].x;
		split(root,now,root1,root2);
		split(root1,now-1,root1,root3);
		root=merge(root1,root2);
	}
	for(i=1;i<=2*n;i++){
		if(p[i]==1)q.push(w[i]);
		else{
		//	printf("%d\n",q.top());
			if(q.empty()||q.top()!=ss[i]){printf("NO\n");return 0;}
			q.pop();
		}
	}
	printf("YES\n");
	for(i=1;i<=2*n;i++) if(p[i])printf("%d ",w[i]);
}