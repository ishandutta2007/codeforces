#include<cstdio>
#define N (1<<17)
struct node{
	int sum[26];
	int sz;
	int val[26];
}tree[N<<1];
using namespace std;
char s[N];
inline int qsum(int u,char c){
	if(tree[u].val[c]==1) return tree[u].sz;
	else if(tree[u].val[c]==-1) return 0;
	else return tree[u].sum[c];
}
inline void push(int u){
	for(int i=0;i<26;i++){
		if(tree[u].val[i]){
			tree[u].sum[i]=qsum(u,i);
			tree[u*2].val[i]=tree[u*2+1].val[i]=tree[u].val[i];
			tree[u].val[i]=0;
		}
	}
}
inline void pull(int u){
	for(int i=0;i<26;i++){
		tree[u].sum[i]=qsum(u*2,i)+qsum(u*2+1,i);
	}
}
void qry(int u,int ql,int qr,int l,int r,int res[]){
	if(ql>=qr) return;
	if(ql==l&&qr==r){
		for(int i=0;i<26;i++) res[i]+=qsum(u,i);
		return;
	}
	push(u);
	int md=(l+r)/2;
	if(qr<=md){
		qry(u*2,ql,qr,l,md,res);
	}
	else if(ql>=md){
		qry(u*2+1,ql,qr,md,r,res);
	}
	else{
		qry(u*2,ql,md,l,md,res);
		qry(u*2+1,md,qr,md,r,res);
	}
}
void upd(int u,int ql,int qr,int l,int r,int arg[]){
	if(ql>=qr) return;
	if(ql==l&&qr==r){
		for(int i=0;i<26;i++) tree[u].val[i]=arg[i];
		return;
	}
	push(u);
	int md=(l+r)/2;
	if(qr<=md){
		upd(u*2,ql,qr,l,md,arg);
	}
	else if(ql>=md){
		upd(u*2+1,ql,qr,md,r,arg);
	}
	else{
		upd(u*2,ql,md,l,md,arg);
		upd(u*2+1,md,qr,md,r,arg);
	}
	pull(u);
}
int main(){
	int n,q,i,j,u,l,r,od,val[26],res[26];
	scanf("%d%d",&n,&q);
	scanf("%s",s);
	for(i=0;i<n;i++){
		s[i]-='a';
		l=0;
		r=n;
		u=1;
		while(l+1<r){
			tree[u].sum[s[i]]++;
			tree[u].sz++;
			if(i<(l+r)/2) u=u*2,r=(l+r)/2;
			else u=u*2+1,l=(l+r)/2;
		}
		tree[u].sum[s[i]]++;
		tree[u].sz++;
	}
	while(q--){
		scanf("%d%d%d",&l,&r,&od);
		l--;
		for(i=0;i<26;i++) res[i]=0;
		qry(1,l,r,0,n,res);
		for(i=0;i<26;i++) val[i]=-1;
		if(od){
			for(i=0;i<26;i++){
				val[i]=1;
				upd(1,l,l+res[i],0,n,val);
				l+=res[i];
				val[i]=-1;
			}
		}
		else{
			for(i=25;i>=0;i--){
				val[i]=1;
				upd(1,l,l+res[i],0,n,val);
				l+=res[i];
				val[i]=-1;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<26;j++) res[j]=0;
		qry(1,i,i+1,0,n,res);
		for(j=0;j<26;j++){
			if(res[j]) putchar('a'+j);
		}
	}
	putchar('\n');
	return 0;
}