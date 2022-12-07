#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
#define inf 1000000000005ll
using namespace std;
typedef long long ll;
int maxi,n,m,k,s[maxn],a[maxn];
bool bl[maxn];
ll ans = inf;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int b;
		scanf("%d",&b);
		bl[b] = true;
	}
	for(int i=0;i<n;i++){
		if(bl[i]) s[i] = s[i-1] + 1;
		else s[i] = 0;
		maxi = max(maxi,s[i]);
	}
	for(int i=1;i<=k;i++) scanf("%d",&a[i]);
	if(bl[0] || k <= maxi){
		puts("-1");
		return 0;
	}
	for(int i=maxi + 1;i<=k;i++){
		ll res = 0;
		int j = 0;
		while(j < n){
			res++;
			j = j + i;
			if(j >= n) break;
			j -= s[j];
		}
		ans = min(ans,res * a[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}