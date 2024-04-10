#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 200005
using namespace std;
typedef long long ll;
int n,a[maxn],k,ans;
bool dis[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int he = n;
	for(int i=n-1;i>=1;i--){
		if(a[i+1] - a[i] > 0 && a[i+1] - a[i] <= k){
			ans++;
			dis[i] = true;
		}else if(a[i+1] == a[i]){
			if(dis[i+1]){
				ans++;
				dis[i] = true;
			}
		}
	}
	printf("%d\n",n - ans);
	return 0;
}