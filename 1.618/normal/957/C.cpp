#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;
typedef long long ll;
int n,U,e[maxn];
double ans = 0.0;
int main(){
	scanf("%d%d",&n,&U);
	for(int i=1;i<=n;i++){
		scanf("%d",&e[i]);
	}
	for(int i=1;i<=n-2;i++){
		int j = i+1, k = upper_bound(e+1,e+n+1,U + e[i]) - e - 1;
		if(k<=j) continue;
		ans = max(ans,1.0 * (e[k] - e[j]) / (e[k] - e[i]));
	}
	if(ans == 0.0) puts("-1");
	else printf("%.10lf",ans);
	return 0;
}