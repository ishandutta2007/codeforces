#include <bits/stdc++.h>

using namespace std;

int g[10][10];
vector <int> perm;

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        perm.push_back(i);
    }
    int res = 0;
    do {
        int fun = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = i; j + 1 < 5; j += 2) {
                fun += g[perm[j]][perm[j + 1]] + g[perm[j + 1]][perm[j]];
            }
        }
        res = max(res, fun);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << res << endl;
}