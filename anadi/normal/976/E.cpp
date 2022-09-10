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
const LL INF = 1e18 + 9LL;

int n, a, b;
int hp[N], dmg[N];

LL res;
bool inside[N];
pair <int, int> zysk[N];

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &hp[i], &dmg[i]);
		zysk[i] = {hp[i] - dmg[i], i};
		res += dmg[i];
	}
	
	b = min(b, n); int last = n + 1;
	sort(zysk + 1, zysk + n + 1);
	for(int i = n; i > n - b; --i){
		if(zysk[i].st <= 0)
			break;

		last = i;
		res += zysk[i].st;
		inside[zysk[i].nd] = true;
	}
	
	a = 1 << a;
	LL sum = res;
	int used = n - last + 1;

	for(int i = 1; i <= n; ++i){
		LL newhp = 1LL * a * hp[i];
		if(!inside[i]){
			if(used < b)
				res = max(res, sum + newhp - dmg[i]);
			else if(b > 0)
				res = max(res, sum + newhp - dmg[i] - zysk[last].st);
		}
		else
			res = max(res, sum + newhp - hp[i]);
	}
	
	printf("%lld\n", res);
	return 0;
}