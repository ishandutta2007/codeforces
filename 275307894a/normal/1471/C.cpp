#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=3e5+10;
int n,m,a[N],b[N];
int get(){
	ll ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	for(int i=n,j=1;i>=1;i--){
		if(a[i]>=j)ans+=b[j++];
		else ans+=b[a[i]];
	}
	printf("%lld\n",ans);
	return 0;
}
int main(){
	int T;scanf("%d",&T);
	while(--T)get();
	return get();
}