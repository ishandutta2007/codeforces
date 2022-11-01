#pragma comment (linker, "/STACK:128000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <sstream>
#include <stack>
#include <cassert>
#include <list>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;
    
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const char let[4] = {'D', 'L', 'R', 'U'};


int n, m, k;
vector <vector <char> > a;

pair <int, int> get(pair <int, int> x, int dir) {
    return mp(x.first + dx[dir], x.second + dy[dir]);
}

bool is_valid(pair <int, int> x) {
    return x.first >= 0 && x.second >= 0 && x.first < n && x.second < m && a[x.first][x.second] == '.';
}

vector <vector <int> > bfs(pair <int, int> start) {
    vector <vector <int> > result(n, vector <int> (m, -1));
    result[start.first][start.second] = 0;
    
    queue <pair <int, int> > q;
    q.push(start);
    while (!q.empty()) {
        pair <int, int> cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            pair <int, int> go = get(cur, i);
            if (is_valid(go) && result[go.first][go.second] == -1) {
                result[go.first][go.second] = result[cur.first][cur.second] + 1;
                q.push(go);
            }
        }
    }
    
    return result;
}

void printerr() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void solve() {

    cin >> n >> m >> k;
    if (k & 1) {
        printerr();
    }
    
    a = vector < vector <char> > (n, vector <char> (m));
    pair <int, int> start;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'X') {
                start = mp(i, j);
                a[i][j] = '.';
            }
        }
    }
    
    vector <vector <int> > dists = bfs(start);
    string result;
    
    pair <int, int> cur = start;
    
    while (result.size() < k) {
        bool ok = false;
        pair <int, int> go;
        for (int i = 0; i < 4; ++i) {
            go = get(cur, i);
            if (is_valid(go) && dists[go.first][go.second] + 1 <= k - result.size()) {
                ok = true;
                cur = go;
                result.push_back(let[i]);
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    
    if (result.size() == k && cur == start) {
        cout << result << endl;
    } else {
        printerr();
    }
    
}