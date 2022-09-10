#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
bool ans[N];
vector <int> V[N];

void solve(int t){
	for(int v: V[t]){
		int cx = v;
		while(cx + t <= n){
			cx += t;
			ans[v] |= in[cx] > t && !ans[cx];
		}
		
		cx = v;
		while(cx - t >= 1){
			cx -= t;
			ans[v] |= in[cx] > t && !ans[cx];
		}
	}
}

bool ok[N];
void solve2(int t){
	for(int i = 0; i < t; ++i)
		ok[i] = false;

	for(int i = 1; i <= n; ++i)
		ok[i%t] |= in[i] > t && !ans[i];
	
	for(int v: V[t])
		ans[v] = ok[v%t];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]),
		V[in[i]].push_back(i);
	
	int t = sqrt(n);
	for(int i = n; i >= 1; --i){
		if(i > t)
			solve(i);
		else
			solve2(i);
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%c", ans[i] ? 'A' : 'B');
	return 0;
}