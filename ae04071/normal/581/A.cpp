#include <bits/stdc++.h>
using namespace std;

int a,b;
int main() {
	scanf("%d%d",&a,&b);
	printf("%d %d",min(a,b),(max(a,b)-min(a,b))/2);

	return 0;
}