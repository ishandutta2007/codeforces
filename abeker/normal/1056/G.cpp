#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int LOG = 60;

ll T;
int N, M, S;
int jmp[MAXN][LOG];
int tour[2 * offset];
vector <int> queries[MAXN];
int l[3 * MAXN], r[3 * MAXN];
vector <pii> states;
int trans[3 * MAXN];
int dp[3 * MAXN];
int pref[MAXN];

void load() {
	scanf("%d%d%d%lld", &N, &M, &S, &T);
	S--;
}

inline int add(int x, int y) {
	x += y;
	if (x >= N)
		return x - N;
	if (x < 0)
		return x + N;
	return x;
}

inline int get_id(pii p) {
	if (p.second < N - 1)
		return 2 * p.second + p.first - M + 1;
	return 2 * (N - 1) + p.first;
}

inline int get_dp(int x, int y) {
	return dp[get_id({x, y})];
}

void update(int x, int val) {
	x += offset;
	tour[x] = val;
	for (x /= 2; x; x /= 2)
		tour[x] = max(tour[2 * x], tour[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return -1;
	if (lo >= from && hi <= to)
		return tour[x];
	int mid = (lo + hi) / 2;
	return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int query(int from, int to) {
	return query(1, 0, offset, from, to);
}

int solve() {
	memset(tour, -1, sizeof tour);
	
	for (int i = 0; i < N - 1; i++) {
		states.push_back({M - 1, i});
		states.push_back({M, i});
	}
	for (int i = 0; i < N; i++)
		states.push_back({i, N - 1});
	
	for (int i = 1; i < N; i++) 
		pref[i] = add(pref[i - 1], i);
		
	for (int i = 0; i < states.size(); i++) {
		pii it = states[i];
		assert(get_id(it) == i);
		if (it.first < M) {
			l[i] = add(add(it.first, pref[it.second]), 1);
			r[i] = add(l[i], -M);
		}
		else {
			l[i] = add(-it.first, pref[it.second]);
			r[i] = add(l[i], M);
		}
		queries[it.second].push_back(i);
	}
	
	for (int i = 0; i < N; i++) {
		for (auto it : queries[i]) 
			if (l[it] < r[it])
				trans[it] = query(l[it], r[it]);
			else
				trans[it] = max(query(l[it], N), query(0, r[it]));
		update(pref[i], i);
	}
	
	for (int i = 0; i < states.size(); i++) {
		pii it = states[i];
		if (trans[i] == -1) {
			dp[i] = add(it.first, it.first < M ? pref[it.second] : -pref[it.second]);
			continue;
		}
		if (it.first < M) {
			int pos = add(it.first, add(pref[it.second], -pref[trans[i] + 1]));
			int nxt = add(it.first, add(pref[it.second], -pref[trans[i]]));
			if (nxt - M <= M - 1 - pos)
				dp[i] = get_dp(M, trans[i] - 2 * (nxt - M));
			else
				dp[i] = get_dp(M, trans[i] - 2 * (M - 1 - pos) - 1);
		}
		else {
			int pos = add(it.first, -add(pref[it.second], -pref[trans[i] + 1]));
			int nxt = add(it.first, -add(pref[it.second], -pref[trans[i]]));
			if (M - 1 - nxt <= pos - M)
				dp[i] = get_dp(M - 1, trans[i] - 2 * (M - 1 - nxt));
			else
				dp[i] = get_dp(M - 1, trans[i] - 2 * (pos - M) - 1);
		}
	}
	
	for (int i = 0; i < N; i++)
		jmp[i][0] = get_dp(i, N - 1);	
	
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i < N; i++)
			jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
	
	for (int t = T % N; t; t--) 
		S = add(S, S < M ? t : -t);
	
	ll rep = T / N;
	for (int i = 0; i < LOG; i++)
		if (rep >> i & 1ll)
			S = jmp[S][i];
	
	return ++S;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}