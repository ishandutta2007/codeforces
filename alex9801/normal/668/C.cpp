#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

double arr[100000][2];
double res[100000][2];

inline double ab(double x)
{
	return x<0 ? -x : x;
}

inline double val(double x)
{
	if(x<0)
		return 0;
	if(x>1)
		return 1;
	return x;
}

inline double dif(double x)
{
	if(x<0)
		return -x;
	if(x>1)
		return x-1;
	return 0;
}

int main()
{
	int n, i;
	double s1 = 0, s2 = 0, c, e, b, t, p1, p2, d1, d2;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%lf", &arr[i][0]);
	for(i = 0; i<n; i++)
		scanf("%lf", &arr[i][1]);

	for(i = 0; i<n-1; i++)
	{
		c = arr[i][0]+arr[i][1];
		e = arr[i][0];

		b = (s2-s1-c);

		t = sqrt(std::max(b*b-4*(e-c*s2), 0.0));

		p1 = (-b+t)/2;
		p2 = (-b-t)/2;

		d1 = dif(p1)+dif(c-p1)+dif(s2+p1)+dif(s1+c-p1);
		d2 = dif(p2)+dif(c-p2)+dif(s2+p2)+dif(s1+c-p2);

		if(d1<=d2)
			res[i][0] = p1;
		else
			res[i][0] = p2;
		res[i][1] = c - res[i][0];

		res[i][0] = val(res[i][0]);
		res[i][1] = val(res[i][1]);

		s1 += res[i][1];
		s2 += res[i][0];
	}

	res[n-1][0] = 1-s2;
	res[n-1][1] = 1-s1;

	for(i = 0; i<n; i++)
		printf("%.10lf ", res[i][0]);
	printf("\n");
	for(i = 0; i<n; i++)
		printf("%.10lf ", res[i][1]);
}