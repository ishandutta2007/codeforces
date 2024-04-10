#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, k, ta, tb;
int in[N], in2[N];

int main(){
	scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &in2[i]);
	
	if(k >= min(n, m)){
		puts("-1");
		return 0;
	}
	
	int ans = 0;
	for(int i = 0; i <= k; ++i){
		int s = 1, e = m + 1;
		while(s < e){
			int mid = (s + e) / 2;
			if(in[i + 1] + ta <= in2[mid])
				e = mid;
			else
				s = mid + 1;
		}
		
		if(s + k - i > m){
			puts("-1");
			return 0;
		}
		
		ans = max(ans, in2[s + k - i] + tb);
	}
	
	printf("%d\n", ans);
	return 0;
}