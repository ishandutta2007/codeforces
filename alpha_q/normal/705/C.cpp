#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n, q;
int found[N];
int app[N];
int status[N];
int pointer = 1;
int unread = 0, pos = 0;
int inp[N];

int main (int argc, char const *argv[]) {
    scanf("%d %d", &n, &q); while (q--) {
        int cmd, x; scanf("%d %d", &cmd, &x);
        if (cmd == 1) {
            inp[++pos] = x;
            ++app[x], ++status[x], ++unread;
        }
        else if (cmd == 2) {
            unread -= status[x];
            status[x] = 0;
        }
        else if (x >= pointer) {
            while (pointer <= x) {
                int now = inp[pointer];
                ++found[now];
                if (found[now] > app[now] - status[now]) --unread, --status[now];
                ++pointer;
            }
        }
        printf("%d\n", unread);
    }
    return 0;
}