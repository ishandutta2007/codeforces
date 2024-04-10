#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;
const double eps = 1e-13;

int n;
double prob[N];
double prob2[N];

bool dp[N][2];
bool choose[N];
double res[N][2];
pair <double, double> poss[N][2];

bool ok(pair <double, double> a){
	return -eps <= a.st && a.st <= 1.0 + eps && -eps <= a.nd && a.nd <= 1.0 + eps;
}

bool ok2(pair <double, double> a, pair <double, double> b){
	return a.st - eps <= b.st && a.nd - eps <= b.nd;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lf", &prob[i]),
		prob[i] += prob[i - 1];

	for(int i = 1; i <= n; ++i)
		scanf("%lf", &prob2[i]);
	for(int i = n; i >= 1; --i)
		prob2[i] = prob2[i] + prob2[i + 1];
	
	poss[0][0] = poss[0][1] = {0.0, 0.0};
	for(int i = 1; i <= n; ++i){
		double y = prob[i];
		double x = -prob2[i + 1] + 1.0 + y;
		
//		printf("%.9lf %.9lf\n", x, y);
//		assert(x * x >= 4.0 * y);
		double delt = 0.0;
		if(x * x >= 4.0 * y)
			delt = sqrt(x * x - 4.0 * y);
		double s1 = (x + delt) / 2.0;
		double s2 = (x - delt) / 2.0;
		
		poss[i][0] = {s1, x - s1};
		poss[i][1] = {s2, x - s2};
		
//		printf("%d :: %.9lf %.9lf :: %.9lf %.9lf\n", i, s1, x - s1, s2, x - s2);
	}
	
	dp[n][0] = ok(poss[n][0]);
	dp[n][1] = ok(poss[n][1]);

	for(int i = n - 1; i >= 1; --i){
		dp[i][0] = ok(poss[i][0]);
		dp[i][1] = ok(poss[i][1]);
		
		dp[i][0] &= ok2(poss[i][0], poss[i + 1][0]) | ok2(poss[i][0], poss[i + 1][1]);
		dp[i][1] &= ok2(poss[i][1], poss[i + 1][0]) | ok2(poss[i][1], poss[i + 1][1]);
	}
	
	assert(dp[1][0] | dp[1][1]);
	pair <double, double> last = {0.0, 0.0};
	for(int i = 1; i <= n; ++i){
		if(!ok2(last, poss[i][0]) || !dp[i][0])
			choose[i] = true;
		
		res[i][0] = poss[i][choose[i]].st - last.st;
		res[i][1] = poss[i][choose[i]].nd - last.nd;
		last = poss[i][choose[i]];
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%.12lf ", res[i][0]);
	puts("");
	for(int i = 1; i <= n; ++i)
		printf("%.12lf ", res[i][1]);
	return 0;
}