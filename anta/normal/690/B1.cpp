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
	int N;
	while(~scanf("%d", &N)) {
		vector<string> v(N);
		rep(i, N)
			cin >> v[i];
		int miX = N - 1, maX = 0, miY = N - 1, maY = 0;
		rep(i, N) rep(j, N) if(v[i][j] == '4') {
			amin(miX, j);
			amax(maX, j);
			amin(miY, i);
			amax(maY, i);
		}
		bool ans = true;
		rep(i, N) rep(j, N) {
			int cnt = 0;
			rep(dy, 2) rep(dx, 2) {
				int yy = i + dy, xx = j + dx;
				cnt += miY <= yy && yy <= maY + 1 && miX <= xx && xx <= maX + 1;
			}
			ans &= cnt == v[i][j] - '0';
		}
		puts(ans ? "Yes" : "No");
	}
	return 0;
}