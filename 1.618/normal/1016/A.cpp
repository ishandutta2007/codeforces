#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
ll n,m,a[maxn],sum,ans[maxn];
int main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum += a[i];
		ans[i] = sum / m;
	}
	for(int i=1;i<=n;i++){
		printf("%I64d",ans[i] - ans[i-1]);
		if(i == n) printf("\n");
		else printf(" ");
	}
	return 0;
}