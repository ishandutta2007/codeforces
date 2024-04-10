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

PII in[5];
set <PII> ans;
vector <int> xs, ys;

int main(){
	for(int i = 0; i < 3; ++i){
		scanf("%d %d", &in[i].st, &in[i].nd);
		xs.push_back(in[i].st);
		ys.push_back(in[i].nd);
	}
	
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());	
	
	int cx = xs[1], cy = ys[1];
	ans.insert({cx, cy});
	
	for(int i = xs[0]; i <= xs[2]; ++i)
		ans.insert({i, cy});
	
	for(int i = 0; i < 3; ++i){
		for(int j = in[i].nd; j <= cy; ++j)
			ans.insert({in[i].st, j});
		for(int j = cy; j <= in[i].nd; ++j)
			ans.insert({in[i].st, j});		
	}
	
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d %d\n", v.st, v.nd);
	return 0;
}