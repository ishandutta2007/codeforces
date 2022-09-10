#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, x;
set <int> good;
vector <int> ans;

int main(){
	scanf("%d %d", &n, &x);
	for(int i = 1; i < (1 << n); ++i)
		good.insert(i);
	
	if(x < (1 << n))
		good.erase(x);
	
	int pref = 0;
	while(good.size()){
		int u = *good.begin();
		good.erase(good.begin());
		
		ans.push_back(pref ^ u);
		pref = u;

		if(good.find(x ^ u) != good.end())
			good.erase(x ^ u);
	}
	
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d ", v);
	return 0;
}