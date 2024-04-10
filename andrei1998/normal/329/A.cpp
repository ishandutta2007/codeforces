#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100 + 5;

int N;
string mat[NMAX];

void tryLin() {
    vector <pair <int, int> > sol;
    for (int i = 1; i <= N; ++ i) {
        bool ok = false;
        for (int j = 1; j <= N && !ok; ++ j)
            if (mat[i][j] == '.') {
                sol.emplace_back(i, j);
                ok = true;
            }
        if (!ok)
            return ;
    }
    for (auto it: sol)
        cout << it.first << ' ' << it.second << endl;
    exit(0);
}

void tryCol() {
    vector <pair <int, int> > sol;
    for (int i = 1; i <= N; ++ i) {
        bool ok = false;
        for (int j = 1; j <= N && !ok; ++ j)
            if (mat[j][i] == '.') {
                sol.emplace_back(j, i);
                ok = true;
            }
        if (!ok)
            return ;
    }
    for (auto it: sol)
        cout << it.first << ' ' << it.second << endl;
    exit(0);
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i];
    }

    tryLin();
    tryCol();

    cout << "-1\n";
    return 0;
}