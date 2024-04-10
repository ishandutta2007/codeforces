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

#define maxN 1000011

int n, c, i, j;
int dim[maxN];
int s[5][maxN];

int ss, dd;
int deny[maxN];
int l, r;


void no_sol() {
    printf("-1");
    exit(0);
}

void add_condition(int L, int R) {
    l = max(l, L);
    r = min(r, R);

    if (l > r) no_sol();
}

void add_rel(int id1, int id2) {
    int i;
    int limit = min(dim[id1], dim[id2]);

    for (i = 1; i <= limit && s[ss][i] == s[dd][i]; i++);
    if (i > dim[id1] && i > dim[id2]) return; // equal
    if (i > dim[id1]) return; // it is always good
    if (i > dim[id2]) no_sol(); // no no no

    if (s[ss][i] < s[dd][i]) {
        deny[s[ss][i] + 1]++;
        deny[s[dd][i] + 1]--;
    } else {
        add_condition(s[dd][i] + 1, s[ss][i]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &c);

    l = 1; r = c;
    ss = 0; dd = 1;
    scanf("%d", &dim[1]);
    for (i = 1; i <= dim[1]; i++) scanf("%d", &s[ss][i]);

    for (i = 2; i <= n; i++) {
        scanf("%d", &dim[i]);
        for (j = 1; j <= dim[i]; j++) scanf("%d", &s[dd][j]);
        add_rel(i - 1, i);
        swap(ss, dd);
    }

    for (i = 1; i <= c; i++) deny[i] += deny[i - 1];
    for (i = l; i <= r; i++) {
        if (deny[i] > 0) continue;

        printf("%d", (c - (i - 1)) % c);
        return 0;
    }

    no_sol();

    return 0;
}