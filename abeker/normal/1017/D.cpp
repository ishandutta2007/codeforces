#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 15;
const int MAXC = 105;

int N, M, Q;
int cost[MAXN];
int cnt[1 << MAXN];
int ans[1 << MAXN][MAXC];
vector <int> v[MAXC];

int get() {
	char s[MAXN];
	scanf("%s", s);
	int num = 0;
	for (int i = 0; i < N; i++)
		if (s[i] == '1')
			num |= 1 << i;
	return num;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 0; i < N; i++)
		scanf("%d", cost + i);
	
	while (M--)
		cnt[get()]++;
	
	for (int i = 0; i < 1 << N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
			if (!(i >> j & 1))
				sum += cost[j];
		if (sum < MAXC)
			v[sum].push_back(i);
	}
	
	for (int i = 0; i < MAXC; i++)
		for (int j = 0; j < 1 << N; j++) {
			ans[j][i] = i ? ans[j][i - 1] : 0;
			for (auto it : v[i])
				ans[j][i] += cnt[j ^ it];
		}
				
	while (Q--) {
		int t = get(), k;
		scanf("%d", &k);
		printf("%d\n", ans[t][k]);
	}
	
	return 0;
}