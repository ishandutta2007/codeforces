#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
using ll=long long;
int f[N],g[N],s[3],t[2],u[N],v[N];
ll a[N];
void gm(int&x,int y){if(x>y)x=y;}
int main(){
	int*p=u,*q=v,n,i,j,k;
	ll w=0;
	for(scanf("%d",&n),memset(g+1,9,n*4),i=1;i<=n;++i)scanf("%lld",a+i),w=max(w,a[i]);
	for(i=1;i<=n;++i)a[i]=w-a[i],q[i]=i;
	for(j=0;j<60;++j,swap(p,q),memcpy(g,f,n*4+4)){
		for(i=1,memset(f,9,n*4+4),s[0]=s[1]=s[2]=0;i<=n;++i)++s[a[i]>>j&1];
		for(i=t[0]=n,t[1]=s[1];i;--i)p[t[a[q[i]]>>j&1]--]=q[i];
		for(i=0;i<=n;++i){
			if(i)k=a[q[i]]>>j&1,--s[k],++s[k+1];
			gm(f[s[2]],g[i]+s[1]),gm(f[s[1]+s[2]],g[i]+s[0]+s[2]);
		}
	}
	printf("%d",g[0]);
	return 0;
}