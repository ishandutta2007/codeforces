#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 111;
const int INF = 1e9 + 19;

int n, m;
char s[N][N];
int color[N][N];
int use[N];


void read() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
}

void rec(int x, int y);

void callNext(int x, int y) {
	y++;
	if (y == m) {
		y = 0;
		x++;
	}
	rec(x, y);
}

long long answer;
set < pair < int, int > > q;	

void add(int x1, int y1, int x2, int y2) {
	int v = color[x1][y1];
	int u = color[x2][y2];
	assert(0 <= v && v <= 6);
	assert(0 <= u && u <= 6);
	if (v > u) swap(v, u);
	q.insert(mp(v, u));
}
int cc = 0;
char ser[N][N];
int t[N];
int tmr;
vector < pair < int, int > > p1;
vector < pair < int, int > > p2;

void rec(int x, int y) {
    //cc++;
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << color[i][j] << " ";
    //db2(x, y);
    //cerr << endl;

    tmr++;
    for (int i = 0; i < (int)p1.size(); i++) {
        int v = color[p1[i].fr][p1[i].sc];
        int u = color[p2[i].fr][p2[i].sc];
        if (v != -1 && u != -1) {
            if (v > u)
                swap(v, u);
            int id = v * 7 + u;
            if (t[id] == tmr) return;
            t[id] = tmr;
        }
    }

	if (x == n && y == 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '.')
                    ser[i][j] = '.';
                else
                    ser[i][j] = '0' + color[i][j];
        answer++;
		return;
	}
	if (s[x][y] == '.') {
		callNext(x, y);
		return;
	}
	if (color[x][y] != -1) {
		callNext(x, y);
		return;
	}
	if (color[x][y] == -1) {
        for (int i = 0; i < 7; i++) {
            if (use[i] <= 1) {
                use[i]++;
                for (int dx = 0; dx < 2; dx++)
                    for (int dy = 0; dy < 2; dy++)
                        color[x + dx][y + dy] = i;
                callNext(x, y);
                use[i]--;
            }
            if (use[i] == 0) 
                break;
        }
		for (int dx = 0; dx < 2; dx++)
			for (int dy = 0; dy <  2; dy++)
				color[x + dx][y + dy] = -1;
	}

}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (s[i][j] != '.') {
                if (s[i][j] == s[i + 1][j]) {
                    p1.pb(mp(i, j));
                    p2.pb(mp(i + 1, j));
                }
                if (s[i][j] == s[i][j + 1]) {
                    p1.pb(mp(i, j));
                    p2.pb(mp(i, j + 1));
                }
            }
            
    assert(p1.size() == 28);

	memset(color, -1, sizeof(color));
	rec(0, 0);
    //db(cc);
	//db(answer);
	for (int i = 1; i <= 7; i++)
		answer *= i;

	//for (int i = 0; i < n; i++, cerr << endl)
		//cerr << use[i] << " ";
		//for (int j = 0; j < m; j++)
			//cerr << color[i][j] << " ";

	printf("%lld\n", answer);
	for (int i = 0; i < n; i++)
		printf("%s\n", ser[i]);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}