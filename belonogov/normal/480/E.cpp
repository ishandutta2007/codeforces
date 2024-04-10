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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2111;
const long long INF = 1e9 + 19;

int n, m, k;
int board[N][N];
char s[N][N];
pair < int, int > add[N];
int pref[N][N];
int answer[N];
int dp[N][N];
int p[N * N];
int l[N * N];
int r[N * N];
int LUp[N];
int RUp[N];
int LDown[N];
int RDown[N];


void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &add[i].fr, &add[i].sc);
        add[i].fr--;
        add[i].sc--;
    }

}

int getPos(int x, int y) {
    return x * m + y;
}

int getSum(int x0, int y0, int x1, int y1) {
    return pref[x1][y1] - pref[x0][y1] - pref[x1][y0] + pref[x0][y0];
}

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    p[v] = u;
    l[u] = min(l[u], l[v]);
    r[u] = max(r[u], r[v]);
}

void getLR(int x, int y, int & L, int & R) {
    if (board[x][y] == 1) {
        L = m;
        R = -1;
        return;
    }
    int v = getPos(x, y);
    v = getId(v);
    L = l[v];
    R = r[v];
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = s[i][j] == 'X';

    for (int i = 0; i < k; i++) {
        assert(board[add[i].fr][add[i].sc] == 0);
        board[add[i].fr][add[i].sc] = 1;
    }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + board[i][j];

    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            for (;; ) {
                int r = dp[i][j] + 1;
                if (i + r <= n && j + r <= m && getSum(i, j, i + r, j + r) == 0) 
                    dp[i][j]++;
                else
                    break;
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
            mx = max(dp[i][j], mx);
        } 

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int id = getPos(i, j);
            p[id] = id;
            l[id] = j;
            r[id] = j;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            if (board[i][j] == 0 && board[i][j + 1] == 0) {
                merge(getPos(i, j), getPos(i, j + 1));
            }
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << board[i][j] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << getId(getPos(i, j)) << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << r[getId(getPos(i, j))] << " ";
    int ll, rr;
    getLR(3, 7, ll, rr);
    //db2(n, m);
    //db2(ll, rr);

    answer[k - 1] = mx;
    for (int t = k - 1; t >= 1; t--) {
        //db(t);
        int x = add[t].fr;
        int y = add[t].sc;
        assert(board[x][y] == 1);
        board[x][y] = 0;
        if (y > 0 && board[x][y - 1] == 0)
            merge(getPos(x, y - 1), getPos(x, y));
        if (y + 1 < m && board[x][y + 1] == 0)
            merge(getPos(x, y + 1), getPos(x, y));

        for (;;) {
            int up = max(0, x - mx);
            int down = min(x + mx, n - 1);
            int mxL = 0;
            int mnR = m;
            //db2(x, y);
            //db2(up, down);
            //db(mx);
            for (int i = x; i >= up; i--) {
                int left, right;                
                getLR(i, y, left, right);
                mxL = max(mxL, left);
                mnR = min(mnR, right);
                LUp[i] = mxL;
                RUp[i] = mnR;
            }
            mxL = 0;
            mnR = m;
            for (int i = x; i <= down; i++) {
                int left, right;
                getLR(i, y, left, right);
                mxL = max(mxL, left);
                mnR = min(mnR, right);
                LDown[i] = mxL;
                RDown[i] = mnR;
            }
            //for (int i = 0; i < n; i++)
                //db2(LUp[i], RUp[i]);
            //cerr << endl;
            //for (int i = 0; i < n; i++)
                //db2(LDown[i], RDown[i]);
            bool flag = 0;
            for (int i = x; i >= up; i--) {
                int dd = i + mx;
                //db2(dd, x);
                assert(dd >= x);
                if (dd > down) continue;
                mxL = max(LUp[i], LDown[dd]);
                mnR = min(RUp[i], RDown[dd]);
                if (mnR - mxL >= mx)
                    flag = 1;
            }
            if (!flag) break;
            mx++;
        }
        
        answer[t - 1] = mx;
    }
    for (int i = 0; i < k; i++)
        printf("%d\n", answer[i]);

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