#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

const int N = 555;
const long long INF = 1e9 + 19;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct Box {
	int mnX, mnY, mxX, mxY;
	Box():mnX(INF), mnY(INF), mxX(-1), mxY(-1) { }
	void add(int x, int y) {
		mnX = min(mnX, x);
		mnY = min(mnY, y);
		mxX = max(mxX, x);
		mxY = max(mxY, y);
	}
};

int n, k;
char s[N][N];
int color[N][N];
int cnt[N * N];
Box box[N * N];
int use[N * N];
int tmr;
int cur;
int pref[N][N];
int s1;
int bal[N];


void gen() {
	n = 500;
	k = 250;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			s[i][j] = ((i + j) % 2 == 0)? '.': 'X';
}

bool check(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
	color[x][y] = cur;
	box[cur].add(x, y);
	cnt[cur]++;
	for (int i = 0; i < 4; i++) {
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (check(x1, y1) && s[x1][y1] == '.' && color[x1][y1] == -1) 
			dfs(x1, y1);
	}	
}


void read() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
}

int getSum(int x1, int y1, int x2, int y2) {
	return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
}

void add(int x, int y) {
	if (s[x][y] == '.') {
		int id = color[x][y];
		if (use[id] != tmr) {
			use[id] = tmr;
			s1 += cnt[id];
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (s[i][j] == 'X');


	memset(color, -1, sizeof(color));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == '.' && color[i][j] == -1) {
				dfs(i, j);
				cur++;
			}
	int answer = 0;
	for (int i = 0; i + k <= n; i++) {
		tmr++;
		memset(bal, 0, sizeof(bal));
		for (int x = i; x < i + k; x++)
			for (int y = 0; y < n; y++) {
				if (s[x][y] == '.' && use[color[x][y]] != tmr) {
					int id = color[x][y];
					use[id] = tmr;
					if (i <= box[id].mnX && box[id].mxX < i + k) {
						int l = box[id].mxY - k + 1;	
						int r = box[id].mnY + 1;
						l = max(0, l);
						if (l < r) {
							bal[l] += cnt[id];
							bal[r] -= cnt[id];
						}
					}
				}
			}
			
		int s2 = 0;
		for (int j = 0; j + k <= n; j++) {
			s2 += bal[j];

			int sum = 0;		
			sum += getSum(i, j, i + k, j + k);
			s1 = 0;
			tmr++;
			if (i - 1 >= 0)
				for (int d = 0; d < k; d++) 
					add(i - 1, j + d);
			if (i + k < n)
				for (int d = 0; d < k; d++) 
					add(i + k, j + d);
			if (j - 1 >= 0)
				for (int d = 0; d < k; d++) 
					add(i + d, j - 1);

			if (j + k < n)
				for (int d = 0; d < k; d++) 
					add(i + d, j + k);
			sum += s1;
			sum += s2;
			answer = max(answer, sum);
		}
	}

	printf("%d\n", answer);
}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
			//gen();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}