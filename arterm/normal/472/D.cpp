#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 2014
#define INF 2000000000

int n, a[M][M];
vector<pair<int, int>> d[M];
bool u[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            d[i].push_back(make_pair(a[i][j], j));
        }
        sort(d[i].begin(), d[i].end());
    }
}

bool kill() {

    for (int i = 0; i < n; ++i)
        if (a[i][i] > 0)
            return false;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != a[j][i])
                return false;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && a[i][j] == 0)
                return false;

    for (int i = 0; i + 1 < n; ++i) {
        int bs = -1, x = n;

        for (int j = 0; j < n; ++j)
            if (!u[j]) {
                while (u[d[j].back().second])
                    d[j].pop_back();
                if (d[j].back().first > bs) {
                    bs = d[j].back().first;
                    x = j;
                }
            }
        u[x] = true;

        int sm = INF, y = n;
        for (int j = 0; j < n; ++j)
            if (!u[j] && sm > a[x][j]) {
                sm = a[x][j];
                y = j;
            }

        for (int j = 0; j < n; ++j)
            if (!u[j])
                if (a[j][x] != sm + a[j][y])
                    return false;
    }

    return true;
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    read();

    if (kill())
        cout << "YES\n";
    else
        cout << "NO\n";
    
    
    return 0;
}