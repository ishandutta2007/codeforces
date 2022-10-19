#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

typedef pair <int, int> par;
#define x first
#define y second

const int MAXN = 300005;
const int LOG = 20;

int N;
int len[3];
char s[3][MAXN];
int rank[LOG][3][MAXN];
par suff[MAXN];
int lcp[MAXN];

inline void mul(int &a, int b) { a = (ll)a * b % MOD; }

inline void add(int &a, int b) { a = (a + b) % MOD; }

inline void sub(int &a, int b) { a = (a - b + MOD) % MOD; }

void load() {
	for (int i = 0; i < 3; i++)
		scanf("%s", s[i]);
}

int k;

bool cmp(const par &a, const par &b) {
	if (!k) return s[a.x][a.y] < s[b.x][b.y];
	if (rank[k - 1][a.x][a.y] != rank[k - 1][b.x][b.y])
		return rank[k - 1][a.x][a.y] < rank[k - 1][b.x][b.y];
	return (a.y + (1 << k - 1) >= len[a.x] && b.y + (1 << k - 1) < len[b.x]) 
            || rank[k - 1][a.x][a.y + (1 << k - 1)] < rank[k - 1][b.x][b.y + (1 << k - 1)];
}

int calc(par a, par b) {
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		if (a.y + ret + (1 << i) > len[a.x] || b.y + ret + (1 << i) > len[b.x]) continue;
		if (rank[i][a.x][a.y + ret] == rank[i][b.x][b.y + ret]) ret += 1 << i;
	}
	return ret;
}

void suffix_array() {

	for (int i = 0; i < 3; i++)
		len[i] = strlen(s[i]);

	for (int i = 0; i < 3; i++)
        for (int j = 0; j < len[i]; j++)
        	suff[N++] = par(i, j);

	for (k = 0; k < LOG; k++) {
		sort(suff, suff + N, cmp);
		for (int j = 1; j < N; j++)
			rank[k][suff[j].x][suff[j].y] = rank[k][suff[j - 1].x][suff[j - 1].y] + cmp(suff[j - 1], suff[j]);
	}

	for (int i = 0; i < N - 1; i++)
		lcp[i] = calc(suff[i], suff[i + 1]);
}

void output() {
    printf("\nSUFF\n");
	for (int i = 0; i < N; i++)
		printf("%d %d\n", suff[i].x, suff[i].y);
	printf("\nLCP\n");
	for (int i = 0; i < N - 1; i++)
        printf("%d ", lcp[i]);
    puts("");
	for (int i = 0; i < N - 1; i++) 
	    printf("%d ", suff[i].x);
	puts("");
}

int cnt[3][MAXN];
vector <int> V[MAXN];

int dad[MAXN];

int find(int x) { return dad[x] == -1 ? x : dad[x] = find(dad[x]); }

int get(int x) {
    int res = 1;
    for (int i = 0; i < 3; i++) 
        mul(res, cnt[i][x]);
    return res;
}
        
void join(int a, int b, int &c) {
	a = find(a);
	b = find(b);
	if (rand() & 1) swap(a, b);
	dad[a] = b;
	sub(c, get(a));
	sub(c, get(b));
	for (int i = 0; i < 3; i++)
        add(cnt[i][b], cnt[i][a]);
	add(c, get(b));
}

int sol[MAXN];

void solve() {
    memset(dad, -1, sizeof dad);
	for (int i = 0; i < N; i++) {
		V[lcp[i]].push_back(i);
		//dad[i] = i;
		cnt[suff[i].x][i]++;
    }
    
	int M = min(len[0], min(len[1], len[2]));
	//printf("AWOJ SWOBO %d\n", M);
	for (int i = N; i; i--) {
		for (int j = 0; j < V[i].size(); j++) {
			join(V[i][j], V[i][j] + 1, sol[i]);
			//if (i == M) printf("%d ", V[i][j]);
        }
        //if (i == M) puts("");
        add(sol[i], sol[i + 1]);	
    }

	for (int i = 1; i <= M; i++)
		printf("%d ", sol[i]);
	puts("");
}

int main() {
	load();
	suffix_array();
	//output();
	solve();
	return 0;
}