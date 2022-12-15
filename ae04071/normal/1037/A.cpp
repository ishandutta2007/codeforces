#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int n,c=0;
	scanf("%d",&n);

	while(n) c++,n>>=1;
	printf("%d\n",c);

	return 0;
}