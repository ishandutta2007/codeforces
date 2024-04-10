#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
PII id[N];
vector <int> chain;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int v;
		scanf("%d", &v);
		id[i] = {v, i};
	}
	
	sort(id + 1, id + n + 1);
	reverse(id + 1, id + n + 1);

	for(int i = 1; i <= n; ++i){
		chain.push_back(id[i].nd * 2);
		if(i > 1)
			printf("%d %d\n", chain[i - 2], chain[i - 1]);
	}

	for(int i = 1; i <= n; ++i){
		int t = id[i].nd;
		if((int)chain.size() - i + 1 == id[i].st){
			printf("%d %d\n", chain.back(), 2 * t - 1);
			chain.push_back(t + t - 1);
		}
		else{
			int p = i + id[i].st - 2;
			printf("%d %d\n", 2 * t - 1, chain[p]);
		}
	}

	return 0;
}