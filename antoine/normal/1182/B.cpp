#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


void no() {
    cout << "NO";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &s : grid)
        cin >> s;

    int cx = -1, cy = -1;
    for (int i = 1; i + 1 < n; ++i)
        for (int j = 1; j + 1 < m; ++j) {
            if (grid[i][j] == '*') {
                if (grid[i + 1][j] == '*')
                    cy = j;
                if (grid[i][j + 1] == '*')
                    cx = i;
            }
        }

    if (cx == -1 || cy == -1)
        no();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == cx && j == cy) {
                if (grid[i][j] != '*')
                    no();
            } else if (i == cx) {
                if (abs(j - cy) == 1 && grid[i][j] != '*')
                    no();
                int jj = j + (j < cy ? 1 : -1);
                if (grid[i][j] == '*' && grid[i][jj] != '*')
                    no();
            } else if (j == cy) {
                if (abs(i - cx) == 1 && grid[i][j] != '*')
                    no();
                int ii = i + (i < cx ? 1 : -1);
                if (grid[i][j] == '*' && grid[ii][j] != '*')
                    no();
            } else {
                if (grid[i][j] == '*')
                    no();

            }
        }
    }
    cout << "YES";


    return 0;
}