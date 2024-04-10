#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
PII P[N];
int ans[N];
vector <pair <int, PII> > V[10];

int mnX = MX, mxX = 0;
int mnY = MX, mxY = 0;

int get(PII a, PII b){
	return abs(a.st - b.st) + abs(a.nd - b.nd);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &P[i].st, &P[i].nd);	
		mnX = min(mnX, P[i].st);
		mxX = max(mxX, P[i].st);
		mnY = min(mnY, P[i].nd);
		mxY = max(mxY, P[i].nd);
		
		int cnt = 0;
		for(int a = -2; a <= 2; a += 2)
			for(int b = -2; b <= 2; b += 2)
				V[cnt++].push_back({a * P[i].st + b * P[i].nd, P[i]});
	}
	
	ans[n] = get(P[1], P[n]);
	for(int i = n - 1; i >= 1; --i)
		ans[n] += get(P[i], P[i + 1]);

	for(int i = n - 1; i >= 4; --i)
		ans[i] = ans[i + 1];
	
	vector <PII> maybe;
	for(int i = 1; i <= n; ++i)
		if(mnX == P[i].st || mxX == P[i].st || mnY == P[i].nd || mxY == P[i].nd)
			maybe.push_back(P[i]);

	for(int i = 0; i < 9; ++i){
		sort(V[i].begin(), V[i].end());
		for(int j = 0; j < min(n, 10); ++j)
			maybe.push_back(V[i][j].nd);

		reverse(V[i].begin(), V[i].end());
		for(int j = 0; j < min(n, 10); ++j)
			maybe.push_back(V[i][j].nd);
	}
	
	for(PII a: maybe)
		for(PII b: maybe)
			for(PII c: maybe)
				ans[3] = max(ans[3], get(a, b) + get(b, c) + get(c, a));
	
	for(int i = 3; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}