#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

int n;
int main() {
	scanf("%d",&n);
	if(n<=2) puts("No");
	else if(n%2==1) {
		printf("Yes\n");
		printf("%d ",n-1);
		for(int i=1;i<=n-1;i++) printf("%d ",i);
		puts("");
		printf("%d %d\n",1,n);
	} else {
		puts("Yes");
		printf("%d ",n/2);
		for(int i=1;i<=n/2;i++) printf("%d ",i*2-1);
		printf("\n%d ",n/2);
		for(int i=1;i<=n/2;i++) printf("%d ",i*2);
	}
	return 0;
}