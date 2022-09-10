#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 16;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int k;
LL sum[N];
vector <int> in[N];
unordered_map <LL, int> M;

LL maskSum[1 << N];
bool isPath[1 << N];
bool cycle[1 << N];

int who[N], where[N];
bool finalDp[1 << N];

void solve(int n, int val){
	isPath[0] = true;
	for(int i = 1; i < (1 << n); ++i)
		isPath[i] = false;

	for(int i = 0; i < (1 << n); ++i){
		if(!isPath[i])
			continue;

		if(maskSum[i ^ (1 << n)] == 0)
			cycle[i ^ (1 << n)] = true;

		int id = 0;
		if(M.count(val - maskSum[i]))
			id = M[val - maskSum[i]];

//		printf("%d %d -> %d %d\n", n, val, i, id);
		id &= ((1 << n) - 1) ^ i;
		
		if(id == 0)	continue;
		for(int t = 0; t < n; ++t)
			if(id & (1 << t))
				isPath[i ^ (1 << t)] = true;
	}
}

void getCycles(){
	for(int i = k - 1; i >= 0; --i)
		for(auto v: in[i])
			solve(i, v);
	
//	for(int i = 0; i < (1 << k); ++i)
//		if(cycle[i])
//			printf("%d\n", i);
}

void restore(int Msk){
	int n = -1;
	for(int i = 0; i < k; ++i)
		if(Msk & (1 << i))
			n = i;
	
	assert(n != -1);

	int val = -1;
	Msk ^= 1 << n;

	for(auto v: in[n]){
		solve(n, v);
		if(isPath[Msk]){
			val = v;
			break;
		}
	}
	
	assert(val != -1);
	int last = n;
	
	while(Msk > 0){
		for(int t = 0; t < n; ++t){
			if((Msk & (1 << t)) == 0)
				continue;

			int id = 0;
			if(M.count(val - maskSum[Msk] + sum[t]))
				id = M[val - maskSum[Msk] + sum[t]];

			if(id & (1 << t)){
				who[t] = val - maskSum[Msk];
				Msk ^= 1 << t;

				where[t] = last;
				last = t;
			}
		}
	}
	
	who[n] = val;
	where[n] = last;
}

int main(){
	LL allSum = 0;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int n;
		scanf("%d", &n);
		
		in[i].resize(n);
		for(int j = 0; j < n; ++j){
			scanf("%d", &in[i][j]);
			sum[i] += in[i][j];
		}
		
		allSum += sum[i];
	}

	if(allSum % k != 0){
		puts("No");
		exit(0);
	}
	
	allSum /= k;
	for(int i = 0; i < k; ++i){
		sum[i] = allSum - sum[i];
//		printf("sum[%d] = %lld\n", i, sum[i]);
	}
	
	for(int i = 0; i < k; ++i)
		for(auto v: in[i])
			M[v + sum[i]] |= 1 << i;
	
	for(int i = 1; i < (1 << k); ++i){
		int t = __builtin_ctz(i);
		maskSum[i] = sum[t] + maskSum[i ^ (1 << t)];
	}
	
	getCycles();
	finalDp[0] = true;
	for(int i = 1; i < (1 << k); ++i)
		for(int j = i; j > 0; j = i & (j - 1))
			finalDp[i] |= finalDp[i ^ j] && cycle[j];
	
	if(!finalDp[(1 << k) - 1])
		puts("No");
	else{
		puts("Yes");
		int curMask = (1 << k) - 1;
		
		while(curMask){
			for(int i = curMask; i > 0; i = curMask & (i - 1))
				if(cycle[i] && finalDp[curMask ^ i]){
					restore(i);
					curMask ^= i;
					break;
				}
		}
	
		for(int i = 0; i < k; ++i)
			printf("%d %d\n", who[i], where[i] + 1);
	}

	return 0;
}