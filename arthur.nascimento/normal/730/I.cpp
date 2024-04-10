#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void read(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

const int N = 3e3+7;

int n;
int x[2];
int v[N][3];
int p[N];
int memo[2][N][N];
vector<int> res[2];

bool cmp_t (int i, int j) {
	return pii(v[i][0], v[i][1]) > pii(v[j][0], v[j][1]);
}

int pd (int k, int i, int g) {
	if (k == 2) return 0;
	if (g > x[k]) return -1e7;
	if (i == n) return pd(k+1, i, i-g);
	if (g == x[k]) return pd(k+1, i, i - g);

	int & me = memo[k][i][g];
	if (me != -1) return me;
	me = max(pd(k, i+1, g+1) + v[p[i]][k], pd(k, i+1, g) + v[p[i]][k+1]);
	return me;
}

void build (int k, int i, int g) {
	if (i == n) return;
	if (k == 2) return;
	if (g > x[k]) assert(false);
	if (g == x[k]) {
		build(k+1, i, i-g);
		return;
	}

	int me = pd(k, i, g);
	if (pd(k, i+1, g+1) + v[p[i]][k] == me) {
		if (k < 2)
			res[k].push_back(p[i]);
		build(k, i+1, g+1);
		return;
	} else {
		if (k+1 < 2)
			res[k+1].push_back(p[i]);
		build(k, i+1, g);
		return;
	}
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d", &n);

	scanf("%d %d", &x[0], &x[1]);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i][0]);
		v[i][2] = 0;
		p[i] = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i][1]);

	sort(p, p+n, cmp_t);

	printf("%d\n", pd(0, 0, 0));
	build(0, 0, 0);
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < res[k].size(); i++)
			printf("%d ", res[k][i]+1);
		printf("\n");
	}
}