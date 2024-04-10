#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,a[100000],b[100000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%1d",&a[i]);
	for(int i=0;i<n;i++) scanf("%1d",&b[i]);

	int zz=0,zo=0,oz=0,oo=0;
	for(int i=0;i<n;i++) {
		if(a[i]==0) {
			if(b[i]==0) zz++;
			else zo++;
		} else {
			if(b[i]==0) oz++;
			else oo++;
		}
	}
	printf("%lld\n",1ll*zz*oo + 1ll*oz*zo + 1ll*oz*zz);
	return 0;
}