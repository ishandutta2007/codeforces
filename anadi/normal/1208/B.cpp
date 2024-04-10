#include <bits/stdc++.h>

using namespace std;

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
int cnt[N];
int ileduzo;
map <int, int> M;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		if(!M.count(in[i]))
			M[in[i]] = M.size();
		in[i] = M[in[i]];
	}
	
	for(int i = 1; i <= n; ++i){
		cnt[in[i]]++;
		if(cnt[in[i]] == 2)
			++ileduzo;
	}
	
	int ans = n - 1;
	if(ileduzo == 0)
		ans = 0;

	for(int i = 1; i <= n; ++i){
		ileduzo = 0;
		for(int j = 1; j <= n; ++j)
			cnt[in[j]] = 0;

		for(int j = 1; j <= n; ++j){
			cnt[in[j]]++;
			if(cnt[in[j]] == 2)
				++ileduzo;
		}

		for(int j = i; j <= n; ++j){
			cnt[in[j]]--;
			if(cnt[in[j]] == 1)
				--ileduzo;
			
			if(ileduzo == 0)
				ans = min(ans, j - i + 1);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}