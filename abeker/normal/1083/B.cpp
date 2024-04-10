#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;
const ll INF = 1e18;

int N, K;
char S[MAXN], T[MAXN];
ll a[MAXN], b[MAXN];

void load() {
	scanf("%d%d%s%s", &N, &K, S, T);
}

ll solve() {
	string s = S;
	string t = T;
	if (s == t)
		return N;
		
	ll sol = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] != t[i]) {
			s = s.substr(i, N - i);
			t = t.substr(i, N - i);
			N -= i;
			break;
		}
		sol++;
	}
	
	for (int i = 1; i < N; i++) {
		a[i] = min(2 * a[i - 1] + !(s[i] - 'a'), INF);
		b[i] = min(2 * b[i - 1] +  (t[i] - 'a'), INF);
	}
	
	for (int i = N - 1; i >= 0; i--) 
		sol += min((ll)K, a[i] + b[i] + 2);
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}