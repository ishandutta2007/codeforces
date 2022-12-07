#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 100005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n,l[maxn],r[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	ll ans = n;
	sort(l + 1,l + n + 1);
	sort(r + 1,r + n + 1);
	for(int i=1;i<=n;i++){
		ans += max(l[i],r[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}