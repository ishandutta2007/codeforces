#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	double d, h, v, e;
	scanf("%lf %lf %lf %lf", &d, &h, &v, &e);
	double r = d / 2.0;
	double m = v/(pi * r * r) - e;
	if (m <= eps) printf("NO\n");
	else printf("YES\n%0.12lf\n", h/m);
	return 0;
}