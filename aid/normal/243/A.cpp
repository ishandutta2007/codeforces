#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, MAXX = 2000 * 1000 + 5, LOGX = 20;
int a[MAXN], nxt[MAXN][LOGX];
char c[MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < LOGX; i++)
        nxt[n - 1][i] = (a[n - 1] & (1 << i))? n - 1 : n;
    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j < LOGX; j++)
            nxt[i][j] = (a[i] & (1 << j))? i : nxt[i + 1][j];
    for(int i = 0; i < n; i++) {
        int pos = i, x = a[i];
        while(pos < n) {
            c[x] = true;
            int npos = n;
            for(int j = 0; j < LOGX; j++)
                if(!(x & (1 << j)) && nxt[pos][j] < npos)
                    npos = nxt[pos][j];
            for(int j = 0; j < LOGX; j++)
                if(nxt[pos][j] == npos)
                    x |= (1 << j);
            pos = npos;
        }
    }
    int ans = 0;
    for(int i = 0; i < MAXX; i++)
        ans += c[i];
    cout << ans << '\n';
    return 0;
}