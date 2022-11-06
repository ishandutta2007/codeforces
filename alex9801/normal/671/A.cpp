#include <stdio.h>
#include <algorithm>
#include <math.h>

struct str
{
	double d;
	int i;
	str(double ad = 0.0, int ai = 0) : d(ad), i(ai) {}
	bool operator <(const str &a) const
	{
		return d < a.d;
	}
};

int arr[100000][2];
str sor1[100000];
str sor2[100000];
double p[100000];

double dis(int x1, int y1, int x2, int y2)
{
	return sqrt(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2));
}

int main()
{
	int n, a, b, c, d, e, f, i;
	double r;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &n);
	for(i = 0; i<n; i++)
		scanf("%d%d", &arr[i][0], &arr[i][1]);

	for(i = 0; i<n; i++)
		p[i] = dis(e, f, arr[i][0], arr[i][1]);

	for(i = 0; i<n; i++)
	{
		sor1[i] = str(dis(a, b, arr[i][0], arr[i][1]) - p[i], i);
		sor2[i] = str(dis(c, d, arr[i][0], arr[i][1]) - p[i], i);
	}
	std::sort(sor1, sor1+n);
	std::sort(sor2, sor2+n);

	if(n==1)
		r = std::min(sor1[0].d, sor2[0].d);
	else if(sor1[0].i != sor2[0].i)
		r = std::min({sor1[0].d, sor2[0].d, sor1[0].d + sor2[0].d});
	else
		r = std::min({sor1[0].d, sor2[0].d, sor1[0].d+sor2[1].d, sor1[1].d+sor2[0].d});

	for(i = 0; i<n; i++)
		r += 2*p[i];

	printf("%.10lf", r);
	return 0;
}