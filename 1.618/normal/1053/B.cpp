#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 300005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[maxn],sum[maxn];
ll evnum,odnum;
int main(){
	scanf("%d",&n);
	evnum++;
	a[0] = sum[0] = 0;
	for(int i=1;i<=n;i++){
		ll tmp;
		scanf("%I64d",&tmp);
		int t = 0;
		while(tmp){
			t += (tmp & 1);
			tmp >>= 1;
		}
		a[i] = t;
		sum[i] = sum[i - 1] + t;
		if(sum[i] & 1) odnum++;
		else evnum++;
	}
	ll ans = 0;
	ans += evnum * (evnum - 1) / 2;
	ans += odnum * (odnum - 1) / 2;
	for(int i=1;i<=n;i++){
		int maxi = a[i];
		for(int j=i-1;j>=0;j--){
			if(sum[i] - sum[j] >= 140) break;
			if(sum[i] % 2 == sum[j] % 2 && sum[i] - sum[j] < 2 * maxi) ans--;
			maxi = max(maxi,a[j]);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}