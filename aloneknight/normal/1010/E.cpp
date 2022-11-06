#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=16000005;
int mx,my,mz,n,m,k,lx,rx,ly,ry,lz,rz,cnt,lc[M],rc[M],lv[M],rv[M],rt[N<<2];
bool in(int x,int y,int z){return lx<=x&&x<=rx&&ly<=y&&y<=ry&&lz<=z&&z<=rz;}
void upd(int &o,int l,int r,int y,int z)
{
	if(!o)o=++cnt,rv[o]=mz+1;
	if(lz<=z)rv[o]=min(rv[o],z);
	if(z<=rz)lv[o]=max(lv[o],z);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(y<=mid)upd(lc[o],l,mid,y,z);else upd(rc[o],mid+1,r,y,z);
}
void chg(int o,int l,int r,int x,int y,int z)
{
	upd(rt[o],1,my,y,z);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)chg(o<<1,l,mid,x,y,z);else chg(o<<1|1,mid+1,r,x,y,z);
}
bool gtans(int o,int l,int r,int yl,int yr,int zl,int zr)
{
	if(!o)return 1;
	if(yl<=l&&r<=yr)return lv[o]<zl&&zr<rv[o];
	bool res=1;
	int mid=(l+r)>>1;
	if(yl<=mid)res&=gtans(lc[o],l,mid,yl,yr,zl,zr);
	if(yr>mid)res&=gtans(rc[o],mid+1,r,yl,yr,zl,zr);
	return res;
}
inline bool qry(int o,int l,int r,int xl,int xr,int yl,int yr,int zl,int zr)
{
	if(xl<=l&&r<=xr)return gtans(rt[o],1,my,yl,yr,zl,zr);
	bool res=1;
	int mid=(l+r)>>1;
	if(xl<=mid)res&=qry(o<<1,l,mid,xl,xr,yl,yr,zl,zr);
	if(xr>mid)res&=qry(o<<1|1,mid+1,r,xl,xr,yl,yr,zl,zr);
	return res;
}
inline void sol(int x,int y,int z)
{
	if(in(x,y,z))puts("OPEN");
	else if(qry(1,1,mx,min(lx,x),max(rx,x),min(ly,y),max(ry,y),min(lz,z),max(rz,z)))puts("UNKNOWN");
	else puts("CLOSED");
}
int main()
{
	scanf("%d%d%d%d%d%d",&mx,&my,&mz,&n,&m,&k);lx=mx,ly=my,lz=mz;
	for(int i=1,x,y,z;i<=n;i++){scanf("%d%d%d",&x,&y,&z);lx=min(lx,x),rx=max(rx,x);ly=min(ly,y),ry=max(ry,y);lz=min(lz,z),rz=max(rz,z);}
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(in(x,y,z)){puts("INCORRECT");return 0;}
		chg(1,1,mx,x,y,z);
	}
	puts("CORRECT");
	for(int i=1,x,y,z;i<=k;++i)scanf("%d%d%d",&x,&y,&z),sol(x,y,z);
	return 0;
}