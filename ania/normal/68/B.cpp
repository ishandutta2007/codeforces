#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
int t[100100];

bool ok(double x)
{
	double H = 0, L = 0;
	for(int i = 0; i < n; i++)
		if(t[i] > x) H += 0.0 + t[i] - x;
		else L += x - t[i];
	return .01 * (100-k) * H >= L;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	double low = 0, high = 1e4;
	for(int qq = 0; qq < 50; qq++)
	{
		double mid = (low+high) / 2;
		if(ok(mid)) low = mid;
		else high = mid;
	}
	printf("%.8lf\n", low);
}