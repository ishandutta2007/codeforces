#include <iostream>
#include <cstdlib>

#define int long long int
using namespace std;

const int NMAX = 500000 + 5;

int n, klin, kcol;
char type[NMAX];
int l[NMAX];
int c[NMAX];

int dist(int l1, int c1, int l2, int c2) {
    return abs(l1 - l2) + abs(c1 - c2);
}

bool works(int l, int c, int dl, int dc) {
    int lin = l - klin;
    int col = c - kcol;

    if (dl == 0) {
        if (lin != 0)
            return false;
        if (dc == 1)
            return col > 0;
        else if (dc == -1)
            return col < 0;
    }

    if (dc == 0) {
        if (col != 0)
            return false;
        if (dl == 1)
            return lin > 0;
        else if (dl == -1)
            return lin < 0;
    }

    if (abs(lin) != abs(col))
        return false;

    lin /= abs(lin);
    col /= abs(col);

    if (lin != dl || col != dc)
        return false;
    else
        return true;
}

int dlin[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dcol[8] = {1, 0, -1, 1, -1, 1, 0, -1};

bool check(int dl, int dc) {
    int small_dist = 1e16;
    int who = 0;
    for (int i = 1; i <= n; ++ i) {
        if (works(l[i], c[i], dl, dc)) {
            if (dist(klin, kcol, l[i], c[i]) < small_dist) {
                small_dist = dist(klin, kcol, l[i], c[i]);
                who = i;
            }
        }
    }

    if (who == 0)
        return false;
    if (type[who] == 'Q')
        return true;

    if (abs(dl) + abs(dc) == 1)
        return type[who] == 'R';
    if (abs(dl) + abs(dc) == 2)
        return type[who] == 'B';
    return false;
}

signed main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> klin >> kcol;

    for (int i = 1; i <= n; ++ i)
        cin >> type[i] >> l[i] >> c[i];

    for (int k = 0; k < 8; ++ k)
        if (check(dlin[k], dcol[k])) {
            cout << "YES\n";
            return 0;
        }

    cout << "NO\n";
    return 0;
}