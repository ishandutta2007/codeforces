#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=3e5+10,M=1e6+10;
int n,a[N],cnt[M],maxx,tot,tot1;
ll x;
int get(){
	maxx=tot=0;
	int T;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=2;j*j<=a[i];j++)while(a[i]%j==0&&a[i]/j%j==0)a[i]/=j*j;
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++)maxx=max(maxx,cnt[a[i]]);
	for(int i=1;i<=n;cnt[a[i]]=0,i++)if(cnt[a[i]]%2==0||a[i]==1)tot+=cnt[a[i]];
	tot=max(tot,maxx);
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&x);
		if(x==0)printf("%d\n",maxx);
		else printf("%d\n",tot);
	}
	return 0;
}
int main(){
	if(fopen("1.in","r"))freopen("1.in","r",stdin);
	int T;scanf("%d",&T);
	while(--T)get();
	return get();
}