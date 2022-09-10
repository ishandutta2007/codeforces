#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int M = 1 << 25;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int in[N];
int pref[M];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	int ans = 0, t = 0;
	for(int i = 2; i <= M; i *= 2){
		for(int j = 0; j < i; ++j)
			pref[j] = 0;
		
		for(int j = 1; j <= n; ++j)
			pref[in[j] & (i - 1)]++;
		
		for(int j = 1; j < i; ++j)
			pref[j] += pref[j - 1];
		
		long long int cnt = 0;
		for(int j = 1; j <= n; ++j){
			if((in[j] << 1) & (1 << t))
				--cnt;
			
			int base = in[j] & ((1 << t) - 1);
			if(in[j] & 1 << t){
				cnt += pref[(1 << t) - base - 1];
				cnt += pref[i - 1] - pref[i - base - 1];
			}
			else
				cnt += pref[i - base - 1] - pref[(1 << t) - base - 1];
		}
		
//		printf("%d :: %lld\n", i, cnt);
		assert(cnt % 2 == 0);

		++t;
		cnt /= 2;
		if(cnt & 1)
			ans += i >> 1;
	}
	
	printf("%d\n", ans);
	return 0;
}