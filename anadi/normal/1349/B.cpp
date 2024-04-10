#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 1 << 19;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, k;
int in[N];
int tree[T + T + 7];
vector <int> added;

void add(int p, int v){
	if(v > 0)
		added.push_back(p);
	
	p += N;
	p += T;
	
	while(p){
		tree[p] += v;
		p >>= 1;
	}
}

int ask(int from, int to){
	int ret = 0;
	from += N, to += N;
	from += T, to += T;

	while(from <= to){
		if(from & 1)
			ret += tree[from];
		
		if(!(to & 1))
			ret += tree[to];
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	return ret;
}

LL check(int v){
	added.clear();
	int bal = 0, prv_bal = 0;

	LL ans = 0;
	for(int i = 1; i <= n; ++i){
		if(i > 1){
//			printf("add %d\n", prv_bal);
			add(prv_bal, 1);
		}
		
		prv_bal = bal;
		if(in[i] >= v)
			++bal;
		else
			--bal;
		
//		printf("%d :: from %d to %d v %d\n", i, -n, bal - 1, ask(-n, bal - 1));
		ans += ask(-n, bal - 1);
	}
	
	for(auto v: added)
		add(v, -1);
	
//	printf("%d :: %lld\n", v, ans);
	return ans;
}

void solve(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	if(n == 1){
		puts(in[1] == k ? "yes" : "no");
		return;
	}
	
	bool is = false;
	for(int i = 1; i <= n; ++i)
		is |= in[i] == k;

	bool bg = check(k) > 0;
	bool sm = 1LL * n * (n - 1) / 2 > check(k + 1);

	if(bg && sm && is)
		puts("yes");
	else
		puts("no");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}