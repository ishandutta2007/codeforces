#include <cstdio>
#include <set>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct node {
    int a, b, c;
    node(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
    node(){}
    friend bool operator <(const node &A, const node &B) {
        if (A.c != B.c) return A.c < B.c;
        if (A.a != B.a) return A.a < B.a;
        return A.b < B.b;
    }
};

int n, m, k;
char mat[510][510];
int rx[510][510], ry[510][510];
bool bio[510][510];
int cnt[510][510];

set <node> s;

inline bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == '.';
}

void dfs(int x, int y, int px, int py) {
    rx[x][y] = px;
    ry[x][y] = py;
    bio[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny) && !bio[nx][ny]) 
            dfs(nx, ny, x, y);
    }
}

int main() {
    
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) 
        scanf("%s", mat[i]);
        
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (ok(i, j)) {
                dfs(i, j, n, m);
                i = n;
                break;
            }
    
    for (int i = 0; i < n; i++)     
        for (int j = 0; j < m; j++) 
            if (ok(i, j)) cnt[rx[i][j]][ry[i][j]]++;
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (ok(i, j)) s.insert(node(i, j, cnt[i][j]));
        
    while (k--) {
        node tmp = *s.begin();
        s.erase(s.begin());
        mat[tmp.a][tmp.b] = 'X';
        int t = cnt[rx[tmp.a][tmp.b]][ry[tmp.a][tmp.b]]--;
        s.erase(node(rx[tmp.a][tmp.b], ry[tmp.a][tmp.b], t)); t--;
        s.insert(node(rx[tmp.a][tmp.b], ry[tmp.a][tmp.b], t));
    }
        
    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < m; j++) 
            putchar(mat[i][j]);
    
    return 0;
}