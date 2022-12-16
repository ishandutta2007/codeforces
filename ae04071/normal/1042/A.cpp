#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m,a[100];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	int lo=(*max_element(a,a+n))-1,up=100000;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		long long sum=0;
		for(int i=0;i<n;i++) sum += md-a[i];
		if(sum >= m) up=md;
		else lo=md;
	}
	printf("%d %d\n",up,(*max_element(a,a+n))+m);

	return 0;
}