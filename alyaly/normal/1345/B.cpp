#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int T,n,ans,a[100001],pa;
signed main(){
	for(int i=1;i<=40000;i++) a[i]=3ll*i*i+i;
	cin>>T;
	while(T--){
		cin>>n;
		n*=2;
		ans=0;
		for(int i=40000;i>=1;i--){
			while(n>=a[i]){
				ans++;
				n-=a[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}