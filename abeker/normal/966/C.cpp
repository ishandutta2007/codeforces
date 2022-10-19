#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXB = 60;

int N;
ll a[MAXN];
vector <ll> v[MAXB];
vector <ll> ans;
ll pref[MAXN];

void bye() {
	puts("No");
	exit(0);
}

void check() {
	assert(ans.size() == N);
	for (int i = 1; i <= N; i++) {
		pref[i] = pref[i - 1] ^ ans[i - 1];	
		if (pref[i] <= pref[i - 1])
			bye();
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
	
	for (int i = 0; i < N; i++)
		for (int j = MAXB - 1; j >= 0; j--)
			if (a[i] >> j & 1ll) {
				v[j].push_back(a[i]);
				break;
			}
			
	for (int i = MAXB - 1; i >= 0; i--) {
		if (v[i].empty())
			continue;
			
		vector <ll> nxt;
		nxt.push_back(v[i].back());
		v[i].pop_back();
		for (auto it : ans) {
			nxt.push_back(it);
			if (it >> i & 1ll && !v[i].empty()) {
				nxt.push_back(v[i].back());
				v[i].pop_back();
			}
		}
		
		if (!v[i].empty())
			bye();
		
		ans = nxt;
	}
	
	check();
	
	puts("Yes");
	for (auto it : ans)
		printf("%lld ", it);
	puts("");
	
	return 0;
}