#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 300015
using namespace std;
typedef long long ll;
int n,a[maxn],b[maxn];
ll suma[maxn],sumb[maxn],suma2[maxn],sumb2[maxn],suma3[maxn],sumb3[maxn];
ll calca(int x){//premove in the other row.
	int premove = x - 1;
	ll ap = premove * (suma[n] - suma[x-1]) + suma2[n] - suma2[x-1];
	ll bp = (n + premove) * (sumb[n] - sumb[x-1]) + sumb3[x];
	return ap + bp;
}
ll calcb(int x){
	int premove = x - 1;
	ll bp = premove * (sumb[n] - sumb[x-1]) + sumb2[n] - sumb2[x-1];
	ll ap = (n + premove) * (suma[n] - suma[x-1]) + suma3[x];
	return ap + bp;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		suma[i] = suma[i-1] + a[i];
		suma2[i] = suma2[i-1] + (ll)i * a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sumb[i] = sumb[i-1] + b[i];
		sumb2[i] = sumb2[i-1] + (ll)i * b[i];
	}
	for(int i=n;i>=1;i--){
		suma3[i] = suma3[i+1] + (ll)(n-i+1) * a[i];
		sumb3[i] = sumb3[i+1] + (ll)(n-i+1) * b[i];
	}
	ll ans = calca(1);
	ll res = 0;
	for(int i=1;i<=n;i++){
		if(i & 1){
			ll x1 = i * 2;
			res += (x1 - 1) * a[i] + x1 * b[i];
			ans = max(ans,calcb(i+1) + res);
		}else{
			ll x1 = i * 2;
			res += (x1 - 1) * b[i] + x1 * a[i];
			ans = max(ans,calca(i+1) + res);
		}
	}
	printf("%I64d\n",ans - suma[n] - sumb[n]);
	return 0;
}