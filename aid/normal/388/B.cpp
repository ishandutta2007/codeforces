#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005, LEN = 11;
char g[MAXN][MAXN];
int n = 2;

void add(int p, int k) {
    int last = n;
    for(int i = 0; i < p; i++) {
        g[0][n] = true;
        g[n][0] = true;
        n++;
    }
    for(int i = 0; i < k; i++) {
        int last1 = n;
        for(; n < last1 + 10; n++)
            for(int i = last; i < last1; i++) {
                g[i][n] = true;
                g[n][i] = true;
            }
        last = last1;
    }
    for(int i = k; i < LEN; i++, n++) {
        for(int i = last; i < n; i++) {
            g[i][n] = true;
            g[n][i] = true;
        }
        last = n;
    }
    g[n - 1][1] = true;
    g[1][n - 1] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    for(int i = 1, j = 0; i <= k; i *= 10, j++) {
        int p = (k / i) % 10;
        if(p)
            add(p, j);
    }
    cout << n << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << (g[i][j]? 'Y' : 'N');
        cout << '\n';
    }
    return 0;
}