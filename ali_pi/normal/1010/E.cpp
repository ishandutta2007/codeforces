#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5,INF=1e9;

struct T{
	int l,r,d[3],mn[3],mx[3];
	}t[N];
	
int n,m,q,a,b,c,lx,rx,ly,ry,lz,rz,rt,h[N],D;

inline bool cmp(int a,int b){
	return t[a].d[D]<t[b].d[D];
	}
	
inline void update(int x){
	int l=t[x].l,r=t[x].r;
	for(int i=0;i<3;i++){
		t[x].mn[i]=t[x].mx[i]=t[x].d[i];
		if(l)
			t[x].mn[i]=min(t[x].mn[i],t[l].mn[i]),t[x].mx[i]=max(t[x].mx[i],t[l].mx[i]);
		if(r)
			t[x].mn[i]=min(t[x].mn[i],t[r].mn[i]),t[x].mx[i]=max(t[x].mx[i],t[r].mx[i]);
	}
}

void build(int&x,int l,int r,int k){
	if(l>r)
		return;
	int mid=(l+r)>>1;
	D=k;
	nth_element(h+l,h+mid,h+r+1,cmp);
	x=h[mid];
	build(t[x].l,l,mid-1,(k+1)%3);
	build(t[x].r,mid+1,r,(k+1)%3);
	update(x);
}

int query(int x,int x0,int x1,int y0,int y1,int z0,int z1){
	if(!x)
		return 0;
	if(x1<t[x].mn[0]||x0>t[x].mx[0]||y1<t[x].mn[1]||y0>t[x].mx[1]||z1<t[x].mn[2]||z0>t[x].mx[2])
		return 0;
	if(x0<=t[x].d[0]&&t[x].d[0]<=x1&&y0<=t[x].d[1]&&t[x].d[1]<=y1&&z0<=t[x].d[2]&&t[x].d[2]<=z1)
		return 1;
	return query(t[x].l,x0,x1,y0,y1,z0,z1)|query(t[x].r,x0,x1,y0,y1,z0,z1);
}

int main(){
	cin>>a>>b>>c>>n>>m>>q;
	lx=ly=lz=INF;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		lx=min(lx,x);
		ly=min(ly,y);
		lz=min(lz,z);
		rx=max(rx,x);
		ry=max(ry,y);
		rz=max(rz,z);
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>=lx&&x<=rx&&y>=ly&&y<=ry&&z>=lz&&z<=rz)
			return cout<<"INCORRECT",0;
		t[i].d[0]=x;t[i].d[1]=y;t[i].d[2]=z;
	}
	for(int i=1;i<=m;i++)
		h[i]=i;
	build(rt,1,m,0);
	cout<<"CORRECT"<<endl;
	while(q--){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>=lx&&x<=rx&&y>=ly&&y<=ry&&z>=lz&&z<=rz){
			cout<<"OPEN"<<endl;
			continue;
			}
		int x0=min(lx,x),x1=max(rx,x),y0=min(ly,y),y1=max(ry,y),z0=min(lz,z),z1=max(rz,z);
		if(query(rt,x0,x1,y0,y1,z0,z1))
			cout<<"CLOSED"<<endl;
		else 
			cout<<"UNKNOWN"<<endl;
	}
	return 0;
}