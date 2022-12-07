#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>

using namespace std;
typedef long long ll;
int t,n,k,a[205];
int main(){
//	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int maxans = 0;
		for(int i=1;i<=k;i++) scanf("%d",&a[i]);
		maxans = max(a[1],n-a[k]+1);
		for(int i=2;i<=k;i++){
			maxans = max(maxans,(a[i]-a[i-1]+2)/2);
		}
		printf("%d\n",maxans);
	}
	return 0;
}