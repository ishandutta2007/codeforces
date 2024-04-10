#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long int n, p[1003], tp[1003], ans = 2147483647;
char v[1003][5];
int main() {
	scanf("%lld", &n);
	for(long long int i=1; i<=n; i++) {
		scanf("%lld", &p[i]); 
		scanf("%s", v[i] + 1);
	}
	long long int x;
	for(long long int i=1; i<=n; i++) {
		x = 0;
		if(v[i][1] == 'A' || v[i][2] == 'A' || v[i][3] == 'A') {
			x += p[i];
			long long int tmp1 = p[i];
			p[i] = 0;
			for(long long int j=1; j<=n; j++) {
				if(v[j][1] == 'B' || v[j][2] == 'B' || v[j][3] == 'B') {
					x += p[j];
					long long int tmp2 = p[j];
					p[j] = 0;
					for(long long int k=1; k<=n; k++) {
						if(v[k][1] == 'C' || v[k][2] == 'C' || v[k][3] == 'C') {
							x += p[k];
							ans = min(ans, x);
							x -= p[k];
						}
					}
					p[j] = tmp2;
					x -= p[j];
				}
			}
			p[i] = tmp1;
			x -= p[i];
		}
	}
	printf("%lld", ans == 2147483647 ? -1 : ans);
}