#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N];
ll u,v;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld",&n,&u,&v);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		bool flag=1;
		for(int i=2;i<=n;++i)if(abs(a[i]-a[i-1])>1)flag=0;
		if(!flag){
			puts("0");
			continue;
		}
		flag=1;
		for(int i=2;i<=n;++i)if(a[i]!=a[i-1])flag=0;
		if(flag){
			printf("%lld\n",v+min(u,v));
		}
		else{
			printf("%lld\n",min(u,v));
		}
	}
}