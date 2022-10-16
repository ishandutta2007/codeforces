#include <iostream>

using namespace std;

const int N = 7, POWN = (1 << N), MOD = 1000 * 1000 * 1000 + 7;
int ans[POWN], res[POWN], a[POWN][POWN], b[POWN][POWN], c[POWN][POWN];

void powm(int p, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            b[i][j] = a[i][j];
            a[i][j] = (i == j);
        }
    while(p) {
        if(p & 1) {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) {
                    c[i][j] = 0;
                    for(int k = 0; k < n; k++)
                        c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
                }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    a[i][j] = c[i][j];
        }
        p >>= 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                c[i][j] = 0;
                for(int k = 0; k < n; k++)
                    c[i][j] = (c[i][j] + (long long)b[i][k] * b[k][j]) % MOD;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                b[i][j] = c[i][j];
    }
}

void mul(int n) {
    for(int i = 0; i < n; i++) {
        res[i] = 0;
        for(int j = 0; j < n; j++)
            res[i] = (res[i] + (long long)ans[j] * a[j][i]) % MOD;
    }
    for(int i = 0; i < n; i++)
        ans[i] = res[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    ans[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (1 << i); j++) {
            ans[j | (1 << i)] = ans[j];
            ans[j] = 0;
        }
        int w;
        cin >> w;
        if(!w)
            continue;
        for(int j = 0; j < (1 << (i + 1)); j++)
            for(int k = 0; k < (1 << (i + 1)); k++) {
                a[j][k] = 0;
                for(int l = 0; l < (1 << i); l++) {
                    int msk = ((1 << (i + 1)) | (l << 1) | 1);
                    bool ok = true;
                    for(int m = 0; m < i + 1; m++)
                        if((j & (1 << m)) && (k & (1 << m)) &&
                           (msk & (1 << m)) && (msk & (1 << (m + 1)))) {
                            ok = false;
                            break;
                        }
                    if(ok)
                        a[j][k]++;
                }
            }
        powm(w, 1 << (i + 1));
        mul(1 << (i + 1));
    }
    cout << ans[(1 << N) - 1] << '\n';
    return 0;
}