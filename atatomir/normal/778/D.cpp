#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 55
#define magic vector< pair<int, int> >

int n, m, i, j;
char mat[maxN][maxN];
magic op1, op2;

void no_sol() {
    printf("-1");
    exit(0);
}

void execute(int x, int y) {
    if (mat[x][y] == 'U') {
        if (mat[x + 1][y] != 'D') no_sol();
        if (mat[x][y + 1] != 'U') no_sol();
        if (mat[x + 1][y + 1] != 'D') no_sol();

        mat[x][y] = mat[x + 1][y] = 'L';
        mat[x][y + 1] = mat[x + 1][y + 1] = 'R';

        return;
    }
    if (mat[x][y] == 'L') {
        if (mat[x + 1][y] != 'L') no_sol();
        if (mat[x][y + 1] != 'R') no_sol();
        if (mat[x + 1][y + 1] != 'R') no_sol();

        mat[x][y] = mat[x][y + 1] = 'U';
        mat[x + 1][y] = mat[x + 1][y + 1] = 'D';

        return;
    }

    no_sol();
}

void setLR(int x, int y, magic& dest);

void setUD(int x, int y, magic& dest) {
    if (mat[x][y] == 'U')
        return;

    if (mat[x + 1][y] != 'L') setLR(x + 1, y, dest);
    dest.pb(mp(x, y));
    execute(x, y);
}

void setLR(int x, int y, magic& dest) {
    if (mat[x][y] == 'L')
        return;

    if (mat[x][y + 1] != 'U') setUD(x, y + 1, dest);
    dest.pb(mp(x, y));
    execute(x, y);
}

void solve(magic& dest) {
    int i, j;

    if (n % 2 == 0) {
        for (i = 1; i <= n; i += 2)
            for (j = 1; j <= m; j++)
                setUD(i, j, dest);
    } else {
        for (j = 1; j <= m; j += 2)
            for (i = 1; i <= n; i++)
                setLR(i, j, dest);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) scanf("%s\n", mat[i] + 1);
    solve(op1);

    for (i = 1; i <= n; i++) scanf("%s\n", mat[i] + 1);
    solve(op2);

    reverse(op2.begin(), op2.end());
    printf("%d\n", op1.size() + op2.size());
    for (auto e : op1)
        printf("%d %d\n", e.first, e.second);
    for (auto e : op2)
        printf("%d %d\n", e.first, e.second);


    return 0;
}