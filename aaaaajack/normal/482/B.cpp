#include<cstdio>
#define N (1<<17)
using namespace std;
struct node{
	int val;
	int sum;
}seg[N<<1];
int l[N],r[N],q[N];
void push(int now){
	seg[now<<1].val|=seg[now].val;
	seg[now<<1|1].val|=seg[now].val;
	seg[now].val=0;
}
void pull(int now){
	seg[now].sum=(seg[now<<1].sum|seg[now<<1].val)&(seg[now<<1|1].sum|seg[now<<1|1].val);
}
int qry(int l,int r,int nl,int nr,int now){
	if(l==nl&&r==nr) return seg[now].val|seg[now].sum;
	if(l>=r) return -1;
	int m=(nl+nr)/2,ans;
	push(now);
	if(m>=r) ans=qry(l,r,nl,m,now<<1);
	else if(m<=l) ans=qry(l,r,m,nr,now<<1|1);
	else ans=qry(l,m,nl,m,now<<1)&qry(m,r,m,nr,now<<1|1);
	pull(now);
	return ans;
}
void upd(int l,int r,int nl,int nr,int now,int v){
	if(l==nl&&r==nr){
		seg[now].val|=v;
		return ;
	}
	if(l>=r) return;
	int m=(nl+nr)/2;
	push(now);
	if(m>=r) upd(l,r,nl,m,now<<1,v);
	else if(m<=l) upd(l,r,m,nr,now<<1|1,v);
	else{
		upd(l,m,nl,m,now<<1,v);
		upd(m,r,m,nr,now<<1|1,v);
	}
	pull(now);
}
int main(){
	int n,m,i;
	bool flag=true;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&l[i],&r[i],&q[i]);
		upd(l[i]-1,r[i],0,n,1,q[i]);
	}
	for(i=0;i<m;i++){
		if(qry(l[i]-1,r[i],0,n,1)!=q[i]) flag=false;
	}
	if(flag){
		printf("YES\n");
		for(i=0;i<n;i++){
			if(i) putchar(' ');
			printf("%d",qry(i,i+1,0,n,1));
		}
		putchar('\n');
	}
	else printf("NO\n");
	return 0;
}