# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int d;
double a, b;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &d);
		if (d * d - 4 * d < 0){
			printf("N\n");
			continue;
		}
		a = (d + sqrt(double(d * d - 4 * d))) / 2.0;
		b = d - a;
		printf("Y %.10lf %.10lf\n", a, b);
	}
	return 0;
}