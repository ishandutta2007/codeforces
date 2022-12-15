#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <ctype.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int main() {
	lli a,b;
	scanf("%lld%lld",&a,&b);

	lli s = max(1ll,b-a),e=min(a,b-1ll);
	if(b-s==s) s++;
	if(b-e==e) e--;

	lli ans = max(0ll,(e-s+1)/2);

	printf("%lld\n",max(0ll,(e-s+1)/2));


	return 0;
}