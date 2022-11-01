#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char reply[3];
int t, n, x[N], y[N], pos;

int main (int argc, char const *argv[]) {
    scanf("%d", &t); while (t--) {
        scanf("%d", &n), pos = 0;
        for (int i = 1; i < n; i += 2) {
            ++pos;
            x[pos] = i, y[pos] = i + 1;
            printf("? %d %d\n", i, i + 1);
            fflush(stdout);
            scanf("%s", reply);
            if (reply[0] != '<') swap(x[pos], y[pos]);
        }
        
        if (n % 2) {
            ++pos;
            x[pos] = y[pos] = n;
        } 

        for (int i = 1; i < pos; ++i) {
            printf("? %d %d\n", x[i], x[i + 1]);
            fflush(stdout);
            scanf("%s", reply);
            if (reply[0] == '<') x[i + 1] = x[i];
            printf("? %d %d\n", y[i], y[i + 1]);
            fflush(stdout);
            scanf("%s", reply);
            if (reply[0] == '>') y[i + 1] = y[i];
        }

        printf("! %d %d\n", x[pos], y[pos]);
        fflush(stdout);
    }
    return 0;
}