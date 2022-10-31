#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
#include<map>
#include<set>
#define N 200100
#define inf 1023456789
using namespace std;
int mval[1<<21],add[1<<21],dis[N*3],dpos[N*2];
struct duck{
	int h,t;
	bool operator<(const duck& rhs)const{return t<rhs.t||t==rhs.t&&h<rhs.h;}
}d[N];
inline int qmin(int u){
	return mval[u]+add[u];
}
inline void push(int u){
	mval[u]+=add[u];
	add[u<<1]+=add[u];
	add[u<<1|1]+=add[u];
	add[u]=0;
}
inline void pull(int u){
	mval[u]=min(qmin(u<<1),qmin(u<<1|1));
}
void upd(int u,int l,int r,int ql,int qr,int v){
	if(ql>=qr) return;
	if(l==ql&&r==qr){
		add[u]+=v;
		return;
	}
	int m=(l+r)/2;
	push(u);
	if(qr<=m) upd(u<<1,l,m,ql,qr,v);
	else if(ql>=m) upd(u<<1|1,m,r,ql,qr,v);
	else{
		upd(u<<1,l,m,ql,m,v);
		upd(u<<1|1,m,r,m,qr,v);
	}
	pull(u);
}
int qry(int u,int l,int r,int ql,int qr){
	if(ql>=qr) return inf;
	if(l==ql&&r==qr){
		return qmin(u);
	}
	int m=(l+r)/2;
	push(u);
	if(qr<=m) return qry(u<<1,l,m,ql,qr);
	else if(ql>=m) return qry(u<<1|1,m,r,ql,qr);
	else return min(qry(u<<1,l,m,ql,m),qry(u<<1|1,m,r,m,qr));
}
int main(){
	map<int,int> id;
	int n,r,cnt=0,sz,j=0,nv=0,pv=0,m,k=0,pr=0,nt;
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++){
		scanf("%d%d",&d[i].h,&d[i].t);
		if(d[i].t<0){
			i--;
			n--;
			continue;
		}
		if(d[i].h<0) d[i].h=0;
		dpos[i]=d[i].h;
		dpos[n+i]=d[i].t+1;
	}
	sort(d,d+n);
	sort(dpos,dpos+n*2);
	m=unique(dpos,dpos+n*2)-dpos;
	dpos[m]=inf;
	sz=n*3+1;
	dis[sz]=inf;
	nt=-inf;
	while(nt<inf){
		while(j<n&&d[j].t<nt){
			upd(1,0,sz,0,id[d[j].h],1);
			j++;
		}
		dis[cnt]=nt;
		id[nt]=cnt++;
		if(cnt>1){
			nv=qry(1,0,sz,0,id.upper_bound(nt-r)->second);
			pv=qry(1,0,sz,cnt-2,cnt-1);
			if(nv!=pv) upd(1,0,sz,cnt-1,sz,nv-pv);
		}
		while(k<m&&dpos[k]<=nt) k++;
		while(dis[pr]+r<=nt) pr++;
		nt=dpos[k];
		while(pr<cnt&&dis[pr]+r<dpos[k]){
			if(pr>0&&qry(1,0,sz,0,pr)>qry(1,0,sz,pr,pr+1)){
				nt=dis[pr]+r;
				break;
			}
			else pr++;
		}
	}
	printf("%d\n",n-qmin(1));
	return 0;
}