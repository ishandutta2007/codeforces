#include <stdio.h>

char s[123][77];
char a[6][9];

void f(char *b, char x, char y) {
    b[0] = b[1] = x;
    b[3] = b[4] = y;
    b[6] = b[7] = x;
}

int main() {
    f(a[0], '3', '4');
    f(a[1], '3', '4');
    f(a[2], '2', '3');
    f(a[3], '2', '3');
    f(a[4], '1', '2');
    f(a[5], '1', '2');
    int i;
    int j;
    int ans;
    ans = 0;
    for (i = 0; i < 6; ++i){
        scanf("%s", s[i]);
        for (j = 0; j < 8; ++j) {
            if (s[i][j] == '.') {
                int x = a[i][j] - '0';
                if (x > ans) {
                    ans = x;
                }
            }
        }
    }
    for (i = 0; i < 6; ++i){
        for (j = 0; j < 8; ++j) {
            if (s[i][j] == '.') {
                int x = a[i][j] - '0';
                if (x == ans) {
                    //printf("! %d %d\n", i, j);
                    s[i][j] = 'P';
                    for (j = 0; j < 6; ++j) {
                        printf("%s\n", s[j]);
                    }
                    return 0;
                }
            }
        }
    }
}