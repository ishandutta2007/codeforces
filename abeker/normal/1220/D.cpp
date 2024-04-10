#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
ll b[MAXN];
int cnt[100];

int v2(ll x) {
	int res = 0;
	for (; !(x % 2); x /= 2)
		res++;
	return res;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", b + i);
		cnt[v2(b[i])]++;
	}
	
	int opt = max_element(cnt, cnt + 100) - cnt;
	vector <ll> ans;
	for (int i = 0; i < N; i++)
		if (v2(b[i]) != opt)
			ans.push_back(b[i]);
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%lld ", it);
	puts("");
	
	return 0;
}