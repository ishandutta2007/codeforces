#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <map>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int main() {
	lli n;
	scanf("%lld",&n);
	n++;
	if(n==1) puts("0");
	else if(n%2==0) {
		printf("%lld\n",n/2);
	}
	else printf("%lld\n",n);
	return 0;
}