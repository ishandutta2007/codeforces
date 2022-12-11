#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int p1,p2,p3,p4,a,b;
	scanf("%d%d%d%d%d%d", &p1, &p2, &p3, &p4, &a, &b);
	if(p1>p2) p1=p2;
	if(p1>p3) p1=p3;
	if(p1>p4) p1=p4;
	if(p1 > b+1) p1 = b+1;
	if(a > p1) printf("0\n");
	else printf("%d\n", p1-a);
}