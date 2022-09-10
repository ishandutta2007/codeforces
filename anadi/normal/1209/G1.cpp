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

int n, q;
int in[N];
int cnt[N];

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		cnt[in[i]]++;
	}
	
	int sum = 0;
	set <int> S;

	int ans = n;
	for(int i = 1; i <= n; ++i){
		if(S.find(in[i]) == S.end()){
			S.insert(in[i]);
			sum += cnt[in[i]];
		}
		
		sum--;
		if(sum == 0){
			int mx = 0;
			for(auto v: S)
				mx = max(mx, cnt[v]);

			ans -= mx;
			S.clear();
		}
	}

	printf("%d\n", ans);
	return 0;
}