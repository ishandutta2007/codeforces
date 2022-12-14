#include <bits/stdc++.h>
using namespace std;
const int N=200010; typedef long long ll;
ll a[N],d[N],e[N];
#define GG {puts("NO"); return;}
void solve(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		scanf("%lld",d+i);
	sort(d+1,d+n*2+1);
	for(int i=1;i<=n*2;i++){
		if(d[i]%2!=0)GG;
		if(i%2==1){
			if(d[i]!=d[i+1])GG;
			if(i!=1 && d[i]==d[i-2])GG;
		}
	}
	for(int i=1;i<=n;i++)e[i]=d[i*2]/2;
	ll sum=0;
	for(int i=n;i>=1;i--){
		if((e[i]-sum)%i!=0)GG;
		a[i]=(e[i]-sum)/i;
		sum+=a[i];
	}
	if(a[1]<=0)GG;
	puts("YES");
}
signed main(){
	int T; scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}