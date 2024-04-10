#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1005, gox[] = {-1, 0, 1, 0}, goy[] = {0, -1, 0, 1};
char c[MAXN][MAXN];
int p[MAXN * MAXN], ts[MAXN * MAXN];

int get(int x) {
    return p[x] == x? x : p[x] = get(p[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x == y)
        return;
    if(ts[x] < ts[y])
        swap(x, y);
    ts[x] += ts[y];
    p[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n * m; i++) {
        p[i] = i;
        ts[i] = 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m - 1; j++)
            if(c[i][j] == '.' && c[i][j + 1] == '.')
                unite(i * m + j, i * m + j + 1);
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m; j++)
            if(c[i][j] == '.' && c[i + 1][j] == '.')
                unite(i * m + j, (i + 1) * m + j);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(c[i][j] == '.')
                continue;
            int cnt = 1;
            set<int> st;
            for(int d = 0; d < 4; d++) {
                int x = i + gox[d], y = j + goy[d];
                if(x < 0 || x >= n || y < 0 || y >= m || c[x][y] != '.')
                    continue;
                int comp = get(x * m + y);
                if(st.find(comp) != st.end())
                    continue;
                cnt += ts[comp];
                st.insert(comp);
            }
            c[i][j] = char('0' + (cnt % 10));
        }
    for(int i = 0; i < n; i++)
        cout << c[i] << '\n';
    return 0;
}