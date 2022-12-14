#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 1e9;

int a[maxn], b[maxn], dp[maxn], pd[maxn], last[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int answer = 0;
	for (int i = 1; ; i++){
		int ptr = m;
		memset(last, 63, sizeof last);
		for (int j = 1; j <= n; j++){
			while (ptr > dp[j - 1]){
				last[b[ptr]] = ptr;
				ptr --;
			}
			pd[j] = last[a[j]];
		}
		dp[0] = inf;
		for (int j = 1; j <= n; j++){
			if (j + pd[j] + i * e <= s)
				answer = i;
			dp[j] = min(pd[j], dp[j - 1]);
		}
		if (answer != i)
			return cout << answer << endl, 0;
	}
}