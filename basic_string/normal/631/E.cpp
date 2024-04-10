#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3,P=1e6+3; 
ll a[N],s[N],K[N],b[N],u,v;
int g[P*5],p;
#define f(i,j) (K[i]*(j)+b[i])
void upd(int k=1,int l=-P,int r=P){
	int m=l+r>>1;
	if(f(p,m)>f(g[k],m))swap(p,g[k]);
	if(l!=r)K[p]>K[g[k]]?upd(k*2+1,m+1,r):upd(k*2,l,m);
}
void qry(int k=1,int l=-P,int r=P){
	if(u=max(u,f(g[k],v)),l==r)return;
	int m=l+r>>1;
	v>m?qry(k*2+1,m+1,r):qry(k*2,l,m);
}
int main(){
	int n,i,j,t=0;
	ll o=0,w=0;
	cin>>n,b[0]=-1e18;
	for(i=1;i<=n;++i)cin>>a[i],s[i]=s[i-1]+a[i],o+=i*a[i];
	for(i=1;i<=n;++i)u=-1e18,v=a[i],qry(),w=max(w,u+s[i-1]-a[i]*i),K[++t]=i,b[p=t]=-s[i-1],upd();
	memset(g,t=0,sizeof(g));
	for(i=n;i;--i)u=-1e18,v=a[i],qry(),w=max(w,u+s[i]-a[i]*i),K[++t]=i,b[p=t]=-s[i],upd();
	cout<<w+o;
	return 0;
}