#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
struct M{
	double a[3][3];
	M(){memset(a,0,sizeof a);}
	M operator*(M b){
		M c;
		for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k)
		c.a[i][k]=max(c.a[i][k],a[i][j]+b.a[j][k]);
		return c;
	}
};
int u,v,n,b[N],x,y;
M get(int v){
	M a;
	a.a[0][0]=a.a[1][0]=a.a[2][0]=0;
	a.a[0][1]=a.a[1][1]=v*1./(x+y),a.a[2][1]=-1e18;
	a.a[0][2]=v*1./y,a.a[1][2]=a.a[2][2]=-1e18;
	return a;
}
double a[3];
M s[N*4];
void bd(int k,int l,int r){
	if(l==r){s[k]=get(b[l]);return;}
	int m=(l+r)>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),s[k]=s[k*2]*s[k*2+1];
}
void upd(int k,int l,int r){
	if(l==r){s[k]=get(v);return;}
	int m=(l+r)>>1;
	u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),s[k]=s[k*2]*s[k*2+1];
}
void qry(int k,int l,int r){
	if(u<=l&&r<=v){
		double b[3]={};
		for(int i=0;i<3;++i)for(int j=0;j<3;++j)b[j]=max(b[j],a[i]+s[k].a[i][j]);
		a[0]=b[0],a[1]=b[1],a[2]=b[2];return;
	}
	int m=(l+r)>>1;
	if(u<=m)qry(k*2,l,m);
	if(m<v)qry(k*2+1,m+1,r);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,q;cout<<fixed<<setprecision(12);
	cin>>n>>q>>x>>y;
	if(x>y)swap(x,y);
	for(i=1;i<=n;++i)cin>>b[i];
	bd(1,1,n);
	while(q--)if(cin>>i>>u>>v,i==1)upd(1,1,n);else{
		a[0]=a[1]=a[2]=0;
		qry(1,1,n);
		cout<<max(a[0],max(a[1],a[2]))<<'\n';
	}
}