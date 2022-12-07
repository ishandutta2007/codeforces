//Will it FST?
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
int n,m;
ll a[maxn],b[maxn],sumb;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		a[i] = a[i - 1] + a[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%I64d",&b[i]);
		sumb += b[i];
	}
	if(sumb != a[n]){
		puts("-1");
		return 0;
	}
	int p = 0,q = 0;
	int ans = 0;
	while(q < m){
		ll sum = 0;
		while(q < m){
			q++;
			sum += b[q];
			int pos = lower_bound(a + p + 1,a + n + 1,sum + a[p]) - a;
			if(pos <= n && a[pos] - a[p] == sum){
				ans++;
				p = pos;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}