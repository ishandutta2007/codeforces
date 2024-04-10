#include <bits/stdc++.h>

using namespace std;

char s[1010];

int main (int argc, char const *argv[]) {
    scanf("%s", s + 1);
    int res = -1, last = 0, n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or s[i] == 'Y') {
            res = max(res, i - last);
            last = i;
        }
    }
    res = max(res, n + 1 - last);
    printf("%d\n", res);
    return 0;
}