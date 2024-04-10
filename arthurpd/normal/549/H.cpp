#include <stdio.h>

double min(double a, double b) {return ((a < b) ? a : b);}
double max(double a, double b) {return ((a > b) ? a : b);}

double a, b, c, d;

bool foo(double x)
{
/*	|a - a2| <= x
	a - a2 <= x && a2 - a <= x
	-a2 <= x - a
	a2 >= a - x && a2 <= x + a
*/	
	double minl = min(min((a-x)*(d-x), (a-x)*(x+d)), min( (x+a)*(x+d), (x + a)*(d-x)));
	double maxl = max(max((x-a)*(x-d), -1*(x-a)*(x+d)), max( (x+a)*(x+d), (x + a)*(d-x)));
	
	double minr = min(min((x-b)*(x-c), -1*(x-b)*(x+c)), min( (x+b)*(x+c), -1*(x + b)*(x-c)));
	double maxr = max(max((x-b)*(x-c), -1*(x-b)*(x+c)), max( (x+b)*(x+c), -1*(x + b)*(x-c)));
	
	if(max(minl, minr) <= min(maxl, maxr))
		return true;
	return false;
}

int
main(void)
{
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	double bot = 0.0, top = 1e9, mid;
	while((top - bot) > 1e-11 && (top - bot)/top > 1e-11)
	{
//		printf("%lf %lf\n", bot, top);
		mid = (top+bot)/2;
		if(foo(mid))
			top = mid;
		else
			bot = mid;
	}
	printf("%.12lf\n", (bot+top)/2.0);
}