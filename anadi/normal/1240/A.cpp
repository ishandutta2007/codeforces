#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
LL k;
int in[N];
int prc[N];

void updatePrc(){
	int x, a;
	scanf("%d %d", &x, &a);
	
	for(int i = a; i <= n; i += a)
		prc[i] += x;
}

bool ok(int t){
	vector <int> cur;
	for(int i = 1; i <= t; ++i)
		cur.push_back(prc[i]);

	sort(cur.begin(), cur.end());
	reverse(cur.begin(), cur.end());
	
	LL ans = 0;
	for(int i = 0; i < t; ++i)
		ans += in[i + 1] * cur[i];
	return ans >= k;
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		in[i] /= 100;
	}

	sort(in + 1, in + n + 1);
	reverse(in + 1, in + n + 1);
	
	for(int i = 1; i <= n; ++i)
		prc[i] = 0;
	
	updatePrc();
	updatePrc();
	scanf("%lld", &k);

//	for(int i = 1; i <= n; ++i)
//		printf("%d %d\n", prc[i], in[i]);

	int s = 1, e = n + 1;
	while(s < e){
		int mid = (s + e) / 2;
		if(!ok(mid))
			s = mid + 1;
		else
			e = mid;
	}
	
	if(s > n)
		puts("-1");
	else
		printf("%d\n", e);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}