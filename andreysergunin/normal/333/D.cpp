#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 1010;

int main() {
    int n, m;
    cin >> n >> m;
    int a[MAXN][MAXN];
    vector< pair<int, int> > p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int c;
            scanf("%d", &c);
            p.push_back(make_pair(c, i * m + j));
        }
    sort(p.begin(), p.end());
    int u[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            u[i][j] = 0;
    
    for (int i = n * m - 1; i >= 0; i--) {
        int x = p[i].second / m;
        int y = p[i].second % m;
        
        for (int j = 0; j < n; j++)
            if (x != j && a[j][y] == 1 && u[x][j] == 1) {
                cout << p[i].first << endl;
                return 0;
            }
        for (int j = 0; j < n; j++)
            if (x != j && a[j][y] == 1) {
                u[x][j] = 1;
                u[j][x] = 1;
            }
        a[x][y] = 1;
    }
    return 0;
}