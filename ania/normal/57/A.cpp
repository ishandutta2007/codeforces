#include<cstdio>
#include<algorithm>
using namespace std;

int go(int a, int b, int c, int d, int e)
{
	if(b == a) return go(a,0,c,a-d,e);
	if(c == a) return go(a,b,0,d,a-e);
	if(b != 0) return go(a,c,b,e,d);
	if(d == a) return a + min(c+e, 2*a-c-e);
	if(d == 0) return abs(c-e);
	if(e == 0) return d+c;
	if(e == a) return d+a-c;
}

int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
	printf("%d\n", go(a,b,c,d,e));
}