#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e3+5;
void cmax(ll &x,ll y){x=x>y?x:y;}
ll n,m,a[N],vis[N],f[N][N];
int solve(int l,int r){
	if(l>r)return 0;
	int p=l; for(int i=l;i<=r;i++)if(a[i]<a[p])p=i;
	int ls=solve(l,p-1),rs=solve(p+1,r);
	for(int i=0;i<=r-l+1;i++)f[p][i]=-1e18;
	for(int i=0;i<=p-l;i++)for(int j=0;j<=r-p;j++)
		cmax(f[p][i+j],f[ls][i]+f[rs][j]-i*j*2*a[p]),
		cmax(f[p][i+j+1],f[ls][i]+f[rs][j]-(i*j*2+i*2+j*2+1-m)*a[p]);
	return p;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int r=solve(1,n);cout<<f[r][m]<<endl;
	return 0;
}