#include<bits/stdc++.h>
#define N 200100
#define Q 998244353
using namespace std;
map<int,int> seg[N];
int mul[N*2],add[N*2],ans[N*2],sz[N*2];
int get_ans(int u){
	return (1LL*ans[u]*mul[u]+1LL*add[u]*sz[u])%Q;
}
void pull(int u){
	while(u/=2){
		ans[u]=(get_ans(u*2)+get_ans(u*2+1))%Q;
	}
}
void upd_node(int u, int vmul, int vadd){
	mul[u]=1LL*mul[u]*vmul%Q;
	add[u]=(1LL*add[u]*vmul+vadd)%Q;
}
void push(int u){
	stack<int> s;
	while(u/=2){
		s.push(u);
	}
	while(!s.empty()){
		u=s.top();
		s.pop();
		ans[u]=get_ans(u);
		upd_node(u*2,mul[u],add[u]);
		upd_node(u*2+1,mul[u],add[u]);
		mul[u]=1,add[u]=0;
	}
}
void build(int n){
	for(int i=0;i<n*2;i++){
		mul[i]=1;
	}
	for(int i=0;i<n;i++){
		sz[n+i]=1;
	}
	for(int i=n*2-1;i>0;i--){
		sz[i/2]+=sz[i];
	}
}
void upd(int l,int r,int n, int vmul, int vadd){
	if(l==r) return;
	//printf("update (%d,%d): (mul=%d,add=%d)\n",l,r,vmul,vadd);
	int tl=l+n,tr=r+n;
	push(l+n);
	push(r+n-1);
	while(tl<tr){
		if(tl&1){
			upd_node(tl++,vmul,vadd);
		}
		if(tr&1){
			upd_node(--tr,vmul,vadd);
		}
		tl>>=1,tr>>=1;
	}
	pull(l+n);
	pull(r+n-1);
}
int qry(int l,int r,int n){
	int tl=l+n,tr=r+n;
	push(tl);
	push(tr-1);
	int res=0;
	while(tl<tr){
		if(tl&1) res=(res+get_ans(tl++))%Q;
		if(tr&1) res=(res+get_ans(--tr))%Q;
		tl>>=1,tr>>=1;
	}
	return res;
}
int main(){
	int n,q,t,l,r,x;
	scanf("%d%d",&n,&q);
	build(n);
	while(q--){
		scanf("%d%d%d",&t,&l,&r);
		--l;
		if(t==2) printf("%d\n",qry(l,r,n));
		else{
			scanf("%d",&x);
			auto it=seg[x].lower_bound(l);
			auto pit=it;
			int st=l,tl=l,ed=r;
			if(pit!=seg[x].begin() && (--pit)->second>=l){
				st=pit->first;
				if(pit->second<r){
					upd(l,pit->second,n,2,0);
					tl=pit->second;
				}
				else{
					upd(l,r,n,2,0);
					tl=r;
					ed=pit->second;
				}
				seg[x].erase(pit);
			}
			while(it!=seg[x].end() && it->second <= r){
				upd(tl,it->first,n,1,1);
				upd(it->first,it->second,n,2,0);
				tl=it->second;
				it=seg[x].erase(it);
			}
			if(it!=seg[x].end() && it->first <= r){
				upd(tl,it->first,n,1,1);
				upd(it->first,r,n,2,0);
				ed=it->second;
				seg[x].erase(it);
			}
			else{
				upd(tl,r,n,1,1);
			}
			seg[x][st]=ed;
		}
	}
	return 0;
}