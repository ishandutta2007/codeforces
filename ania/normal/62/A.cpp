#include<cstdio>
#include<algorithm>
using namespace std;

bool ok(int a, int b)
{
	if(a > b+1) return 0;
	if((b+1)/2 > a+1) return 0;
	return 1;
}

int main()
{
	int a1,a2,b1,b2;
	scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
	if(ok(a1,b2) || ok(a2,b1)) printf("YES\n");
	else printf("NO\n");
}