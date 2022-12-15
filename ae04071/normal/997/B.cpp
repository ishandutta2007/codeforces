#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <cmath>

#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const double PI=acos(-1);
const lli mod=1e9+7;

int a[12];
int main() {
a[1]=4;
a[2]=10;
a[3]=20;
a[4]=35;
a[5]=56;
a[6]=83;
a[7]=116;
a[8]=155;
a[9]=198;
a[10]=244;
a[11]=292;
	int n;
	lli ans=0;
	scanf("%d",&n);
	if(n<=11) printf("%d\n",a[n]);
	else {
		ans=a[11];
		ans += 1ll*49*(n-11);
		printf("%lld\n",ans);
	}
}