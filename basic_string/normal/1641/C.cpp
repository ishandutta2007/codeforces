#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
struct Q{
	int t,l,r,x;
}q[N];
struct T{
	int l,r,s;
}t[N*90];
int rt[N],u,v,id;
void upd(int&k,int l,int r){
	if(t[k].s==r-l+1)return;
	t[++id]=t[k],k=id;
	if(u<=l&&r<=v){
		t[k].s=r-l+1;
		return;
	}
	int m=l+r>>1;
	if(u<=m)upd(t[k].l,l,m);
	if(m<v)upd(t[k].r,m+1,r);
	t[k].s=t[t[k].l].s+t[t[k].r].s;
}
int qry(int k,int l,int r){
	if(!k)return 0;
	if(t[k].s==r-l+1)return min(r,v)-max(l,u)+1;
	if(u<=l&&r<=v)return t[k].s;
	int m=l+r>>1,z=0;
	if(u<=m)z=qry(t[k].l,l,m);
	if(m<v)z+=qry(t[k].r,m+1,r);
	return z;
}
vector<int>vc[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,x;
	cin>>n>>m;
	for(i=1;i<=m;++i){
		cin>>q[i].t>>q[i].l;
		rt[i]=rt[i-1];
		if(q[i].t==0){
			cin>>q[i].r>>q[i].x;
			if(q[i].x==0){
				u=q[i].l,v=q[i].r;
				upd(rt[i],1,n);
			}
		}
	}
	for(i=1;i<=m;++i)if(q[i].t==0&&q[i].x==1){
		int l=i,r=m,o;
		u=q[i].l,v=q[i].r,x=v-u;
		while(l<=r){
			o=l+r>>1;
			if(qry(rt[o],1,n)==x)r=o-1;
			else l=o+1;
		}
		vc[l].push_back(i);
	}
	for(i=1;i<=m;++i){
		for(int o:vc[i])u=q[o].l,v=q[o].r,upd(rt[0],1,n);
		if(q[i].t==1){
			u=v=q[i].l;
			if(qry(rt[i],1,n)==1)cout<<"NO\n";
			else if(qry(rt[0],1,n)==1)cout<<"YES\n";
			else cout<<"N/A\n";
		}
	}
	return 0;
}