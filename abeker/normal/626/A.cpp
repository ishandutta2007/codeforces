#include <cstdio>
using namespace std;

const int MAXN = 205;

int N;
char s[MAXN];

int main() {
    scanf("%d%s", &N, s);
    int sol = 0;
    for (int i = 0; i < N; i++) {
        int x = 0, y = 0;
        for (int j = i; j < N; j++) {
            if (s[j] == 'U') y++;
            if (s[j] == 'R') x++;
            if (s[j] == 'D') y--;
            if (s[j] == 'L') x--;
            sol += !x && !y;
        }
    }
    printf("%d\n", sol);
    return 0;
}