#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
#define eps 1e-9
std :: map<double, double> M;
int n;
double L, ans;
void insert(double d, double v){
	double need_e = d / (v + 1);
	ans += need_e;
	M[v] += need_e + (v > 1 ? d / (v - 1) : 0);
	while (need_e >= eps){
		double x = M.rbegin() -> first, delta_e = std :: min(M[x], need_e);
		M[x] -= delta_e, need_e -= delta_e, ans += delta_e / x;
		if (M[x] < eps) M.erase(x);
	}
}
int main(){
	scanf("%d%lf", &n, &L);
	double lst = 0;
	for (register int i = 1; i <= n; ++i){
		double x, y, s;
		scanf("%lf%lf%lf", &x, &y, &s);
		insert(x - lst, 1), insert(y - x, s + 1), lst = y;
	}
	insert(L - lst, 1);
	printf("%.15lf\n", ans);
}