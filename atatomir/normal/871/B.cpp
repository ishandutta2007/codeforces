#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 10011

int n, i, j;
int ud[maxN], lr[maxN];
int to[maxN];
int cnt[maxN], act;
bool us[maxN];

int p[maxN], b[maxN], sol[maxN], aux[maxN];
int ans;


int ask(int a, int b) {
    int ans;

    printf("? %d %d\n", a, b);
    fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int get_value(int x, int y) {
    int ans = ud[y] ^ (x == 0 ? 0 : ud[x - 1]);
    ans ^= (y == 0 ? 0 : lr[y - 1]) ^ (x == 0 ? lr[x - 1] : 0);
    return ans;
}

bool check() {
    int i;

    memset(us, 0, sizeof(us));
    for (i = 0; i < n; i++) {
        aux[p[i]] = i;
        if (us[p[i]]) return false;
        us[p[i]] = true;
    }

    for (i = 0; i < n; i++)
        if (b[i] != aux[i])
            return false;

    if (ans == 0) {
        for (i = 0; i < n; i++)
            sol[i] = p[i];
    }

    return true;
}

int main()
{


    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        ud[i] = ud[i + n] = ask(i, i);
        lr[i] = lr[i + n] = ask(i, (i + 1) % n);
    }

    for (i = 1; i < 2 * n; i++) {
        ud[i] ^= ud[i - 1];
        lr[i] ^= lr[i - 1];
    }

    for (b[0] = 0; b[0] < n; b[0]++) {
        p[0] = ud[0] ^ b[0];

        for (i = 1; i < n; i++) {
            p[i] = b[0] ^ get_value(0, i);
            b[i] = ud[i] ^ ud[i - 1] ^ p[i];
        }

        if (check()) ans++;
    }

    printf("!\n");
    printf("%d\n", ans);
    for (i = 0; i < n; i++)
        printf("%d ", sol[i]);
    printf("\n");
    fflush(stdout);



    return 0;
}