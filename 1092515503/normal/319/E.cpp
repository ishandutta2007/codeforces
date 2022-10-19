#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct oper{
	int tp,l,r;
}q[100100];
vector<int>v[800100],dis;
int L[100100],R[100100],dsu[100100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
void merge(int x,int l,int r,int P,int id){
	if(l>P||r<P)return;
	if(!v[x].empty()){
		for(auto ip:v[x])ip=find(ip),dsu[ip]=id,L[id]=min(L[id],L[ip]),R[id]=max(R[id],R[ip]);
		v[x].clear(),v[x].push_back(id);
	}
	if(l!=r)merge(lson,l,mid,P,id),merge(rson,mid+1,r,P,id);
}
void assign(int x,int l,int r,int id){
	if(r<=L[id]||l>=R[id])return;
	if(L[id]<l&&r<R[id]){v[x].push_back(id);return;}
	assign(lson,l,mid,id),assign(rson,mid+1,r,id);
}
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].tp,&q[i].l,&q[i].r);
		if(q[i].tp==1)dis.push_back(q[i].l),dis.push_back(q[i].r);
	}
	sort(dis.begin(),dis.end()),dis.resize(n=unique(dis.begin(),dis.end())-dis.begin());
	for(int i=1;i<=m;i++){
		if(q[i].tp==1){
			cnt++;
			dsu[cnt]=cnt,q[i].l=lower_bound(dis.begin(),dis.end(),q[i].l)-dis.begin()+1,q[i].r=lower_bound(dis.begin(),dis.end(),q[i].r)-dis.begin()+1;
			L[cnt]=q[i].l,R[cnt]=q[i].r;
			merge(1,1,n,q[i].l,cnt),merge(1,1,n,q[i].r,cnt);
			assign(1,1,n,cnt);
		}else{
			int x=q[i].l,y=q[i].r;
			x=find(x),y=find(y);
			puts(x==y||(L[y]<L[x]&&L[x]<R[y])||(L[y]<R[x]&&R[x]<R[y])?"YES":"NO");
		}
	}
	return 0;
}