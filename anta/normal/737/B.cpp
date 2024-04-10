#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int a; int b; int k;
	while(~scanf("%d%d%d%d", &n, &a, &b, &k)) {
		char s[200001];
		scanf("%s", s);
		//sum x_i/b < a
		vi blocks;
		{
			int L = 0;
			rep(i, n + 1) {
				if(i == n || s[i] == '1') {
					int size = i - L;
					rep(k, size / b)
						blocks.push_back(L + k * b);
					L = i + 1;
				}
			}
		}
		vector<int> ans;
		rep(i, (int)blocks.size() - (a - 1))
			ans.push_back(blocks[i] + (b - 1));
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}