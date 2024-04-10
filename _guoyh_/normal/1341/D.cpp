# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const char dig[10][10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
const int NR = 2051;
int n, k;
char s[NR][10];
int f[NR][NR];
int fnl[NR];
int dif(int x, int y){
    int ans = 0;
    for (int i = 0; i < 7; i++){
        if (s[x][i] == '1' && dig[y][i] == '0') return -1;
        if (s[x][i] == '0' && dig[y][i] == '1') ans++;
    }
    return ans;
}
bool srch(int x, int y){
    if (f[x][y] != -1) return f[x][y];
    if (x == n + 1) return y == 0;
    f[x][y] = 0;
    for (int i = 9; i >= 0; i--){
        int d = dif(x, i);
        if (d == -1 || y < d) continue;
        if (srch(x + 1, y - d)){
            f[x][y] = 1;
            fnl[x] = i;
            return true;
        }
    }
    return false;
}
int main(){
    memset(f, -1, sizeof(f));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%s", s[i]);
    if (srch(1, k)){
        for (int i = 1; i <= n; i++) printf("%d", fnl[i]);
        putchar('\n');
    } else printf("-1\n");
    return 0;
}