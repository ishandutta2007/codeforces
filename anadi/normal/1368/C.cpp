#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

void write(vector <PII> ans){
	printf("%d\n", (int)ans.size());
	for(auto p: ans)
		printf("%d %d\n", p.st, p.nd);
}

int main(){
	int n;
	scanf("%d", &n);
	
	vector <PII> ans;	
	for(int i = -1; i <= 0; ++i)
		for(int j = 0; j <= 1; ++j)
			ans.push_back({i, j});

	ans.push_back({0, -1});	
	ans.push_back({1, 0});
	ans.push_back({1, -1});
	
	int x = 1, y = -1;
	for(int i = 1; i < n; ++i){
		ans.push_back({x + 1, y});
		ans.push_back({x, y - 1});
		
		x += 1, y -= 1;
		ans.push_back({x, y});
	}
	
	write(ans);
	return 0;
}