#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int defX[4] = {1, 0, -1, 0};
const int defY[4] = {0, 1, 0, -1};

int n, m;
vector<vector<char> > mat;
vector<vector<int> > tp, from;

void bfs(int x, int y, int id) {
    queue< pair<int, int> > Q;

    Q.push(mp(x, y));
    tp[x][y] |= id;

    while (!Q.empty()) {
        auto act = Q.front(); Q.pop();
        x = act.first;
        y = act.second;

        for (int i = (id - 1) * 2; i < id * 2; i++) {
            int xx = x + defX[i];
            int yy = y + defY[i];

            if (xx < 0 || xx >= n) continue;
            if (yy < 0 || yy >= m) continue;
            if (mat[xx][yy] == '#') continue;

            if (!(tp[xx][yy] & id)) {
                tp[xx][yy] |= id;
                Q.push(mp(xx, yy));
            }
        }
    }
}

void find_neck() {
    queue< pair<int, int> > Q;
    int visible = 0;

    Q.push(mp(0, 0));
    while (!Q.empty()) {
        auto act = Q.front(); Q.pop();
        int x = act.first;
        int y = act.second;

        if (Q.empty() && visible == 0 && act != mp(n - 1, m - 1) && act != mp(0, 0)) {
            cout << 1;
            exit(0);
        }

        for (int i = 0; i < 2; i++) {
            int xx = defX[i] + x;
            int yy = defY[i] + y;

            if (xx < 0 || xx >= n) continue;
            if (yy < 0 || yy >= m) continue;
            if ((tp[xx][yy] & 3) != 3) continue;

            if (--from[xx][yy] == 0) {
                if (tp[xx][yy] & 4) visible--;
                Q.push(mp(xx, yy));
                //cerr << "add " << xx << ' ' << yy << '\n';
            } else {
                visible++;
                tp[xx][yy] |= 4;
            }
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);
    
   /* 
    freopen("test.in","w",stdout);
    cout << "1000 1000\n";
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++)
            cout << (i & j & 1 ? "#" : ".");
        cout << '\n';
    }
    return 0;
    */

    scanf("%d%d\n", &n, &m);
    mat = vector< vector<char> >(n, vector<char>(m + 1, '.'));
    tp = vector< vector<int> >(n, vector<int>(m + 1, 0));
    from = tp;

    for (int i = 0; i < n; i++)
        scanf("%s\n", &mat[i][0]);

    bfs(0, 0, 1);
    bfs(n - 1, m - 1, 2);

    if (tp[n - 1][m - 1] != 3) {
        cout << 0;
        return 0;
    }


    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < m; j++)
            if (tp[i][j] == 3)
                from[i + 1][j]++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j + 1 < m; j++)
            if (tp[i][j] == 3)
                from[i][j + 1]++;

/*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", from[i][j]);
        printf("\n");
    }
    */
    find_neck();
    
    cout << 2;
    return 0;
}