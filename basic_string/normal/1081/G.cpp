#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[2],c[2],p,iv[N],s[N];
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;return r;}
void wk(int l,int r,int k){
	if(l==r||k==1){if(!a[0]||a[0]==r-l+1)a[0]=r-l+1,++c[0];else a[1]=r-l+1,++c[1];return;}
	int m=l+r>>1;
	wk(l,m,k-1),wk(m+1,r,k-1);
}
int get(int x,int y){
	int w=x*1ll*y%p*iv[2]%p,i;
	for(i=1;i<=x;++i)w=(w+s[i]-s[i+y])%p;
	return w;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,k,i,j;
	cin>>n>>k>>p,wk(1,n,k);
	for(i=1,j=min(max(n,4),max(a[0],a[1])*2);i<=j;++i)iv[i]=qp(i,p-2),s[i]=(s[i-1]+iv[i])%p;
	for(i=j=0;i<2;++i)if(a[i])j=(j+a[i]*(a[i]-1ll)%p*iv[4]%p*c[i]+c[i]*(c[i]-1ll)/2%p*get(a[i],a[i]))%p;
	if(a[1])j=(j+c[0]*1ll*c[1]%p*get(a[0],a[1]))%p;
	cout<<(j+p)%p;
	return 0;
}