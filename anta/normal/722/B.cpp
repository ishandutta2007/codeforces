#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool isv(char c) { return strchr("aeiouy", c) != 0; }

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> p(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &p[i]);
		while(getchar()!='\n');
		bool ans = true;
		rep(i, n) {
			string line;
			getline(cin, line);
			stringstream ss(line);
			string word;
			int cnt = 0;
			while(ss >> word) {
				int vs = 0;
				for(char c : word)
					vs += isv(c);
				cnt += vs;
			}
			ans &= cnt == p[i];
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}