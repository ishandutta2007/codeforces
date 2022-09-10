#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 7LL;

int n;
int in[N];
int pref[N];
deque <PII> Q;

void get(int l, int v){
//	printf("%d %d\n", l, v);
	pref[l] = max(pref[l], v);
}

int main(){
	scanf("%d", &n); 
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	in[0] = -1;

	Q.push_back({0, 0});
	for(int i = 1; i <= n + 1; ++i){		
		while(in[Q.back().st] >= in[i]){
			get(i - Q.back().nd, in[Q.back().st]);
			Q.pop_back();
		}
		
		int t = Q.back().st;
		Q.push_back({i, t + 1});
	}
	
	for(int i = n - 1; i >= 1; --i)
		pref[i] = max(pref[i], pref[i + 1]);
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", pref[i]);
	return 0;
}