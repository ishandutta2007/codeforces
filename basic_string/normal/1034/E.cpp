#include<bits/stdc++.h>
using namespace std;
const int N=1<<21|1;
int n,p[N];
long long a[N],b[N],c[N];
char s[N],t[N];
void OR(long long*a){////
	int i,j,u,v,l,t;///////
	for(i=2;i<=n;i<<=1)
	for(j=0,t=i>>1;j<n;j+=i)
	for(u=j,v=l=j+t;u<l;++u,++v)a[v]+=a[u];
}
void IOR(long long*a){////
	int i,j,u,v,l,t;
	for(i=2;i<=n;i<<=1)
	for(j=0,t=i>>1;j<n;j+=i)
	for(u=j,v=l=j+t;u<l;++u,++v)a[v]-=a[u];
}
int main(){
	int m,i;
	scanf("%d%s%s",&m,s,t),n=1<<m;
	for(i=1;i<n;++i)p[i]=p[i-(i&-i)]+2;
	for(i=0;i<n;++i)a[i]=(s[i]-48ll)<<p[i],b[i]=(t[i]-48ll)<<p[i];
	OR(a),OR(b);
	for(i=0;i<n;++i)c[i]=a[i]*b[i];
	IOR(c);
	for(i=0;i<n;++i)putchar(c[i]>>p[i]&3|48);
	return 0;
}////////////////////////////////////////////////