#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int BASE = 10007;
const int MOD = 1000000007;
const int LOG1 = 18;
const int LOG2 = 60;
const int INF = 0x3f3f3f3f;
const ll INF1 = 0x3f3f3f3f3f3f3f3fll;
const int M = 1 << 4;

ll K;
int N;
char s[MAXN];
int hsh[MAXN], pot[MAXN];
int idx[MAXN], hist[MAXN];
int sparse[MAXN][LOG1];
int expo[MAXN];
int nxt[4][MAXN];
ll mat[M][M][LOG2];
int trans[4][M];
int left[4], right[4];

void load() {
	scanf("%lld%s", &K, s + 1);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

int get(int lo, int hi) {
	return add(hsh[hi], -mul(pot[hi - lo + 1], hsh[lo - 1]));
}

int lcp(int x, int y) {
	int lo = 0, hi = min(N - x + 1, N - y + 1);
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (get(x, x + mid - 1) == get(y, y + mid - 1))
			lo = mid;
		else 
			hi = mid - 1;
	}
	return lo;
}

bool cmp(const int &x, const int &y) {
	int l = lcp(x, y);
	if (l == N - y + 1)
		return 0;
	if (l == N - x + 1)
		return 1;
	return s[x + l] < s[y + l];
}

int merge(int l, int r) {
	if (hist[l] == hist[r])
		return min(l, r);
	return hist[l] < hist[r] ? l : r;
}

int query(int lo, int hi) {
	if (lo >= hi)
		return N;
	int e = expo[hi - lo];
	return merge(sparse[lo][e], sparse[hi - (1 << e)][e]);
}

void update(int &ref, int val) {
	ref = min(ref, val);
}

void update1(ll &ref, ll val) {
	ref = min(ref, val);
}

void rec(int lo, int hi, int depth, int k) {
	if (lo == hi)
		return;
		
	vector <int> tmp;
	int pos = lo - 1;
	int mini = N - idx[lo] + 1;
	while (1) {
		tmp.push_back(pos + 1);
		pos = query(pos + 1, hi - 1);
		update(mini, hist[pos]);
		if (hist[pos] != mini)
			break;
	}
	
	for (int i = 0; i < 4; i++) {
		int curr = nxt[i][idx[lo] + depth + 1] - idx[lo];
		if (curr >= mini)
			continue;
		for (int j = 1; j < M; j++)
			if (!(j >> i & 1)) 
				update(trans[k][j], curr);
	}
	
	int mask = 0;
	for (int it : tmp)
		if (idx[it] + mini <= N)
			mask |= 1 << s[idx[it] + mini] - 'A';
		
	for (int i = 1; i < M; i++)
		if (!(i & mask)) 
			update(trans[k][i], mini);
		
	if (hi - lo == 1)
		return;
		
	tmp.push_back(hi);
	for (int i = 1; i < tmp.size(); i++)
		if (idx[tmp[i - 1]] + mini <= N)
			rec(tmp[i - 1], tmp[i], mini, k);
}

ll calc(ll val) {
	ll opt[M][M];
	ll prev[M][M];
	memset(opt, INF1, sizeof opt);
	for (int i = 1; i < M; i++)
		opt[i][i] = 0;
	for (int it = 0; it < LOG2; it++)
		if (val >> it & 1ll) {
			memcpy(prev, opt, sizeof prev);
			memset(opt, INF1, sizeof opt);
			for (int i = 1; i < M; i++)
				for (int j = 1; j < M; j++)
					for (int k = 1; k < M; k++)
						update1(opt[i][j], prev[i][k] + mat[k][j][it]);
		}
	return *min_element(opt[M - 1] + 1, opt[M - 1] + M);
}

ll solve() {
	N = strlen(s + 1);
	
	pot[0] = 1;
	for (int i = 1; i <= N; i++) {
		hsh[i] = add(mul(hsh[i - 1], BASE), s[i]);
		pot[i] = mul(pot[i - 1], BASE);
	}
	
	for (int i = 1; i <= N; i++)
		idx[i] = i;
	
	sort(idx + 1, idx + N + 1, cmp);
	
	hist[N] = INF;
	for (int i = 1; i < N; i++) {
		hist[i] = lcp(idx[i], idx[i + 1]);
		sparse[i][0] = i;
	}
	
	for (int i = 2; i <= N; i++)
		expo[i] = expo[i / 2] + 1;
		
	for (int j = 1; j < LOG1; j++)
		for (int i = 1; i < N; i++)
			sparse[i][j] = merge(sparse[i][j - 1], i + (1 << j - 1) < N ? sparse[i + (1 << j - 1)][j - 1] : N);

	memset(nxt, INF, sizeof nxt);
	for (int i = 0; i < 4; i++) 
		for (int j = N; j; j--)
			nxt[i][j] = s[j] - 'A' == i ? j : nxt[i][j + 1];
	
	for (int i = 1; i <= N; i++) {
		int ltr = s[idx[i]] - 'A';
		right[ltr] = i;
		if (!left[ltr])
			left[ltr] = i;
	}
	
	memset(trans, INF, sizeof trans);
	for (int i = 0; i < 4; i++)
		rec(left[i], right[i] + 1, 0, i);
	
	memset(mat, INF1, sizeof mat);
	for (int i = 1; i < M; i++)
		for (int j = 1; j < M; j++)
			for (int k = 0; k < 4; k++)
				if (i >> k & 1)
					update1(mat[i][j][0], (ll)trans[k][j]);
			
	for (int it = 1; it < LOG2; it++)
		for (int i = 1; i < M; i++)
			for (int j = 1; j < M; j++)
				for (int k = 1; k < M; k++)
					update1(mat[i][j][it], mat[i][k][it - 1] + mat[k][j][it - 1]);
	
	ll lo = 0, hi = 1e18;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (calc(mid) >= K)
			hi = mid;
		else 
			lo = mid + 1;
	}
	
	return lo;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}