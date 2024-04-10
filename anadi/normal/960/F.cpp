#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
set <PII> S[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		S[i].insert({-1, 0});
	
	int res = 0;
	while(m--){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		swap(u, v);

		auto it = S[v].lower_bound({c, -1});
		--it;

		PII cur = {c, (*it).nd + 1};
		it = S[u].lower_bound({c, -1});
		--it;
		
		if((*it).nd >= cur.nd)
			continue;

		S[u].insert(cur);
		res = max(res, cur.nd);
		
		vector <PII> del;
		it = S[u].find(cur); ++it;
		while(it != S[u].end()){
			if((*it).nd > cur.nd)
				break;			

			del.push_back(*it);
			++it;
		}
		
		for(auto vv: del)
			S[u].erase(vv);
	}
	
	printf("%d\n", res);
	return 0;
}