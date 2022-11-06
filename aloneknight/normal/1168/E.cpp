#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i) 
const int N=5005;
int n,s,a[N],t[N],p[N],q[N],ps[N];
void upd(int i,int j)
{
	int k=ps[t[i]^q[i]];if(k==i)return;
	if(k==j){swap(ps[p[i]],ps[p[j]]);swap(p[i],p[j]);return;}
	swap(ps[p[i]],ps[p[k]]);swap(p[i],p[k]);
	swap(q[j],q[k]);upd(k,j);
}
int main()
{
	scanf("%d",&n);n=1<<n;
	rep(i,0,n-1)scanf("%d",&a[i]),p[i]=q[i]=ps[i]=i,s^=a[i];
	if(s){puts("Fou");return 0;}
	rep(i,0,n-1)if(a[i]!=t[i]){int dt=a[i]^t[i];t[i]^=dt;t[i+1]^=dt;upd(i,i+1);}
	puts("Shi");
	rep(i,0,n-1)printf("%d ",p[i]);puts("");
	rep(i,0,n-1)printf("%d ",q[i]);puts("");
	return 0;
}