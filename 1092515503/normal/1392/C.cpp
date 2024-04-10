#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100],mx;
typedef long long ll;
ll res;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mx=res=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<=a[i-1])res+=a[i-1]-a[i];
		}
		printf("%I64d\n",res);
	}
	return 0;
}