#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII  pair <int, int>

const int N = (1 << 12) + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, q;
int val[N];
int cnt[N];
int res[N][N];
vector <PII> sum;

int read(){
	char cur = ' ';
	while(cur < '0')
		cur = getchar();
	
	int ret = 0;
	while('0' <= cur){
		ret = ret * 2 + cur - '0';
		cur = getchar();
	}

	return ret;
}

int get(int a){
	int p = 0, k = (1 << n) - 1;
	while(p < k){
		int m = (p + k + 1) >> 1;
		if(sum[m].st <= a)
			p = m;
		else
			k = m - 1;
	}
	
	return p;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	reverse(val, val + n);
	
	for(int i = 1; i <= m; ++i)
		cnt[read()]++;
	
	sum.resize(1 << n);
	for(int i = 0; i < (1 << n); ++i){
		for(int j = 0; j < n; ++j)
			if(!(i & (1 << j)))
				sum[i].st += val[j];
		sum[i].nd = i;
	}
	
	sort(sum.begin(), sum.end());
	for(int i = 0; i < (1 << n); ++i){
		int last = 0, t = 0;
		for(auto v: sum){
			res[i][t] = last + cnt[i ^ v.nd];
			last = res[i][t]; ++t;
		}
	}
	
	while(q--){
		int t = read(), k;
		scanf("%d", &k);
		printf("%d\n", res[t][get(k)]);
	}

	return 0;
}