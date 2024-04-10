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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k;

void read() {
    scanf("%d%d%d", &n, &m, &k);
    //db3(n, m, k);
}
set < pair < int, int > > forCheck;

int getAll(int n, int m) {
    return 4 * (n - 1) * (m - 1);
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

vector<pair<int,int>> norm(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3) {
    if (p2 > p3) swap(p2, p3);
    return {p1, p2, p3};
}

map < pair < pair < int, int>, int > , vector<vector<char>> > cache;

void print(vector < vector < char > > board, bool flagSwap) {
    if (flagSwap == 0) {
        cache[mp(mp(n, m), k)] = board;
        for (int i = 0; i < n; i++, puts(""))
            for (int j = 0; j < m; j++)
                printf("%c", board[i][j]);
    }
    else {
        swap(n, m);
        for (int i = 0; i < n; i++, puts(""))
            for (int j = 0; j < m; j++)
                printf("%c", board[j][i]);
    }
}

int calcRes(const vector<vector<char>>& board) {
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            for (int id = 0; id < 4; id++) {
                int x1 = i + dx[id];
                int y1 = j + dy[id];
                int x2 = i + dx[(id + 1) % 4];
                int y2 = j + dy[(id + 1) % 4];
                if (check(x1, y1) && check(x2, y2) && board[i][j] == '*' && board[x1][y1] == '*' && board[x2][y2] == '*') {
                    res++; 
                }
            }
        }
    return res;
}

bool uu[10][10];
int cc;

void dfs(int x, int y, const set<pair<int,int>>& blocked) {
    uu[x][y] = 1;
    cc++;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (check(x1, y1) && !uu[x1][y1] && blocked.count(mp(x1, y1)) == 0) {
            dfs(x1, y1, blocked);
        }
    }
}

bool brute() {
    vector < pair < int, int > > data(all(forCheck));
    int sz = data.size();
    set < pair < int, int > > g;
    for (auto p: data) {
        for (int i = 0; i < 4; i++) {
            int x = p.fr + dx[i];
            int y = p.sc + dy[i];
            g.insert(mp(x, y));
        }
    }
    set < vector < pair < int, int > > > tri;
    
    for (auto p: g) {
        for (int i = 0; i < 4; i++) {
            int x1 = p.fr + dx[i];
            int y1 = p.sc + dy[i];
            int x2 = p.fr + dx[(i + 1) % 4];
            int y2 = p.sc + dy[(i + 1) % 4];
            if (check(p.fr, p.sc) && check(x1, y1) && check(x2, y2)) 
                tri.insert(norm(p, mp(x1, y1), mp(x2, y2)));
        }  
    } 
    

    for (int mask = 0; mask < (1 << sz); mask++) {
        //mask = 27;
        set<pair<int,int>> blocked;
        for (int i = 0; i < sz; i++) 
            if (((mask >> i) & 1) == 1) {
                blocked.insert(data[i]);
            }                
        int cnt = getAll(n, m);
        for (auto tr: tri) {
            bool flag = 0;
            flag |= blocked.count(tr[0]) == 1;
            flag |= blocked.count(tr[1]) == 1;
            flag |= blocked.count(tr[2]) == 1;
            cnt -= flag;
        }
        bool con = 1;
        if (n * m <= 16) {
            memset(uu, 0, sizeof(uu));
            bool ff = 0;
            for (int i = 0; !ff && i < n; i++)
                for (int j = 0; !ff && j < m; j++) {
                    if (blocked.count(mp(i, j)) == 0) {
                        cc = 0;
                        dfs(i, j, blocked);
                        //db2(cc + blocked.size(), n * m);
                        if (cc + (int)blocked.size() == n * m)
                            con = 1;
                        else
                            con = 0;
                        ff = 1;
                        break;
                    }
                }
        }
        //db3(con, cnt, k);
        if (con && n * m <= 16 && cache.count(mp(mp(n, m), cnt)) == 0) {
            vector<vector<char>> board(n, vector<char>(m, '*'));
            for (auto p: blocked)
                board[p.fr][p.sc] = '.';
            cache[mp(mp(n, m), cnt)] = board;
        }
        if (cnt == k && con) {
            vector<vector<char>> board(n, vector<char>(m, '*'));
            for (auto p: blocked)
                board[p.fr][p.sc] = '.';
            assert(calcRes(board) == k);
            print(board, 0);
            return 1;
        }
        //exit(0);
    }
    return 0;
}



void solve() {
    if (getAll(n, m) == k + 1 || getAll(n, m) == k + 2 || getAll(n, m) == k + 4 || getAll(n, m) == k + 5) {
        puts("-1");
        return;
    }
    //db(cache.size());
    if (cache.count(mp(mp(n, m), k)) == 1) {
        print(cache[mp(mp(n, m), k)], 0);
        return;
    }
    if (k == 0) {
        vector<vector<char>> board(n, vector<char>(m, '.'));
        board[0][0] = '*';
        print(board, 0);
        return;
    }
    forCheck.clear();
    if (n * m <= 16) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                forCheck.insert(mp(i, j));
        if (brute())
            return;
        else {
            puts("-1");
            return;
        }
    }
    else {
        forCheck.clear();
        for (int i = 0; i < 3; i++){
            forCheck.insert(mp(0, i));
            forCheck.insert(mp(0, m - 1 - i));
        }
        if (brute())
            return;
        forCheck.clear();
        for (int i = 0; i < 3; i++){
            forCheck.insert(mp(i, 0));
            forCheck.insert(mp(n - 1 - i, 0));
        }
        if (brute())
            return;
    }

    bool flagSwap = 0;
    if (n > m) {
        swap(n, m);
        flagSwap = 1;
    }

    if (k > getAll(n, m)) {
        puts("-1");
        return;
    }
    int cur = 1;
    for (; getAll(cur + 1, m) <= k; cur++);

    assert(m >= 5);
    int curM = 0;
    int need = k - getAll(cur, m);
    //db(need);
    for (; ((curM + 1) - 1) * 4 + 1 <= need; curM++);

    if (curM >= 1)
        need -= (curM - 1) * 4 + 1;

    //db(need);
    vector<vector<char>> board(n, vector<char>(m, '.'));
    for (int i = 0; i < cur; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = '*';
    for (int j = 0; j < curM; j++)
        board[cur][j] = '*';
    int xup = min(need, m - curM - 1);

    need -= xup;
    for (int j = m - xup; j < m; j += 2)
        board[cur][j] = '*';

    //print(board, 0);
    //db(need);

    if (need > 0 && cur + 1 < n) {
        //assert(cur + 1 < n);
        for (int j = need - 1; j >= 0; j -= 2)
            board[cur + 1][j] = '*';
        assert(need < curM);
        need = 0;
    }
    int res = calcRes(board);
    assert(res + need == k);

    if (need == 0) {
        print(board, flagSwap);
        return;
    }
    else 
        puts("-1");



}

void stress() {
    n = 4;
    m = 4;
    int T = (n - 1) * (m - 1) * 4;
    for (int t = 0; t <= T; t++) {
        k = t;
        db3(n, m, k);
        solve();
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    //printf(".*.\n***\n.*.\n\n");
    //printf("**.\n**.\n*..\n\n");
    //printf(".*.\n***\n*..\n");
    //return 0;
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            //db(tt);
            read();
            solve();
            if (tt + 1 != k)
                puts("");
        }
    }
    else {
        stress();
    }

    return 0;
}