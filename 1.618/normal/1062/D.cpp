#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main(){
	scanf("%d",&n);
	ll ans = 0;
	for(int i=2;i<=n;i++){
		for(int j=2;i * j <= n;j++) ans += 4 * j;
	}
	printf("%I64d\n",ans);
	return 0;
}