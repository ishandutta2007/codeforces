#include<cstdio>
#include<algorithm>
#define N 200039
#include<map>
#define ll long long
using namespace std;
int T,n,m,k,x,y,z,flag;ll a[N],d[N],ans;
map<ll,int> g;
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);flag=ans=0;g.clear();for(i=1;i<=2*n;i++) scanf("%lld",&a[i]),g[a[i]]++;sort(a+1,a+2*n+1);
		for(i=1;i<=2*n;i++) if(g[a[i]]^2||a[i]&1){flag=1;break;}
		for(i=3;i<=2*n;i+=2){
			if((a[i]-a[i-2])%(2*(i/2))) {flag=1;break;}
			d[i]=(a[i]-a[i-2])/(2*(i/2));
		}
		for(i=3;i<=2*n;i+=2) ans+=d[i]*(n-i/2)*2;if(ans>=a[1]||(a[1]-ans)%(2*n))flag=1;
		printf("%s\n",flag?"NO":"YES");
	}
}