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

int fx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int fy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int N;

int Map[105][105];

bool getw(int i, int j) {
	int ans = 0, cnt = 0;
	rep(o, 0, 7)
		if (i+fx[o] > 0 && j+fy[o] > 0 && i+fx[o] <= N && j+fx[o] <= N) {
			if (Map[i+fx[o]][j+fy[o]] == 0) ans++;
			cnt++;
		}
	return ans*2 > cnt;
}

int main() {
	N = read();
	rep(i, 1, N) {
		rep(j, 1, N) {
			if ((i+j)&1) printf("W"); else printf("B");
		}
		puts("");
	}
	/*
	memset(Map, -1, sizeof(Map));
	rep(i, 1, N) {
		rep(j, 1, N) {
			if (!getw(i, j)) Map[i][j] = 0; else Map[i][j] = 1;
			printf("%c", Map[i][j] ? 'W' : 'B');
		}
		puts("");
	}
	*/
	return 0;
}