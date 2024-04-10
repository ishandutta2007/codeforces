#include <bits/stdc++.h>


using namespace std;

const int M = 107;
const int N = 3;

int n, k;
string s[N];
bool g[N][M], c[N];

void read() {
    cin >> n >> k;
    for (int i = 0; i < N; ++i)
        cin >> s[i];
}

bool good(int i, int j) {
    return s[i][j] == '.' || s[i][j] == 's';
}

void build() {
    for (int i = 0; i < N; ++i)
        g[i][n] = true;
    for (int j = n - 1; j >= 0; --j) {
        for (int i = 0; i < N; ++i)
            g[i][j] = false;

        for (int i = 0; i < N; ++i)
            if (good(i, j) && g[i][j + 1])
                g[i][j] = true;
        if (j % 3 == 1) {
            fill(c, c + 3, false);
            for (int i = 0; i < N; ++i)
                if (good(i, j))
                    for (int k = -1; k <= 1; ++k)
                        if (0 <= i + k && i + k <= 2)
                            c[i + k] |= g[i][j];
            for (int i = 0; i < N; ++i)
                if (good(i, j))
                     g[i][j] = c[i];
        }
    }
}

bool dfs() {
    int st = -1;
    for (int i = 0; i < N; ++i)
        if (s[i][0] == 's')
            st = i;
    return g[st][0];
}
 
        
int main() {
    int t;
    cin >> t;
    while (t--) {
        read();
        build();
        cout << (dfs() ? "YES\n" : "NO\n");
    }
    return 0;
}