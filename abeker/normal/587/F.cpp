#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int BASE = 3137;
const int SQRT = 500;
const int LIMIT = 200;

struct Query {
	int where, who, which;
};

int N, M, Q;
ll ans[MAXN];
int pot[MAXN];
int len[MAXN];
string s[MAXN];
int idxBig[MAXN];
vector <int> big;
vector <ll> pref[MAXN];
int lft[MAXN], rig[MAXN];
int sum[MAXN], bucket[LIMIT];
int a[MAXN], b[MAXN], c[MAXN];
vector <int> L[MAXN], R[MAXN];
vector <Query> toDo[MAXN];
vector <int> pos[MAXN];
vector <int> hsh[MAXN];
vector <pii> arr;

void load() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++)	
		cin >> s[i];
	for (int i = 0; i < Q; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--;
		b[i]--;
		c[i]--;
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

int get(int x, int l, int r) {
	return add(hsh[x][r], -mul(hsh[x][l - 1], pot[r - l + 1]));
}

bool match(pii p, pii q, int l) {
	return p.second + l - 1 <= len[p.first] && q.second + l - 1 <= len[q.first] && 
		get(p.first, p.second, p.second + l - 1) == get(q.first, q.second, q.second + l - 1);
}

int lcp(pii p, pii q) {
	int lo = 0, hi = min(len[p.first] - p.second, len[q.first] - q.second) + 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (match(p, q, mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

bool cmp(const pii &lhs, const pii &rhs) {
	int l = lcp(lhs, rhs);
	return s[lhs.first][lhs.second + l] < s[rhs.first][rhs.second + l];
}

void output() {
	for (auto it : arr)
		cout << s[it.first].substr(it.second, len[it.first] - it.second + 1) << endl;
	for (int i = 0; i < N; i++)
		cout << lft[i] << ' ' << rig[i] << endl;
}

void update(int lo, int hi) {
	for (; lo <= hi && lo % SQRT; lo++)
		sum[lo]++;
	for (; hi >= lo && (hi + 1) % SQRT; hi--)
		sum[hi]++;
	if (lo > hi)
		return;
	for (int i = lo / SQRT; i <= hi / SQRT; i++)
		bucket[i]++;
}

void solve() {
	memset(idxBig, -1, sizeof idxBig);
	
	pot[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pot[i] = mul(pot[i - 1], BASE);
		
	for (int i = 0; i < N; i++) {
		len[i] = s[i].size();
		s[i] = '0' + s[i] + '0';
		hsh[i].push_back(0);
		for (int j = 1; j <= len[i]; j++) {
			hsh[i].push_back(add(mul(hsh[i].back(), BASE), s[i][j]));
			arr.push_back({i, j});
		}
		if (len[i] > LIMIT) {
			idxBig[i] = big.size();
			big.push_back(i);
		}
	}
	
	sort(arr.begin(), arr.end(), cmp);
	
	M = arr.size();
	for (int i = 0; i < M; i++) {
		int curr = arr[i].first;
		pos[curr].push_back(i);
		if (arr[i].second > 1)
			continue;
		int lo = 0, hi = i;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (match(arr[mid], arr[i], len[curr]))
				hi = mid;
			else
				lo = mid + 1;
		}
		lft[curr] = lo;
		L[lo].push_back(curr);
		lo = i, hi = M - 1; 
		while (lo < hi) {
			int mid = (lo + hi + 1) / 2;
			if (match(arr[mid], arr[i], len[curr]))
				lo = mid;
			else
				hi = mid - 1;
		}
		rig[curr] = lo;
		R[lo + 1].push_back(curr);
	}
		
	vector <int> sofar(big.size(), 0);
	for (int i = 0; i < N; i++)
		pref[i].resize(big.size());
		
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < big.size(); j++) {
			for (auto it : L[i])
				pref[it][j] -= sofar[j];
			for (auto it : R[i])
				pref[it][j] += sofar[j];
		}
		if (i < M && idxBig[arr[i].first] != -1)
			sofar[idxBig[arr[i].first]]++;
	}
	
	for (int i = 1; i < N; i++)
		for (int j = 0; j < big.size(); j++)
			pref[i][j] += pref[i - 1][j];
	
	for (int i = 0; i < Q; i++)
		if (idxBig[c[i]] == -1)
			for (auto it : pos[c[i]]) {
				toDo[a[i]].push_back({it, i, -1});
				toDo[b[i] + 1].push_back({it, i, 1});
			}
		else
			ans[i] = pref[b[i]][idxBig[c[i]]] - (a[i] ? pref[a[i] - 1][idxBig[c[i]]] : 0);
	
	for (int i = 0; i <= N; i++) {
		for (auto it : toDo[i])
			ans[it.who] += it.which * (sum[it.where] + bucket[it.where / SQRT]);
		if (i < N)
			update(lft[i], rig[i]);
	}
	
	for (int i = 0; i < Q; i++)
		cout << ans[i] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	load();
	solve();
	return 0;
}