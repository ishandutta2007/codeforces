#include<cstdio>
#include<set>
#include<algorithm>
#define N 200100
using namespace std;
multiset<int> now;
int add[N<<2],mval[N<<2];
inline int qmv(int u){
	return mval[u]+add[u];
}
void push(int u){
	add[u<<1]+=add[u];
	add[u<<1|1]+=add[u];
	mval[u]+=add[u];
	add[u]=0;
}
void pull(int u){
	if(qmv(u<<1)<=qmv(u<<1|1)){
		mval[u]=qmv(u<<1);
	}else{
		mval[u]=qmv(u<<1|1);
	}
}
void upd(int u,int ql,int qr,int l,int r,int v){
	if(l==ql&&r==qr){
		add[u]+=v;
		return;
	}
	push(u);
	int m=(l+r)/2;
	if(qr<=m){
		upd(u<<1,ql,qr,l,m,v);
	}
	else if(ql>=m){
		upd(u<<1|1,ql,qr,m,r,v);
	}
	else{
		upd(u<<1,ql,m,l,m,v);
		upd(u<<1|1,m,qr,m,r,v);
	}
	pull(u);
}
int qry(int u,int ql,int qr,int l,int r,int k){
	if(l==ql&&r==qr){
		if(qmv(u)>k) return -1;
		if(l+1==r) return l;
		push(u);
		if(qmv(u<<1)<=k) return qry(u<<1,l,(l+r)/2,l,(l+r)/2,k);
		else return qry(u<<1|1,(l+r)/2,r,(l+r)/2,r,k);
	}
	int m=(l+r)/2;
	push(u);
	if(qr<=m){
		return qry(u<<1,ql,qr,l,m,k);
	}
	else if(ql>=m){
		return qry(u<<1|1,ql,qr,m,r,k);
	}
	else{
		int al=qry(u<<1,ql,m,l,m,k),ar=qry(u<<1|1,m,qr,m,r,k);
		return al==-1?ar:al;
	}
}
inline int get_rem(int a,int b){
	return ((a%b)+b)%b;
}
int stk[2][N],sz[2],a[N],pos,len;
int main(){
	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	if(d==0){
		for(int i=0,j=0;i<n;i++){
			scanf("%d",&a[i]);
			while(a[j]!=a[i]) j++;
			if(i-j+1>len){
				len=i-j+1;
				pos=i;
			}
		}
		printf("%d %d\n",pos-len+2,pos+1);
	}
	else{
		upd(1,0,n,0,n,1);
		for(int i=0,j=0;i<n;i++){
			scanf("%d",&a[i]);
			int pre,nxt;
			if(i&&get_rem(a[i],d)!=get_rem(a[i-1],d)){
				sz[0]=sz[1]=0;
				while(j<i){
					now.erase(now.find(a[j++]));
				}
			}
			now.insert(a[i]);
			while(now.count(a[i])>1){
				now.erase(now.find(a[j++]));
			}
			while(sz[0]){
				pre=stk[0][sz[0]-1];
				nxt=sz[0]>1?stk[0][sz[0]-2]+1:0;
				if(a[i]>a[pre]) break;
				sz[0]--;
				upd(1,nxt,pre+1,0,n,(a[pre]-a[i])/d);
			}
			stk[0][sz[0]++]=i;
			while(sz[1]){
				pre=stk[1][sz[1]-1];
				nxt=sz[1]>1?stk[1][sz[1]-2]+1:0;
				if(a[i]<a[pre]) break;
				sz[1]--;
				upd(1,nxt,pre+1,0,n,(a[i]-a[pre])/d);
			}
			stk[1][sz[1]++]=i;
			upd(1,0,i+1,0,n,-1);
			int al=qry(1,j,i+1,0,n,k);
			if(i-al+1>len){
				len=i-al+1;
				pos=i;
			}
		}
		printf("%d %d\n",pos-len+2,pos+1);
	}
	return 0;
}