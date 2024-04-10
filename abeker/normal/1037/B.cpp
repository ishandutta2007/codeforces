#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N, S;
int a[MAXN];

int main() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	vector <int> l, r;
	for (int i = 0; i < N; i++)
		if (a[i] < S)
			l.push_back(a[i]);
		else if (a[i] > S)
			r.push_back(a[i]);
	
	ll ans = 0;
	int half = (N - 1) / 2;
	if (l.size() > half) {
		sort(l.begin(), l.end(), greater <int> ());
		for (int i = 0; i < (int)l.size() - half; i++)
			ans += S - l[i];
	}
	else if (r.size() > half) {
		sort(r.begin(), r.end());
		for (int i = 0; i < (int)r.size() - half; i++)
			ans += r[i] - S;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}