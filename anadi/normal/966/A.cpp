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

int n, m;
int cl, ce, v;
set <int> S1, S2;

int solve(int x1, int y1, int x2, int y2, int t, int v){
	return abs(y1 - t) + abs(y2 - t) + (abs(x2 - x1) + v - 1) / v;
}

int main(){
	scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
	while(cl--){
		int a;
		scanf("%d", &a);
		S1.insert(a);
	}
	
	while(ce--){
		int a;
		scanf("%d", &a);
		S2.insert(a);
	}
	
	int q;
	scanf("%d", &q);
	while(q--){
		int res = MX;
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if(x1 == x2)
			res = min(res, abs(y2 - y1));
		
		if(S1.size()){
			auto it = S1.lower_bound(y1);
			if(it != S1.end())
				res = min(res, solve(x1, y1, x2, y2, *it, 1));
			if(it != S1.begin()){
				--it;
				res = min(res, solve(x1, y1, x2, y2, *it, 1));
			}
		}
		
		if(S2.size()){
			auto it = S2.lower_bound(y1);
			if(it != S2.end())
				res = min(res, solve(x1, y1, x2, y2, *it, v));
			if(it != S2.begin()){
				--it;
				res = min(res, solve(x1, y1, x2, y2, *it, v));
			}
		}
		
		printf("%d\n", res);
	}

	return 0;
}