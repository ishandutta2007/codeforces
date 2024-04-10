#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

char s[25];
int dp[25][15];
int nxt[25][15];
int mat[15][25];

void load() {
    scanf("%s", s);
}

int express(int x) {
    for (int i = 0; i < 7 && x >= 0; i++) {
        if (!(x % 7)) 
            return i + x / 7 > 6 ? -1 : i;
        x -= 4;
    }
    return -1;
}

int rec(int pos, int carry) {
    int &ref = dp[pos][carry];
    if (ref != -1) return ref;
    int digit = s[pos] - '0' - carry;
    if (digit < 0) digit += 10;
    ref = 0;
    for (int i = 0; i < 5; i++)  
        if (express(10 * i + digit) != -1 && rec(pos + 1, i + (digit + carry) / 10)) {
            ref = 1;
            nxt[pos][carry] = i;
        }
    return ref;
}

void solve() {
    int N = strlen(s);
    reverse(s, s + N);
    memset(dp, -1, sizeof dp);
    memset(mat, 0, sizeof mat);
    dp[N][0] = 1;
    for (int i = 1; i < 10; i++)
        dp[N][i] = 0;
        
    int res = rec(0, 0);
    if (!res) {
        puts("-1");
        return;
    }
    
    int curr = 0;
    for (int i = 0; i < N; i++) {
        int digit = s[i] - '0' - curr;
        if (digit < 0) digit += 10;
        int num = 10 * nxt[i][curr] + digit;
        int tmp = express(num);
        for (int j = 0; j < tmp; j++)
            mat[j][N - i - 1] = 4;
        for (int j = 0; j < (num - tmp * 4) / 7; j++)
            mat[tmp + j][N - i - 1] = 7;
        curr = nxt[i][curr] + (digit + curr) / 10;
    }
    
    for (int i = 0; i < 6; i++) {
        ll sol = 0;
        for (int j = 0; j < N; j++)
            sol = 10 * sol + (ll)mat[i][j];
        printf("%I64d ", sol);
    }
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        load();
        solve();
    }
    return 0;
}