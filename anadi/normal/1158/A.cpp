#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
int in[N];
int in2[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);

	for(int i = 1; i <= m; ++i)
		scanf("%d", &in2[i]);
	
	sort(in + 1, in + n + 1);
	sort(in2 + 1, in2 + m + 1);
	
	if(in2[1] < in[n]){
		puts("-1");
		return 0;
	}
	
	LL ans = 0;
	for(int i = 1; i < n; ++i)
		ans += 1LL * m * in[i];
	for(int i = 1; i <= m; ++i)
		ans += in2[i];

	if(in2[1] > in[n])
		ans += in[n] - in[n - 1];
	printf("%lld\n", ans);
	return 0;
}