#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

int n, w, v, u;
PII P[10009];

int main(){
	scanf("%d %d %d %d", &n, &w, &v, &u);
	bool czy = true;
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &P[i].st, &P[i].nd);
		if(1LL * P[i].st * u < 1LL * P[i].nd * v)
			czy = false;
	}
	
	if(czy){
		printf("%.7lf\n", 1.0 * (double)w / (double)u);
		return 0;
	}
	
	int mn = 1;
	for(int i = 2; i <= n; ++i)
		if(P[i].nd < P[mn].nd)
			mn = i;
	
	double ans = (1.0 * P[mn].st) / (1.0 * v);
	double now_y = min((1.0 * u) * ans, 1.0 * P[mn].nd);
	for(int i = mn + 1; true; ++i){
		if(i > n)
			i = 1;
		double t = (1.0 * P[i].st) / (1.0 * v);
		if(t < ans)
			break;
		now_y = min(now_y + (t - ans) * (1.0 * u), 1.0 * P[i].nd);
		ans = t;
	}
	
	ans += ((1.0 * w) - now_y) / (1.0 * u);
	printf("%.7lf\n", ans);
	return 0;
}