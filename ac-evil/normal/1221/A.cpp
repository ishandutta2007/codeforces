#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

map<int, int> FK;

int T, n;
int a[105];
int cnt[33];

int main() {
	T = read();
	rep(i, 0, 29) FK[1<<i] = i;
	while (T--) {
		n = read();
		rep(i, 0, 30) cnt[i] = 0;
		rep(i, 1, n) a[i] = read(), cnt[FK[a[i]]]++;
		rep(i, 0, 10) {
			cnt[i+1] += cnt[i]>>1;
		}
		if (cnt[11]) printf("YES\n"); else printf("NO\n");
	}

    return 0;
}