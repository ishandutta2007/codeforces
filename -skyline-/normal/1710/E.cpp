#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int n,m,a[200005],b[200005],x,y;
int _x[200005],_y[200005];
ll sx[200005];

ll sol(int r,int c){
	if(_x[r]<c) return _y[c]*1ll*c+(sx[r]-sx[_y[c]])+(n-r)*1ll*(m-c);
	return r*1ll*c+(_y[c]-r)*1ll*m-(sx[_y[c]]-sx[r])+(n-_y[c])*1ll*(m-c);
}
ll sol2(int r,int c){
	ll o=0;
	if(_x[r]<c){
		if(x>r&&y>c)o=1;
		if(x<=r&&y<=c&&y<=_x[x])o=1;
		return _y[c]*1ll*c+(sx[r]-sx[_y[c]])+(n-r)*1ll*(m-c)-o;
	}
	if(x<=r&&y<=c)o=1;
	if(x>r&&y>c&&y>_x[x])o=1;
	return r*1ll*c+(_y[c]-r)*1ll*m-(sx[_y[c]]-sx[r])+(n-_y[c])*1ll*(m-c)-o;
}
bool ok(int k){
	ll res1=0,res2=0;
	_x[0]=m;
	for(int i=1;i<=n;++i){
		int j=_x[i-1];
		while(j&&a[i]+b[j]>k)--j;
		_x[i]=j;
		sx[i]=sx[i-1]+j;
	}
	_y[0]=n;
	for(int i=1;i<=m;++i){
		int j=_y[i-1];
		while(j&&a[j]+b[i]>k)--j;
		_y[i]=j;
	}
	res1=max(sx[n],n*1ll*m-sx[n]);
	res2=max(sx[n],n*1ll*m-sx[n]-1);
	int j=1;
	for(int i=1;i<=n;++i){
		while(j<m&&sol(i,j)<=sol(i,j+1))++j;
		res1=max(res1,sol(i,j));
	}
	j=1;
	for(int i=1;i<=n;++i){
		while(j<m&&sol2(i,j)<=sol2(i,j+1))++j;
		res2=max(res2,sol2(i,j));
	}
	return res1!=(res2+1ll);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=m;++i)scanf("%d",b+i);
	x=a[1],y=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;++i){
		if(x==a[i]){
			x=i;
			break;
		}
	}
	for(int i=1;i<=m;++i){
		if(y==b[i]){
			y=i;
			break;
		}
	}
	int l=0,r=a[x]+b[y];
	
	while(r-l>1){
		int mi=l+(r-l)/2;
		if(ok(mi))r=mi;
		else l=mi;
	}
	printf("%d\n",r);
    return 0;
}