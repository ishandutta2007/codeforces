#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,a[20];
ll res;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),m=0,res=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			while(!(a[i]&1))a[i]>>=1,m++;
		}
		sort(a+1,a+n+1);
		res=a[n],res<<=m;
		for(int i=1;i<n;i++)res+=a[i];
		printf("%lld\n",res);
	}
	return 0;
}