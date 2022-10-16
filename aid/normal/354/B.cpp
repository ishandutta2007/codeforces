#include <iostream>

using namespace std;

const int MAXN = 25, MAXMASK = (1 << 20) + 5, INF = 1000 * 1000 * 1000 + 5;
char t[MAXN][MAXN], used[2 * MAXN][MAXMASK];
int d[2 * MAXN][MAXMASK], n;

void dfs(int diag, int mask) {
    if(used[diag][mask])
        return;
    used[diag][mask] = true;
    if(diag == n + n - 2)
        return;
    if(diag & 1)
        d[diag][mask] = -INF;
    else
        d[diag][mask] = INF;
    if(diag < n - 1)
        for(char c = 'a'; c <= 'z'; c++) {
            int mask1 = (mask & 1) && t[0][diag + 1] == c;
            for(int i = 0; i < diag + 1; i++)
                if((mask & (1 << i)) || (mask & (1 << (i + 1))))
                    mask1 |= (int)(t[i + 1][diag - i] == c) << (i + 1);
            if(mask1) {
                dfs(diag + 1, mask1);
                if(diag & 1)
                    d[diag][mask] = max(d[diag][mask], d[diag + 1][mask1] +
                                        (int)(c == 'a') - (int)(c == 'b'));
                else
                    d[diag][mask] = min(d[diag][mask], d[diag + 1][mask1] +
                                        (int)(c == 'a') - (int)(c == 'b'));
            }
        }
    else
        for(char c = 'a'; c <= 'z'; c++) {
            int mask1 = 0;
            for(int i = 0; i < n + n - diag - 2; i++)
                if((mask & (1 << i)) || (mask & (1 << (i + 1))))
                    mask1 |= (int)(t[diag - n + 2 + i][n - 1 - i] == c) << i;
            if(mask1) {
                dfs(diag + 1, mask1);
                if(diag & 1)
                    d[diag][mask] = max(d[diag][mask], d[diag + 1][mask1] +
                                        (int)(c == 'a') - (int)(c == 'b'));
                else
                    d[diag][mask] = min(d[diag][mask], d[diag + 1][mask1] +
                                        (int)(c == 'a') - (int)(c == 'b'));
            }
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> t[i][j];
    dfs(0, 1);
    int ans = d[0][1] + (int)(t[0][0] == 'a') - (int)(t[0][0] == 'b');
    cout << (ans == 0? "DRAW\n" : (ans > 0? "FIRST\n" : "SECOND\n"));
    return 0;
}