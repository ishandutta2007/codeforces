#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
int x[8][3], p[8][3];

long long sqDist(int a, int b) {
    long long res = 0;
    for(int i = 0; i < 3; i++)
        res += (long long)(x[b][p[b][i]] - x[a][p[a][i]]) *
            (x[b][p[b][i]] - x[a][p[a][i]]);
    return res;
}

long long sp(int x0, int y0, int z0, int x1, int y1, int z1) {
    return (long long)x0 * x1 + (long long)y0 * y1 + (long long)z0 * z1;
}

bool isCube() {
    long long a = INF;
    for(int i = 1; i < 8; i++)
        a = min(a, sqDist(0, i));
    for(int i = 0; i < 8; i++) {
        int c[8], k = 0;
        for(int j = 0; j < 8; j++)
            if(sqDist(i, j) == a)
                c[k++] = j;
        if(k != 3)
            return false;
        for(int j = 0; j < 3; j++)
            for(int l = j + 1; l < 3; l++)
                if(sp(x[c[j]][p[c[j]][0]] - x[i][p[i][0]],
                      x[c[j]][p[c[j]][1]] - x[i][p[i][1]],
                      x[c[j]][p[c[j]][2]] - x[i][p[i][2]],
                      x[c[l]][p[c[l]][0]] - x[i][p[i][0]],
                      x[c[l]][p[c[l]][1]] - x[i][p[i][1]],
                      x[c[l]][p[c[l]][2]] - x[i][p[i][2]]))
                    return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 3; j++) {
            cin >> x[i][j];
            p[i][j] = j;
        }
    for(int i0 = 0; i0 < 6; i0++) {
        for(int i1 = 0; i1 < 6; i1++) {
            for(int i2 = 0; i2 < 6; i2++) {
                for(int i3 = 0; i3 < 6; i3++) {
                    for(int i4 = 0; i4 < 6; i4++) {
                        for(int i5 = 0; i5 < 6; i5++) {
                            for(int i6 = 0; i6 < 6; i6++) {
                                if(isCube()) {
                                    cout << "YES\n";
                                    for(int i = 0; i < 8; i++) {
                                        for(int j = 0; j < 3; j++)
                                            cout << x[i][p[i][j]] << ' ';
                                        cout << '\n';
                                    }
                                    return 0;
                                }
                                next_permutation(p[7], p[7] + 3);
                            }
                            next_permutation(p[6], p[6] + 3);
                        }
                        next_permutation(p[5], p[5] + 3);
                    }
                    next_permutation(p[4], p[4] + 3);
                }
                next_permutation(p[3], p[3] + 3);
            }
            next_permutation(p[2], p[2] + 3);
        }
        next_permutation(p[1], p[1] + 3);
    }
    cout << "NO\n";
    return 0;
}