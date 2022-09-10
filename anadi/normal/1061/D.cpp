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

int n, x, y;
PII seg[N];
int last[N];

LL res = 0LL;
priority_queue <PII> Q;

int main(){
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &seg[i].st, &seg[i].nd);
		Q.push({-seg[i].st, 1});
		Q.push({-seg[i].nd, -1});
		res = (res + 1LL * (seg[i].nd - seg[i].st) * y)%MX;
	}

	for(int i = 1; i <= n; ++i)
		last[i] = -MX;
	
	int cnt = 0;
	while(!Q.empty()){
		int v = Q.top().nd;
		int Time = -Q.top().st;
		Q.pop();
		
		cnt += v;
		if(v < 0){
			last[cnt + 1] = Time;
			last[cnt] = last[cnt + 1];
			continue;
		}
		
		res = (res + min(1LL * (Time - last[cnt]) * y, 1LL * x))%MX;
		last[cnt] = Time;
	}
	
	printf("%lld\n", res);
	return 0;
}