#include <bits/stdc++.h>

using namespace std;

int n, L;
double ans;
map< double, double> mt;
void add(double d, double v){
	mt[v] += d / (v + 1);
	if(v > 1)
		mt[v] += d / (v - 1);
	ans += d / (v + 1);
	double need = d / (v + 1);
	while(need > 1e-9){
		double  v = (*mt.rbegin()).first;
        double cnt = min(need, mt[v]);
		ans += cnt / v;
		mt[v] -= cnt;
		need -= cnt;
		if(mt[v] < 1e-9)
			mt.erase(v); 		
	}
}
int main()
{
	mt[1] = 1e18;
	scanf("%d%d", &n, &L);
	int last = 0;
	while(n--){
		int x, y;
		double s;
		scanf("%d%d%lf", &x, &y, &s);
		add(x - last, 1);
		add(y - x, s + 1);
		last = y;
	}
	add(L - last, 1);     
	printf("%.15f", ans);
	return 0;
}