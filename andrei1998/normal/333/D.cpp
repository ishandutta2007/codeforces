#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int NMAX = 1000 + 5;

int n, m;
int mat[NMAX][NMAX];
vector <pair <int, pair <int, int> > > all_of_mat;

vector <int> active_cols[NMAX];
int links[NMAX][NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            cin >> mat[i][j];
            all_of_mat.push_back(make_pair(-mat[i][j], make_pair(i, j)));
        }

    sort(all_of_mat.begin(), all_of_mat.end());
    for (auto elem: all_of_mat) {
        int lin = elem.second.first;
        int col = elem.second.second;

        for (auto it: active_cols[lin]) {
            ++ links[it][col];
            ++ links[col][it];

            if (links[it][col] > 1) {
                cout << -elem.first << '\n';
                return 0;
            }
        }
        active_cols[lin].push_back(col);
    }
    return 0;
}