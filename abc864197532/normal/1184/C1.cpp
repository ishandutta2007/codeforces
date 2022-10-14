#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    int x[4 * n + 1], y[4 * n + 1];
    for (int i = 0; i < 4 * n + 1; ++i) cin >> x[i] >> y[i];
    int tmp[2]{0, 1}, tmp2[4];
    for (int i = 1; i < 4 * n + 1; ++i) {
        if (x[i] < x[tmp[0]]) tmp[0] = i, tmp[1] = 1;
        else if (x[i] == x[tmp[0]]) ++tmp[1];
    }
    if (tmp[1] == 1) return cout << x[tmp[0]] << ' ' << y[tmp[0]], 0;
    tmp2[0] = x[tmp[0]];
    tmp[0] = 0, tmp[1] = 1;
    for (int i = 1; i < 4 * n + 1; ++i) {
        if (x[i] > x[tmp[0]]) tmp[0] = i, tmp[1] = 1;
        else if (x[i] == x[tmp[0]]) ++tmp[1];
    }
    if (tmp[1] == 1) return cout << x[tmp[0]] << ' ' << y[tmp[0]], 0;
    tmp2[1] = x[tmp[0]];
    tmp[0] = 0, tmp[1] = 1;
    for (int i = 1; i < 4 * n + 1; ++i) {
        if (y[i] < y[tmp[0]]) tmp[0] = i, tmp[1] = 1;
        else if (y[i] == y[tmp[0]]) ++tmp[1];
    }
    if (tmp[1] == 1) return cout << x[tmp[0]] << ' ' << y[tmp[0]], 0;
    tmp2[2] = y[tmp[0]];
    tmp[0] = 0, tmp[1] = 1;
    for (int i = 1; i < 4 * n + 1; ++i) {
        if (y[i] > y[tmp[0]]) tmp[0] = i, tmp[1] = 1;
        else if (y[i] == y[tmp[0]]) ++tmp[1];
    }
    if (tmp[1] == 1) return cout << x[tmp[0]] << ' ' << y[tmp[0]], 0;
    tmp2[3] = y[tmp[0]];
    for (int i = 0; i < 4 * n + 1; ++i) if (x[i] != tmp2[0] && x[i] != tmp2[1] && y[i] != tmp2[2] && y[i] != tmp2[3])
        return cout << x[i] << ' ' << y[i], 0;
}