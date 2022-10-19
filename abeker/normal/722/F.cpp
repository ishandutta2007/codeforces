#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int MAXK = 41;

const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int pot[] = {2, 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19, 23, 25, 27, 29, 31, 32, 37};
const int p[]   = {2, 3, 2, 5, 7, 2, 3, 11, 13,  2, 17, 19, 23,  5,  3, 29, 31,  2, 37};

int N, M;
int k[MAXN];
int a[MAXN][MAXK];
vector <pii> pos[MAXN];
int mat[MAXN][MAXK];
int nxt[MAXN][MAXK];
int diff[MAXN][MAXK];
bool f;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", k + i);
		for (int j = 0; j < k[i]; j++)
			scanf("%d", a[i] + j);
	}
}

bool check(int x, int len) {
	int last[MAXK], power[MAXK];
	for (int i = 0; i < 12; i++) 
		last[prime[i]] = -1;
	
	for (int i = 0; i < 19; i++) {
		int tmp = nxt[x][i];
		if (tmp >= x + len) continue;
		if (diff[tmp][i] < x + len) return false;
		int curr =  mat[tmp][i];
		if (last[p[i]] != -1 && (curr - last[p[i]]) % power[p[i]])
			return false;
		last[p[i]] = curr;
		power[p[i]] = pot[i];
	}
	
	return true;
}

int longest(const vector <pii> &V) {
	int sz = V.size();
	vector <int> len, mod;
	for (int i = 0; i < sz; i++) {
		len.push_back(k[V[i].first]);
		mod.push_back(V[i].second);
	}
	
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < 19; j++)
			if (!(len[i] % pot[j]))
				mat[i][j] = mod[i] % pot[j];
			else mat[i][j] = -1;
		
	for (int j = 0; j < 19; j++) {
		nxt[sz][j] = sz;
		diff[sz][j] = sz;
		mat[sz][j] = -2;
		for (int i = sz - 1; i >= 0; i--) {
			if (mat[i][j] != -1) nxt[i][j] = i;
			else nxt[i][j] = nxt[i + 1][j];
			if (mat[i][j] == mat[nxt[i + 1][j]][j]) diff[i][j] = diff[nxt[i + 1][j]][j];
			else diff[i][j] = nxt[i + 1][j];
		}
	}
			
	int res = 0;
	for (int i = 0; i < sz; i++) {
		int lo = 1, hi = sz - i + 1;
		while (lo < hi) {
			int mid = (lo + hi + 1) / 2;
			if (check(i, mid)) lo = mid;
			else hi = mid - 1;
		}
		res = max(res, lo);
	}
	
	return res;
}

int calc(int x) {
	vector <pii> curr;
	int res = 0;
	for (int i = 0; i < pos[x].size(); i++) {
		if (i && pos[x][i].first > pos[x][i - 1].first + 1) {
			res = max(res, longest(curr));
			curr.clear();
		}
		curr.push_back(pos[x][i]);
	}
	res = max(res, longest(curr));
	
	return res;
}

void solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < k[i]; j++)
			pos[a[i][j]].push_back(pii(i, j));
			
	for (int i = 1; i <= M; i++)
		printf("%d\n", calc(i));
}

int main() {
	load();
	solve();
	return 0;
}