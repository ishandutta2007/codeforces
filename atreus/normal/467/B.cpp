#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 3;
const int mod = 1e6 + 7;

int a[maxn];
int cnt[(1 << 21) + 10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i <= m; i++)
		cin >> a[i];
	n ++;
	for (int mask = 1; mask < (1 << n); mask++)
		cnt[mask] = cnt[mask - (mask & -mask)] + 1;
	int answer = 0;
	for (int i = 0; i < m; i++)
		answer += cnt[a[i] ^ a[m]] <= k;
	cout << answer << '\n';
}