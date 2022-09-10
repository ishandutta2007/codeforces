#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const int N = 2e5 + 7;
const int INF = 2e9 + 1;

int n, m;
PII t[N];
int who[N];

int BS(int a, int l){
	int p = a, k = n;
	while(p < k){
		int m = (p + k + 1) / 2;
		if(t[m].st <= t[a].st + l)
			p = m;
		else
			k = m - 1;
	}
	
	return p;
}

int BS2(int a, int l){
	int p = 1, k = a;
	while(p < k){
		int m = (p + k) / 2;
		if(t[m].st >= t[a].st - l)
			k = m;
		else
			p = m + 1;
	}
	
	return k;
}

int solve(int a, int b, int lp){
	if(t[a].st - b > t[a - 1].st && t[a].st + b < t[a + 1].st)
		return t[a].nd;

	int rm, lm;
	if(lp == 1){
		rm = BS(a, b);
		lm = BS2(rm, b - (t[rm].st - t[a].st));
//		printf("%d %d %d :: %d %d\n", a, b, lp, lm, rm);
		if(lm > a)
			return solve(lm, b - (t[rm].st - t[a].st) - (t[rm].st - t[lm].st), 1);
		b -= t[rm].st - t[a].st;
		int ile = b / (t[rm].st - t[lm].st);
		return solve(ile%2 ? lm : rm, b % (t[rm].st - t[lm].st), ile%2);
	}
	
	if(lp == 0){
		lm = BS2(a, b);
		rm = BS(lm, b - (t[a].st - t[lm].st));
		if(rm < a)
			return solve(rm, b - (t[a].st - t[lm].st) - (t[rm].st - t[lm].st), 0);
		b -= t[a].st - t[lm].st;
		int ile = (b / (t[rm].st - t[lm].st)) + 1;
		return solve(ile%2 ? lm : rm, b % (t[rm].st - t[lm].st), ile%2);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i].st),
		t[i].nd = i;
		
	sort(t + 1, t + n + 1);
	t[0].st = -INF;
	t[n + 1].st = INF;
	
	for(int i = 1; i <= n; ++i)
		who[t[i].nd] = i;
	
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(who[a], b, 1));
	}
	
	return 0;
}