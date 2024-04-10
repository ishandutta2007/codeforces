#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 10;

map <int, int> M;

int main (int argc, char const *argv[]) {
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

    int n, m, b[MAX], c[MAX];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        ++M[x];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    for (int i = 1; i <= m; i++) scanf("%d", c + i);

    int id = 1, aud = M[b[1]], sub = M[c[1]];
    for (int i = 2; i <= m; i++)
        if ((M[b[i]] > aud) or (M[b[i]] == aud and M[c[i]] > sub))
            aud = M[b[i]], sub = M[c[i]], id = i;

    printf("%d\n", id);
	return 0;
}