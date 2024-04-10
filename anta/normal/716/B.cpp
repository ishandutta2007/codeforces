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
	char s[50001];
	while(~scanf("%s", s)) {
		int n = strlen(s);
		const int A = 26;
		string ans = "-1";
		rer(i, 0, n - A) {
			int mask = 0;
			bool ok = true;
			reu(j, i, i + A) {
				if(s[j] != '?') {
					int a = s[j] - 'A';
					ok &= ~mask >> a & 1;
					mask |= 1 << a;
				}
			}
			if(ok) {
				ans = s;
				int a = 0;
				rep(j, n) {
					if(s[j] == '?') {
						if(i <= j && j < i + A) {
							while(mask >> a & 1) ++ a;
							ans[j] = 'A' + a;
							++ a;
						} else {
							ans[j] = 'A';
						}
					}
				}
				break;
			}
		}
		puts(ans.c_str());
	}
	return 0;
}