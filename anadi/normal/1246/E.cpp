#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2001;
const int M = 16;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, k;
int in[M];
bitset <N> B[1 << M];

void getResult(){
	int cur = (1 << n) - 1, val = 1;
	vector <PII> result;
	
	int cnt = 0;
	while(cur > 0){
		for(int j = 0; j < n; ++j){
			if((cur & (1 << j)) == 0)
				continue;
			
			bool is = false; int value = val, need = 0;
			bitset <N> tmp = B[cur ^ (1 << j)] << in[j];
			
			while(value < N){
				if(tmp[value]){
					is = true;
					break;
				}
				
				++need;
				value *= k;
			}
			
			if(is){
				cnt += need;
				result.push_back({cnt, in[j]});
				cur ^= 1 << j;

				val = value - in[j];
				break;
			}
		}
	}
	
//	for(auto v: result)
//		printf("%d %d\n", v.st, v.nd);
	
	while(result.size() > 1){
		int t = result.size();
		auto a = result[t - 1], b = result[t - 2];
		
		result.pop_back();
		result.pop_back();
		
		assert(a.st == b.st);
		printf("%d %d\n", a.nd, b.nd);

		int nxtVal = a.nd + b.nd;
		int nxtMx = a.st;
		
		while(nxtVal % k == 0){
			nxtVal /= k;
			nxtMx--;
		}
		
		result.push_back({nxtMx, nxtVal});
		sort(result.begin(), result.end());
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", &in[i]);
	
	B[0][0] = 1;
	for(int i = 1; i < (1 << n); ++i){
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				B[i] |= B[i ^ (1 << j)] << in[j];

		for(int j = N - 1; j >= 0; --j)
			if(j % k == 0)
				B[i][j / k] = B[i][j / k] | B[i][j];
	}
	
	if(B[(1 << n) - 1][1]){
		puts("YES");
		getResult();
	}
	else
		puts("NO");
	return 0;
}