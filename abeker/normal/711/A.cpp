#include <cstdio>
using namespace std;

const int MAXN = 1005;

int N;
char s[MAXN][10];

bool check(int x, int y) {
    if (s[x][y] == 'O' && s[x][y + 1] == 'O') {
        s[x][y] = s[x][y + 1] = '+';
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", s[i]);
    
    bool ok = false;   
    for (int i = 0; i < N; i++) {
        if (check(i, 0)) {
            ok = true;
            break;
        }
        if (check(i, 3)) {
            ok = true;
            break;
        }
    }
    
    if (!ok) {
        puts("NO");
        return 0;
    }
    
    puts("YES");
    for (int i = 0; i < N; i++) {
        s[i][5] = '\0';
        puts(s[i]);
    }
    
    return 0;
}