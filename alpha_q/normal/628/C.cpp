#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

char S[MAX], T[MAX], c; int n, k, i, j, s, t;

int main() {
    scanf ("%d %d", &n, &k); scanf ("%s", S);

    for (i = 0; i < n; i++) {
        if (k == 0) {
            T[i] = S[i];
            continue;
        }
        s = S[i] - 'a', t = 'z' - S[i];
        if (s > t) {
            if (k > s) {
                T[i] = 'a';
                k -= s;
            } else {
                T[i] = (char) (S[i] - k);
                k = 0;
            }
        } else {
            if (k > t) {
                T[i] = 'z';
                k -= t;
            } else {
                T[i] = (char) (S[i] + k);
                k = 0;
            }
        }
    }

    if (k == 0) puts(T);
    else printf("-1");
    return 0;
}