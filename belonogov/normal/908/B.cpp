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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 55;
const int INF = 1.01e9;
typedef vector<int> vi;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};


char s[N][N];

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    string t; 
    cin >> t;
    int answer = 0;
    vector<int> perm;
    for (int i = 0; i < 4; i++) {
        perm.pb(i);
    }
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }


    do {
        bool ok = 0;
        int x = sx;
        int y = sy;
        for (auto ch: t) {
           int dir = perm[ch - '0'];
            int xx = dx[dir] + x;
            int yy = dy[dir] + y;
            if (0 <= xx && xx < n && 0 <= yy && yy < m && s[xx][yy] != '#') {
                x = xx;
                y = yy; 
            }
            else {
                break;
            }
            if (s[x][y] == 'E') {
                ok = 1;
                break;
            }
 
        }
        answer += ok;

    } while (next_permutation(all(perm)));

    cout << answer << endl;


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}