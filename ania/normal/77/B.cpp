#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,t;

double f(double x)
{
	return x - x*x*2/a;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		if(a == 0 && b == 0) printf("1.000000\n");
		else if(a == 0) printf("0.5000000\n");
		else if(b == 0) printf("1.0000000\n");
		else printf("%.8lf\n", 0.5 + 0.5 * f(min(1.0*b,0.25*a)) / b);
	}
}