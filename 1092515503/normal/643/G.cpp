#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define vp vector<pii>
int n,m,p,num[150010],tag[600100];
vp v[600100];
bool cmp(const pii &x,const pii &y){
	return x.second>y.second;
}
vp operator +(const vp &x,const vp &y){
	vp z=x;
	for(int i=0;i<y.size();i++){
		bool qwq=false;
		for(int j=0;j<z.size();j++)if(z[j].first==y[i].first){z[j].second+=y[i].second,qwq=true;break;}
		if(!qwq)z.push_back(y[i]);
	}
	sort(z.begin(),z.end(),cmp);
	while(z.size()>=p){
		for(int i=0;i<z.size();i++)z[i].second-=z.rbegin()->second;
		z.pop_back();
	}
	return z;
}
void build(int x,int l,int r){
	if(l==r){v[x].push_back(make_pair(num[l],1));return;}
	build(lson,l,mid),build(rson,mid+1,r),v[x]=v[lson]+v[rson]; 
}
void change(int x,int l,int r,int val){
	tag[x]=val;
	v[x].clear();
	v[x].push_back(make_pair(val,r-l+1));
}
void pushdown(int x,int l,int r){
	if(!tag[x])return;
	change(lson,l,mid,tag[x]);
	change(rson,mid+1,r,tag[x]);
	tag[x]=0;
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){change(x,l,r,val);return;}
	pushdown(x,l,r),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),v[x]=v[lson]+v[rson];
} 
vp query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return {};
	if(L<=l&&r<=R)return v[x];
	pushdown(x,l,r);
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
int main(){
	scanf("%d%d%d",&n,&m,&p),p=(100/p)+1;
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	build(1,1,n);
	for(int i=1,t1,t2,t3,t4;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==1)scanf("%d",&t4),modify(1,1,n,t2,t3,t4);
		else{
			vp z=query(1,1,n,t2,t3);
			printf("%d ",z.size());
			for(auto j:z)printf("%d ",j.first);puts("");
		}
	}
	return 0;
}
/*
5 9 33
1 2 1 3 3
1 1 3 5
2 1 3
*/