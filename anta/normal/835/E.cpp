#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

#ifdef MY_LOCAL_RUN
//#define TEST
#endif

#ifdef TEST
vector<int> mySeq;
int myP1, myP2;
int queries;
#endif

bool query(const vector<int> &poses, int x, int y) {
	assert(!poses.empty());
#ifndef TEST
	printf("? %d", (int)poses.size());
	for (int x : poses)
		printf(" %d", x + 1);
	puts("");
	fflush(stdout);
	int A;
	scanf("%d", &A);
#else
	++ queries;
	int A = 0;
	for (int i : poses)
		A ^= mySeq[i];
#endif
	if (poses.size() % 2 == 0) {
		assert(A == 0 || A == (x ^ y));
		return A != 0;
	} else {
		assert(A == x || A == y);
		return A == y;
	}
}

int main() {
	mt19937 myRE;
	int n; int x; int y;
#ifndef TEST
	while (~scanf("%d%d%d", &n, &x, &y)) {
#else
	while (1) {
		n = 1000;
		do x = myRE() % 10, y = myRE() % 10; while (x == y);
		do {
			myP1 = myRE() % n, myP2 = myRE() % n;
		} while (myP1 == myP2);
		if (myP1 > myP2) swap(myP1, myP2);
		mySeq.assign(n, x);
		mySeq[myP1] = mySeq[myP2] = y;
		queries = 0;
#endif

		auto solve = [x, y](vector<int> S) {
			while (S.size() > 1) {
				vector<int> T(S.begin(), S.begin() + S.size() / 2);
				if (query(T, x, y))
					S = T;
				else
					S.erase(S.begin(), S.begin() + S.size() / 2);
			}
			return S[0];
		};
		int ans1, ans2;
		vector<vi> history;
		for(int k = 0; ; ++ k) {
			vector<int> v;
			rep(i, n) if (i >> k & 1)
				v.push_back(i);
			if (query(v, x, y)) {
				ans1 = solve(v);
				vector<bool> intersection(n, true);
				for (int i : v)
					intersection[i] = false;
				for (auto &&w : history) {
					vector<bool> inW(n);
					for (int i : w) inW[i] = true;
					bool in = find(w.begin(), w.end(), ans1) != w.end();
					rep(i, n) if(inW[i] != in)
						intersection[i] = false;
				}
				vector<int> w;
				rep(i, n) if (intersection[i])
					w.push_back(i);
				ans2 = solve(w);
				break;
			} else {
				history.push_back(v);
			}
		}
		assert(ans1 != ans2);
		if (ans1 > ans2) swap(ans1, ans2);

#ifndef TEST
		printf("! %d %d\n", ans1 + 1, ans2 + 1);
		fflush(stdout);
		break;
#else
		assert(myP1 == ans1 && myP2 == ans2);
		assert(queries <= 19);
		cerr << n << ": " << queries << endl;
#endif
	}
	return 0;
}