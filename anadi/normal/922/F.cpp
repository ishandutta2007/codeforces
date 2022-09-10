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

int n, k;
int p[N];
int cnt[N];
bool bad[N];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = i + i; j <= n; j += i)
			++cnt[j];
//	int cur = -k;
	if(k == 1){
		puts("Yes");
		puts("2\n1 2");
		return 0;
	}
	
	int all = 0, ok = -1;
	for(int i = 1; i <= n; ++i){
		all += cnt[i];
		if(all >= k){
			ok = i;
			break;
		}
	}
	
	if(ok == -1){
		puts("No");
		return 0;
	}
	
	puts("Yes");
	all -= k;
	
	for(int i = 0; i <= all; ++i)
		p[i] = -1;
	p[0] = 0;
	
	if(all == 0){
		printf("%d\n", ok);
		for(int i = 1; i <= ok; ++i)
			printf("%d ", i);

		puts("");
		return 0;
	}
	
	int mini = ok / 2 + 1;
	for(int i = mini; i <= ok; ++i){
		for(int j = all; j >= cnt[i]; --j)
			if(p[j - cnt[i]] != -1 && p[j] == -1)
				p[j] = i;
		
		if(p[all] >= 0)
			break;
	}
	
	mini = ok;
	assert(p[all] != -1);

	while(all > 0){
		bad[p[all]] = true;
		all -= cnt[p[all]];
		--mini;
	}
	
	printf("%d\n", mini);
//	vector <int> res;

	for(int i = 1; i <= ok; ++i)
		if(!bad[i]){
			printf("%d ", i);
//			res.push_back(i);
		}
	
/*	for(int v: res)
		for(int v2: res)
			if(v < v2 && v2%v == 0)
				++cur;
//234 432
	if(cur != 0)
		puts("KURDE NIE DZIALA");
*/	return 0;
}