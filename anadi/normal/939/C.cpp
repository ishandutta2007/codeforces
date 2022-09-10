#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 19LL;

int n;
int s, f;
PII best;
int pref[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &pref[i]);
		pref[i + n] = pref[i];
	}

	scanf("%d %d", &s, &f);
	for(int i = 1; i <= 2 * n; ++i)
		pref[i] += pref[i - 1];
	--f;
	
	for(int i = 1; i <= n; ++i){
		int maxi = i + f - s;
		int t = s - i + 1;
		if(t <= 0)
			t += n;
		best = max(best, make_pair(pref[maxi] - pref[i - 1], -t));
	}
	
	printf("%d\n", -best.nd);
	return 0;
}