#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int K;
	while (~scanf("%d", &K)) {
		string ans = "z";
		for (char a = 'a'; K > 0; ++ a) {
			int n = 1;
			for (; n * (n + 1) / 2 <= K; ++ n);
			ans += string(n, a);
			K -= n * (n - 1) / 2;
		}
		puts(ans.c_str());
	}
	return 0;
}