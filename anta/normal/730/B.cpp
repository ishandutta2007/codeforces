#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int query(int i, int j) {
	printf("? %d %d\n", i + 1, j + 1);
	fflush(stdout);
	char res[2];
	scanf("%s", res);
	return *res == '<' ? -1 : *res == '=' ? 0 : 1;
}

pair<int, int> getp(int i, int j) {
	int q = query(i, j);
	return q == 1 ? make_pair(j, i) : make_pair(i, j);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ++ ii) {
		int n;
		scanf("%d", &n);
		int i, j;
		if(n % 2 == 0) {
			tie(i, j) = getp(0, 1);
		} else {
			i = j = 0;
		}
		for(int k = 2 - n % 2; k < n; k += 2) {
			auto p = getp(k, k + 1);
			i = getp(i, p.first).first;
			j = getp(p.second, j).second;
		}
		printf("! %d %d\n", i + 1, j + 1);
		fflush(stdout);
	}
	return 0;
}