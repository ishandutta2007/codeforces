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

int n, k;
char input[N];
char target[N];

void solve() {
	scanf("%d %d", &n, &k);
	scanf("%s", input + 1);
	
	for(int i = 1; i < k; ++i) {
		target[2 * i - 1] = '(';
		target[2 * i] = ')';
	}
	
	int rest_len = (n - 2 * k + 2) / 2;
	for(int i = 0; i < rest_len; ++i) {
		target[2 * k - 2 + i + 1] = '(';
		target[2 * k - 2 + rest_len + i + 1] = ')';
	}
	
	vector <PII> result;
	for(int i = 1; i <= n; ++i)
		if(target[i] != input[i]) {
			for(int j = i + 1; j <= n; ++j)
				if(input[j] == target[i]) {
					result.push_back({i, j});
					reverse(input + i, input + j + 1);
					break;
				}
		}
	
	printf("%d\n", (int)result.size());
	for(auto [u, v]: result)
		printf("%d %d\n", u, v);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}