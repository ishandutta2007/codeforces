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
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	int ans = 0;
	ans += (n * 2 + (k - 1)) / k;
	ans += (n * 5 + (k - 1)) / k;
	ans += (n * 8 + (k - 1)) / k;
	printf("%d\n",ans);
	return 0;
}