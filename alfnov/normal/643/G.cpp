#include<bits/stdc++.h>
using namespace std;
int k;
int a[150005];
struct apple{
	int cd,ss[6],cx[6];
	void init(int x,int p){
		cd=1;
		ss[1]=x,cx[1]=p;
	}
};
pair<int,int>tt[1005],ss[1005];
apple operator+(apple a,apple b){
	int oto=0;
	for(int i=1;i<=a.cd;++i)
		ss[++oto]=make_pair(a.ss[i],a.cx[i]);
	for(int i=1;i<=b.cd;++i)
		ss[++oto]=make_pair(b.ss[i],b.cx[i]);
	sort(ss+1,ss+oto+1);
	int tot=0;
	for(int i=1;i<=oto;){
		int j=i,he=0;
		while(j<=oto&&ss[i].first==ss[j].first){
			he+=ss[j].second;
			++j;
		}
		tt[++tot]=make_pair(he,ss[i].first);
		i=j;
	}
	sort(tt+1,tt+tot+1);
	int L=1;
	while(tot-L>=k){
		int xx=tt[L].first;
		for(int i=L;i<=k+L;++i)tt[i].first-=xx;
		while(L<=tot&&tt[L].first==0)++L;
	}
	apple c;
	c.cd=tot-L+1;
	for(int i=L;i<=tot;++i){
		c.ss[i-L+1]=tt[i].second;
		c.cx[i-L+1]=tt[i].first;
	}
	return c;
}
apple sm[600005];
int bj[600005];
void pushdown(int l,int r,int o){
	if(!bj[o])return;
	int mid=(l+r)>>1;
	sm[o<<1].init(bj[o],mid-l+1);
	sm[o<<1|1].init(bj[o],r-mid);
	bj[o<<1]=bj[o<<1|1]=bj[o];
	bj[o]=0;
}
void build(int l,int r,int o){
	if(l==r){
		sm[o].init(a[l],1);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
void add(int l,int r,int o,int ll,int rr,int x){
	if(l>=ll&&r<=rr){
		bj[o]=x;
		sm[o].init(x,r-l+1);
		return;
	}
	pushdown(l,r,o);
	int mid=(l+r)>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,x);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,x);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
apple query(int l,int r,int o,int ll,int rr){
	if(l>=ll&&r<=rr)return sm[o];
	pushdown(l,r,o);
	int mid=(l+r)>>1;
	if(mid>=ll){
		if(mid>=rr)return query(l,mid,o<<1,ll,rr);
		return query(l,mid,o<<1,ll,rr)+query(mid+1,r,o<<1|1,ll,rr);
	}
	return query(mid+1,r,o<<1|1,ll,rr);
}
int main(){
	int n,m,p;
	cin>>n>>m>>p;
	k=100/p;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,n,1);
	while(m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			int x;
			scanf("%d",&x);
			add(1,n,1,l,r,x);
		}else{
			apple a=query(1,n,1,l,r);
			printf("%d",a.cd);
			for(int i=1;i<=a.cd;++i)
				printf(" %d",a.ss[i]);
			putchar('\n');
		}
	}
	return 0;
}