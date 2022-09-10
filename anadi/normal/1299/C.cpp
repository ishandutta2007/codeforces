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

int n;
int in[N];
vector <pair <T, int> > Hull;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i <= n; ++i){
		T tmp = in[i];
		int sz = 1;

		while(Hull.size()){
			if(Hull.back().st < tmp)
				break;
			
			auto cur = Hull.back();
			Hull.pop_back();
			
			tmp = tmp * sz + cur.st * cur.nd;
			sz += cur.nd;
			tmp /= sz;
		}
		
		Hull.push_back({tmp, sz});
	}
	
	for(auto v: Hull){
		for(int t = 0; t < v.second; ++t)
			printf("%.10Lf\n", v.first);
	}
	
	return 0;
}