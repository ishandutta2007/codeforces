#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%.8lf\n", (double)1.0 / tan(pi / n / 2.0));
	}
	return 0;
}