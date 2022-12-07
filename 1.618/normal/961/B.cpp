#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,k,a[maxn],t[maxn],sum[maxn],suma[maxn],tot;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		if(t[i]) tot += a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + a[i]*t[i];
		suma[i] = suma[i-1] + a[i];
	}
	int ma = 0;
	for(int i=1;i<=n-k+1;i++){
		int j = i+k-1;
		ma = max(ma,tot+(suma[j]-suma[i-1])-(sum[j]-sum[i-1]));
	}
	printf("%d\n",ma);
	return 0;
}