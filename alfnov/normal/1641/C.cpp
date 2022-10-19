#include<bits/stdc++.h>
using namespace std;
int ff[200005];
int sm[800005];
void add(int l,int r,int o,int x,int y){
	if(l==r){
		sm[o]=min(sm[o],y);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(l,mid,o<<1,x,y);
	else add(mid+1,r,o<<1|1,x,y);
	sm[o]=min(sm[o<<1],sm[o<<1|1]);
}
int query(int l,int r,int o,int ll,int rr){
	if(l>=ll&&r<=rr)return sm[o];
	int mid=(l+r)>>1,ans=1e9;
	if(mid>=ll)ans=min(ans,query(l,mid,o<<1,ll,rr));
	if(mid<rr)ans=min(ans,query(mid+1,r,o<<1|1,ll,rr));
	return ans;
}
int main(){
	int n,q;
	cin>>n>>q;
	set<int>se;
	for(int i=0;i<=n+1;++i)se.emplace(i);
	memset(sm,63,sizeof(sm));
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==0){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(x==0){
				auto it=se.lower_bound(l);
				int to=0;
				for(;it!=se.end()&&(*it)<=r;++it){
					ff[++to]=*it;
				}
				for(int i=1;i<=to;++i)se.erase(ff[i]);
			}else{
				add(1,n,1,l,r);
			}
		}else{
			int x;
			scanf("%d",&x);
			auto it=se.lower_bound(x);
			if(it==se.end()||(*it)!=x){
				puts("NO");
				continue;
			}
			int L,R;
			--it,L=(*it)+1,++it;
			++it,R=(*it)-1,--it;
			if(query(1,n,1,L,x)<=R)puts("YES");
			else puts("N/A");
		}
	}
	return 0;
}