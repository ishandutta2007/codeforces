#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

pair<int, int> countBandC(int x, int y) {
	int contains = 0;
	int t = x;
	rep(j, 4) {
		contains |= 1 << (t % 10);
		t /= 10;
	}
	int ib = 0, ic = 0;
	rep(j, 4) {
		int a = x % 10, b = y % 10;
		ib += a == b;
		ic += a != b && (contains >> b & 1);
		x /= 10, y /= 10;
	}
	return make_pair(ib, ic);
}

bool isDistinct(int x) {
	int used = 0;
	bool ok = true;
	rep(j, 4) {
		ok &= (used & (1 << (x % 10))) == 0;
		used |= 1 << (x % 10);
		x /= 10;
	}
	return ok;
}

uint64_t hashCoeffs[10000];
mt19937 globalRE;
unordered_map<uint64_t, pair<int,int>> memo;

uint64_t calcHash(const vector<int> &candidates) {
	uint64_t h = 0;
	for (int x : candidates)
		h += hashCoeffs[x];
	return h;
}

int improve(const vector<int> &candidates) {
	if (candidates.size() == 1)
		return 0;
	uint64_t h = calcHash(candidates);
	auto &memop = memo[h];
	if (memop.second == 0) memop = { -1, INF };
	int x = memop.first;
	if (x == -1 || globalRE() % 3 == 0)
		x = candidates[globalRE() % candidates.size()];
	vi ncs[5][5];
	for (int y : candidates) {
		auto bc = countBandC(x, y);
		ncs[bc.first][bc.second].push_back(y);
	}
	int maxT = 0;
	rep(b, 5) rep(c, 5) if (!ncs[b][c].empty()) {
		int t = improve(ncs[b][c]);
		amax(maxT, t + 1);
	}
	if (maxT < memop.second) {
		memop = { x, maxT };
	}
	return memop.second;
}

int main() {
	{
		mt19937_64 RE;
		rep(x, 10000)
			hashCoeffs[x] = RE();
	}
	{
		vector<int> candidates;
		rep(i, 10000) {
			if (isDistinct(i))
				candidates.push_back(i);
		}
		rep(kk, 100)
			improve(candidates);
	}
	vector<int> candidates;
	rep(i, 10000) {
		if (isDistinct(i))
			candidates.push_back(i);
	}
	while (1) {
		int x = candidates.size() == 1 ? candidates[0] : memo[calcHash(candidates)].first;
		printf("%04d\n", x);
		fflush(stdout);
		auto t = countBandC(x, 1234);
		pair<int, int> bc;
		scanf("%d%d", &bc.first, &bc.second);
		if (bc.first == 4)
			break;
		vi ncs;
		for (int y : candidates) {
			if (countBandC(x, y) == bc)
				ncs.push_back(y);
		}
		candidates.swap(ncs);
	}
	return 0;
}