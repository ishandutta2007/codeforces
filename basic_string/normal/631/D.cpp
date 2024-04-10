#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ic=pair<long long,char>;
enum{N=200009};
ic a[N],bb[N],*b=bb+1;
int z[N];
void in(int&n,ic*a){
	int i,x,t=0;
	char c;
	for(i=1;i<=n;++i)if(cin>>x>>c,cin>>c,c==a[t].se)a[t].fi+=x;else a[++t]={x,c};
	n=t;
}
bool eq(const ic&a,const ic&b){return a.fi==b.fi&&a.se==b.se;}
bool lq(const ic&a,const ic&b){return a.se==b.se&&a.fi<=b.fi;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,l,r,s=0,p;
	cin>>n>>m,in(n,a),in(m,bb),a[n+1].se=1;
	if(m==1){
		long long s=0;
		for(i=1;i<=n;++i)if(lq(bb[1],a[i]))s+=a[i].fi-bb[1].fi+1;
		return cout<<s,0;
	}
	if(m==2){
		for(i=1;i<n;++i)if(lq(bb[1],a[i])&&lq(bb[2],a[i+1]))++s;
		return cout<<s,0;
	}
	for(z[1]=(m-=2),l=r=0,i=2;i<m;++i){
		if(i<=r)z[i]=min(z[i-l+1],r-i+1);
		for(;eq(b[i+z[i]],b[z[i]+1]);++z[i]);
		if(i+z[i]-1>r)r=i+z[i]-1,l=i;
	}
	for(i=2,l=r=0;i<n;++i){
		if(i<=r)p=min(z[i-l+1],r-i+1);else p=0;
		for(;eq(a[i+p],b[p+1]);++p);
		if(i+p-1>r)r=i+p-1,l=i;
		if(p>=m&&lq(b[0],a[i-1])&&lq(b[m+1],a[i+m]))++s;
	}cout<<s;
	return 0;
}