#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,a[N],b[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=19;~i;--i){
		for(int j=1,c=0;j<=n;++j)
		if(a[j]&1<<i){
			b[++c]|=1<<i;
		}
	}
	ll ans=0; 
	for(int i=1;i<=n;++i)ans+=1ll*b[i]*b[i];
	printf("%lld\n",ans);
}