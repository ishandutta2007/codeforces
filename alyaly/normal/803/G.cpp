#include<bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define inf 1999999999
//#pragma GCC optimize("Ofast")
#define D 13000000
using namespace std;
int n,K,a[100001],st[21][100001],logn[100001],Q,q0,q1,q2,q3,ans;
int seg0[400001],rt[400001],laz0[400001],seg[D+1],laz[D+1],son[D+1][2],pb;
//queue<int> pool;
void ycl(){
	for(int i=2;i<=n;i++)logn[i]=logn[i/2]+1;
	for(int i=1;i<=n;i++)st[0][i]=a[i];
	for(int i=1;i<=logn[n];i++){
		for(int j=1;j<=n;j++){
			st[i][j]=min(st[i-1][j],st[i-1][min(n,j+(1<<(i-1)))]);
		}
	}
}
int calst(int l,int r){
	return min(st[logn[r-l+1]][l],st[logn[r-l+1]][r-(1<<logn[r-l+1])+1]);
}
int getnew(int l,int r){
	pb++;
//	pb=pool.front();
	seg[pb]=calst(l,r);laz[pb]=-1;
	return pb;
}
void segdown(int u,int l,int r){
	if(l!=r){
		if(!son[u][0])son[u][0]=getnew(l,mid);if(!son[u][1])son[u][1]=getnew(mid+1,r);
	}
	if(laz[u]==-1)return;
	seg[u]=laz[u];
	if(l!=r){
		laz[son[u][0]]=laz[u],laz[son[u][1]]=laz[u];
	}
	laz[u]=-1;
}
void segup(int u,int l,int r){
	segdown(u,l,r);
	if(l!=r)segdown(son[u][0],l,mid),segdown(son[u][1],mid+1,r),seg[u]=min(seg[son[u][0]],seg[son[u][1]]);
}
void segadd(int u,int l,int r,int nl,int nr,int nx){
	if(l>nr||r<nl||laz[u]==nx)return;
	else if(l>=nl&&r<=nr){
		laz[u]=nx;
	}else{
		segdown(u,l,r);
		segadd(son[u][0],l,mid,nl,nr,nx),segadd(son[u][1],mid+1,r,nl,nr,nx);
		segup(u,l,r);
	}
}
int segreq(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return inf;
	else if(l>=nl&&r<=nr){
		segup(u,l,r);
		return seg[u];
	}
	else{
		if(laz[u]!=-1){
			segup(u,l,r);
			return seg[u];
		}
		segdown(u,l,r);
		int nans=min(segreq(son[u][0],l,mid,nl,nr),segreq(son[u][1],mid+1,r,nl,nr));
		segup(u,l,r);return nans;
	}
}
void segclr(int rt,int u,int l,int r){
	if(!u)return;
	if(l!=r)segclr(rt,son[u][0],l,mid),segclr(rt,son[u][1],mid+1,r);
	seg[u]=son[u][0]=son[u][1]=0;
//	if(u!=rt)pool.push(u);
}
void seg0down(int u,int l,int r){
	if(laz0[u]==-1)return;
	seg0[u]=laz0[u];
	if(l!=r){
		laz0[u*2]=laz0[u*2+1]=laz0[u];
	}else{
		segclr(rt[u],rt[u],1,n),seg[rt[u]]=laz[rt[u]]=laz0[u];
	}
	laz0[u]=-1;
}
void seg0up(int u,int l,int r){
	seg0down(u,l,r);
	if(l!=r)seg0down(u*2,l,mid),seg0down(u*2+1,mid+1,r),seg0[u]=min(seg0[u*2],seg0[u*2+1]);
}
int seg0fnd(int u,int l,int r,int np){
	if(l==r)return u;
	seg0up(u,l,r);
	if(np<=mid)return seg0fnd(u*2,l,mid,np);
	else return seg0fnd(u*2+1,mid+1,r,np);
}
void seg0add(int u,int l,int r,int nl,int nr,int nx){
	if(l>nr||r<nl||nl>nr)return;
	else if(l>=nl&&r<=nr)laz0[u]=nx;
	else{
		seg0down(u,l,r);
		seg0add(u*2,l,mid,nl,nr,nx),seg0add(u*2+1,mid+1,r,nl,nr,nx);
		seg0up(u,l,r);
	}
}
void seg0mdf(int u,int l,int r,int np,int nl,int nr,int nx){
	np=seg0fnd(u,l,r,np);
	segadd(rt[np],1,n,nl,nr,nx);
	segup(rt[np],1,n);
	seg0[np]=seg[rt[np]];
	while(np)np>>=1,seg0[np]=min(seg0[np*2],seg0[np*2+1]);
}
int seg0req(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return inf;
	else if(l>=nl&&r<=nr){
		seg0up(u,l,r);
		return seg0[u];
	}
	else{
		seg0down(u,l,r);
		int nans=min(seg0req(u*2,l,mid,nl,nr),seg0req(u*2+1,mid+1,r,nl,nr));
		seg0up(u,l,r);return nans;
	}
}
int seg0srq(int u,int l,int r,int np,int nl,int nr){
	np=rt[seg0fnd(u,l,r,np)];
	return segreq(np,1,n,nl,nr);
}
void seg0build(int u,int l,int r){
	if(l==r){
		rt[u]=getnew(1,n);
		seg0[u]=seg[rt[u]];
	}else{
		seg0build(u*2,l,mid),seg0build(u*2+1,mid+1,r);
		seg0[u]=min(seg0[u*2],seg0[u*2+1]);
	}
}
signed main(){
//	freopen("late.in","r",stdin);
//	for(int i=1;i<=D;i++)pool.push(i);
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>a[i];
	ycl();
	seg0build(1,1,K);
	for(int i=1;i<=4*K;i++)laz0[i]=-1;
	for(int i=1;i<=4*n;i++)laz[i]=-1;
	cin>>Q;
	while(Q--){
		cin>>q0;
		if(q0==1){
			cin>>q1>>q2>>q3;
			if((q1-1)/n+1==(q2-1)/n+1){
				seg0mdf(1,1,K,(q1-1)/n+1,(q1-1)%n+1,(q2-1)%n+1,q3);
			}
			else{
				seg0mdf(1,1,K,(q1-1)/n+1,(q1-1)%n+1,n,q3),seg0mdf(1,1,K,(q2-1)/n+1,1,(q2-1)%n+1,q3);
				seg0add(1,1,K,(q1-1)/n+2,(q2-1)/n,q3);
			}
		}else{
			cin>>q1>>q2;
			if((q1-1)/n+1==(q2-1)/n+1){
				ans=seg0srq(1,1,K,(q1-1)/n+1,(q1-1)%n+1,(q2-1)%n+1);
			}
			else{
				ans=min(seg0srq(1,1,K,(q1-1)/n+1,(q1-1)%n+1,n),seg0srq(1,1,K,(q2-1)/n+1,1,(q2-1)%n+1));
				ans=min(ans,seg0req(1,1,K,(q1-1)/n+2,(q2-1)/n));
			}
//			if(ans!=1)cout<<ans<<endl;
			cout<<ans<<endl;
		}
//		if(Q%1000==0)cout<<Q<<" "<<D-pool.size()<<endl;
	}
	
	return 0;
}
/*
4 3
1 3 2 4
10
1 5 5 5
2 2 7
1 8 10 2
2 5 10
1 7 8 4
2 4 8
1 4 7 3
2 7 9
1 4 4 1
2 3 11
*/