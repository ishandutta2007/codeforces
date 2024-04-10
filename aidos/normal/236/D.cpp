#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = 3e5;
int n;
double p[maxn];
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lf",&p[i]);
	}
	double ans = 0, s1 = 0, s2 = 0, s3 = 0;
	/*for(int i = 1; i <= n; i++) {
		double q = 1-p[i-1];
		for(int j = i; j <= n; j++) {
			q *= p[j];
			ans += (j-i+1) * (j-i+1) * q * (1-p[j+1]);
		}
	}*/
	for(int i = 1; i <= n; i++) {
		//(i - l) * (i-l) * p(l+1, i)
		//i * i * p(l+1, i)- 2 * l * i * p(l+1, i) + l * l * p(l+1, i)
		s3 *= p[i];
		s3 += p[i] * (1-p[i-1]);
		s2 *= p[i];
		s1 *= p[i];
		ans += (s3 * i * i - i * s2 + s1) * (1-p[i+1]);
		s2 += 2 * i * (1-p[i]);
		s1 += i * 1ll * i * (1-p[i]);
	}
	printf("%.12lf\n", ans);
}
int main(){
	solve();
	return 0;
}