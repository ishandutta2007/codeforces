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
const int N = 1111;
const long long INF = 1e9 + 19;

struct Board {
    bool board[N][N];
    int pref[N][N];
    int p[N];
    int l[N];
    int r[N];
    bool use[N];

    int n, m;
    Board() {
        memset(board, 0, sizeof(board));
        memset(pref, 0, sizeof(pref));
    }

    void init(vector < vector < int > > & data, int _n, int _m) {
        n = _n;
        m = _m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = data[i][j];
        for (int i = 0; i < n; i++)
            upd(i);
    }
    void upd(int i)  {
        for (int j = m - 1; j >= 0; j--) {
            pref[i][j] = (board[i][j])? pref[i][j + 1] + 1: 0;
        }
    }
    void updCell(int x, int y) {
        board[x][y] ^= 1;
        upd(x);
    }
    int getId(int v) {
        return (p[v] == v)? v: p[v] = getId(p[v]);
    }

    void merge(int v, int u) {
        v = getId(v);
        u = getId(u);
        p[u] = v;
        l[v] = min(l[v], l[u]);
        r[v] = max(r[v], r[u]); 
    }

    int get(int x, int y) {
        //db2(x, y);
        if (board[x][y] == 0) return 0;
        for (int i = 0; i < n; i++) {
            p[i] = i;
            l[i] = i;
            r[i] = i;            
            use[i] = 0;
        }
        vector < pair < int, int > > event;  
        for (int i = 0; i < n; i++)
            if (board[i][y]) {
                event.pb(mp(pref[i][y], i));
            }
        //db(n);
        //for (auto x: event)
            //db2(x.fr, x.sc);
        //cerr << endl;
        sort(event.rbegin(), event.rend());
        int answer = 0;
        for (auto e: event) {
            use[e.sc] = 1; 
            //db2(x.sc, y);
            for (int shift = -1; shift <= 1; shift += 2) {
                int nei = e.sc + shift;
                if (0 <= nei && nei < n && use[nei]) {
                    merge(nei, e.sc); 
                }
            }
            if (use[x]) {
                //db("here");
                int v = getId(x);
                answer = max(answer, e.fr * (r[v] - l[v] + 1));
            }
        }
        return answer;
    }
    
};

int n, m, q;
int a[N][N];
int b[N][N];
Board h[4];

void read() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

}

void getRot(int i, int j, int & x, int & y) {
    x = n - 1 - j;
    y = i;
}

void solve() {
    n = max(n, m); 
    for (int t = 0; t < 4; t++) {
        vector < vector < int > > data(n, vector < int > (n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                data[i][j] = a[i][j];
        h[t].init(data, n, n);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)  {
                int x, y;
                getRot(i, j, x, y);
                b[x][y] = a[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = b[i][j];
    }
    
    for (int t = 0; t < q; t++) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y); x--; y--;
        if (type == 1) {
            for (int tt = 0; tt < 4; tt++) {
                h[tt].updCell(x, y);
                int x1, y1;
                getRot(x, y, x1, y1);
                x = x1;
                y = y1; 
            }
        }
        if (type == 2) {
            int answer = 0;
            for (int tt = 0; tt < 4; tt++) {
                int res = h[tt].get(x, y);
                //db(res);
                answer = max(answer, res);
                int x1, y1;
                getRot(x, y, x1, y1);
                x = x1;
                y = y1;
            }
            printf("%d\n", answer);
        }
    }

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