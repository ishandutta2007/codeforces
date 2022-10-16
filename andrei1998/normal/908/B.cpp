#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int N, M;
string mat[60];

string commands;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int order[4];

bool works() {
    int l, c;
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < M; ++ j)
            if (mat[i][j] == 'S')
                l = i, c = j;

    for (auto it: commands) {
        int xx = dx[order[it - '0']];
        int yy = dy[order[it - '0']];
        l += xx;
        c += yy;

        if (l < 0 || c < 0 || l >= N || c >= M || mat[l][c] == '#')
            return false;
        if (mat[l][c] == 'E')
            return true;
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++ i)
        cin >> mat[i];
    cin >> commands;
    order[0] = 0;
    order[1] = 1;
    order[2] = 2;
    order[3] = 3;

    int ans = 0;
    do {
        ans += works();
    } while (next_permutation(order, order + 4));

    cout << ans << '\n';
    return 0;
}