#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100015
using namespace std;
typedef long long ll;
int n,a[maxn],m,pre_sumlit[maxn],pre_sumoff[maxn],sumlit[maxn],sumoff[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = 0;
	a[n+1] = m;
	for(int i=n+1;i>=1;i--){
		a[i] = a[i] - a[i-1];
	}
	for(int i=n+1;i>=1;i--){
		sumlit[i] = sumlit[i+1];
		sumoff[i] = sumoff[i+1];
		if(i & 1) sumlit[i] += a[i];
		else sumoff[i] += a[i];
	}
	int ans = sumlit[1];
	for(int i=1;i<=n+1;i++){
		pre_sumlit[i] = pre_sumlit[i-1];
		pre_sumoff[i] = pre_sumoff[i-1];
		if(i & 1) pre_sumlit[i] += a[i];
		else pre_sumoff[i] += a[i];
	}
	for(int i=1;i<=n+1;i+=2){
		if(a[i] > 1){
			ans = max(ans,pre_sumlit[i] + sumoff[i+1] - 1);
		}
	}
	for(int i=2;i<=n+1;i+=2){
		if(a[i] > 1){
			ans = max(ans,pre_sumlit[i] + sumoff[i+1] +(a[i]-1));
		}
	}
	printf("%d\n",ans);
	return 0;
}