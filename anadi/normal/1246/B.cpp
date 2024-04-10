#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int L = 100 * 1000;
const int N = L + 7;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, k;
int in[N];
int cnt[N];

int Need[N];
int TrueVal[N];
vector <int> dv[N];

void getVal(int v){
	TrueVal[v] = 1;
	for(auto p: dv[v]){
		int tmp = 0, tv = v;
		while(tv % p == 0)
			tmp++, tv /= p;
		tmp %= k;
		
		while(tmp--)
			TrueVal[v] *= p;
	}
}

void getNeed(int v){
	Need[v] = L + 1;
	long long cur = 1;

	for(int p: dv[v]){
		int tmp = 0, tv = v;
		while(tv % p == 0)
			tmp++, tv /= p;

		tmp %= k;
		tmp = (k - tmp) % k;
		
		while(tmp--){
			cur *= p;
			if(cur > L)
				return;
		}
	}
	
	Need[v] = cur;
}

void prepro(){
	for(int i = 2; i <= L; ++i)
		if(dv[i].size() == 0)
			for(int j = i; j <= L; j += i)
				dv[j].push_back(i);
	
	TrueVal[1] = Need[1] = 1;
	for(int i = 2; i <= L; ++i){
		getVal(i);
		getNeed(i);
	}
}

int main(){
	scanf("%d %d", &n, &k);
	prepro();

	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		ans += cnt[Need[in[i]]];
		cnt[TrueVal[in[i]]]++;
	}
	
//	for(int i = 1; i <= n; ++i)
//		printf("%d -> %d %d\n", in[i], TrueVal[in[i]], Need[in[i]]);
	
	printf("%lld\n", ans);
	return 0;
}