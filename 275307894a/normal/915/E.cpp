#include<cstdio>
using namespace std;
int n,m,k,x,y,z,tot=1;
struct tree{int l,r,f,sum;}t[15000039];
inline void push(int l,int r,int now){
	int m=(l+r)>>1;
	if(!t[now].l) t[now].l=++tot;
	if(!t[now].r) t[now].r=++tot;
	t[t[now].l].f=t[t[now].r].f=t[now].f;
	t[t[now].l].sum=(m-l+1)*(t[now].f-1);
	t[t[now].r].sum=(r-m)*(t[now].f-1);
	t[now].f=0;
}
inline void get(int x,int y,int z,int l,int r,int now){
	if(x<=l&&r<=y){t[now].sum=(r-l+1)*z;t[now].f=z+1;return;}
	int m=(l+r)>>1;
	if(t[now].f) push(l,r,now);
	if(x<=m){
		if(!t[now].l) t[now].l=++tot;
		get(x,y,z,l,m,t[now].l);
	}
	if(y>m){
		if(!t[now].r) t[now].r=++tot;
		get(x,y,z,m+1,r,t[now].r);
	}
	t[now].sum=t[t[now].l].sum+t[t[now].r].sum;
}
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	t[1].f=2;t[1].sum=n;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		get(x,y,z-1,1,n,1);
		printf("%d\n",t[1].sum);
	}
}