# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1000051;
const int P = 998244353;
int n;
bool flag[MAXN];
int p[MAXN], psz;
int f[MAXN], s[MAXN], d[MAXN], d1[MAXN];
int main(){
	scanf("%d", &n);
	d[1] = 1;
	for (int i = 2; i <= n; i++){
		if (!flag[i]){
			p[++psz] = i;
			d1[i] = 2;
			d[i] = 2;
		}
		for (int j = 1; j <= psz && i * p[j] <= n; j++){
			flag[i * p[j]] = true;
			if (i % p[j] == 0){
				d[i * p[j]] = d[i] / d1[i] * (d1[i] + 1);
				d1[i * p[j]] = d1[i] + 1;
				break;
			}
			d[i * p[j]] = d[i] * 2;
			d1[i * p[j]] = 2;
		}
	}
	for (int i = 1; i <= n; i++){
		f[i] = (s[i - 1] + d[i]) % P;
		s[i] = (s[i - 1] + f[i]) % P;
		// printf("%d %d\n", i, f[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}