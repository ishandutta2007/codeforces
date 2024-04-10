#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
ll pre[maxn];
double ans;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ans=INT_MIN;
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(ri i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
		for(ri i=1;i<n;++i)ckmax(ans,(double)pre[i]/i+(double)(pre[n]-pre[i])/(n-i));
		printf("%.9lf\n",ans);
	}
	return 0;
}