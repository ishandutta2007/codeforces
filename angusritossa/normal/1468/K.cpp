#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n;
char s[5005];

int main() {
    scanf("%d", &t);
    for (int test = 0; test < t; test++) {
        scanf("%s", s);
        n = strlen(s);
        int ansr = 0, ansc = 0;
        for (int i = 0; i < n; i++) {
            int blockr = 0, blockc = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == 'L') blockc--;
                if (s[j] == 'R') blockc++;
                if (s[j] == 'D') blockr--;
                if (s[j] == 'U') blockr++;
            }
            if (blockr == 0 && blockc == 0) {
                continue;
            }
            //printf("%d %d\n", blockr, blockc);
            int r = 0, c = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] == 'L' && !(blockr == r && blockc == c-1)) c--;
                if (s[j] == 'R' && !(blockr == r && blockc == c+1)) c++;
                if (s[j] == 'D' && !(blockr == r-1 && blockc == c)) r--;
                if (s[j] == 'U' && !(blockr == r+1 && blockc == c)) r++;
            }
            if (r == 0 && c == 0) {
                ansr = blockr;
                ansc = blockc;
                break;
            }
        }
        printf("%d %d\n", ansc, ansr);

    }
}