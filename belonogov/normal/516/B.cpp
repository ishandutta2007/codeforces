#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 2e3 + 10;
const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
char s[N][N];
int deg[N][N];
queue < pair < int, int > > q;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void merge(int x, int y, int x1, int y1) {
    if (x1 < x || (x1 == x && y1 < y)) {
        swap(x1, x);
        swap(y1, y);
    }
    if (x1 == x) {
        s[x][y] = '<';
        s[x1][y1] = '>';
    } 
    else {
        s[x][y] = '^';
        s[x1][y1] = 'v';
    }
}

void f(int x, int y) {
    for (int k = 0; k < 4; k++) {
        int x1 = x + dx[k];
        int y1 = y + dy[k];
        if (s[x1][y1] == '.') {
            deg[x1][y1]--;
            if (deg[x1][y1] == 1)
                q.push(mp(x1, y1));
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.') continue;
            for (int k = 0; k < 4; k++) {
                int x1 = i + dx[k];
                int y1 = j + dy[k];
                if (check(x1, y1) && s[x1][y1] == '.')
                    deg[i][j]++;
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (deg[i][j] == 1) {
                q.push(mp(i, j));
            }
        }
    while (!q.empty()) {
        auto tmp = q.front();
        int x = tmp.fr;
        int y = tmp.sc;
        q.pop();
        if (s[x][y] != '.') continue;
        int x1 = -1;
        int y1 = -1;
        bool flag = 0;
        for (int k = 0; k < 4; k++) {
            x1 = x + dx[k];
            y1 = y + dy[k];
            if (check(x1, y1) && s[x1][y1] == '.') {
                merge(x, y, x1, y1); 
                flag = 1;
                break;
            }
        }
        if (flag) {
            f(x, y);          
            f(x1, y1);
        }
    }
    bool flag = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            flag &= s[i][j] != '.';
    if (!flag) {
        printf("Not unique\n");
    }
    else {
        for (int i = 0; i < n; i++)
            printf("%s\n", s[i]);
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}