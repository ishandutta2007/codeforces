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
	int n;
	while(~scanf("%d", &n)) {
		char s[10];
		scanf("%s", s);
		vpii v;
		for(const char *p = s; *p; ++ p) {
			int d = *p - '0';
			int y, x;
			if(d == 0)
				y = 3, x = 1;
			else
				y = (d - 1) / 3, x = (d - 1) % 3;
			v.emplace_back(y, x);
		}
		bool ans = true;
		rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
			bool a = true;
			for(auto p : v) {
				int yy = p.first + dy, xx = p.second + dx;
				a &= 0 <= yy && yy <= 3 && 0 <= xx && xx <= 2 && (yy <= 2 || xx == 1);
			}
			ans &= !a;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}