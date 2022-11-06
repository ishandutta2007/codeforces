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

#define maxN 5011

int n, i, j, u, base;
char s[maxN];
int sum_l[maxN], sum_r[maxN], sum_q[maxN];
int pl[maxN], pr[maxN];
int ans;

bool check(int l, int r) {
    int sz = r - l + 1;

    if (pl[l] < r) return false;
    if (pr[r] > l) return false;
    int a = sum_l[r] - sum_l[l - 1];
    int b = sum_r[r] - sum_r[l - 1];
    int q = sum_q[r] - sum_q[l - 1];

    if (a > b) swap(a, b);
    if (a + q < b) return false;

    return true;
}

int main()
{
   // freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++) {
        sum_l[i] = sum_l[i - 1];
        sum_r[i] = sum_r[i - 1];
        sum_q[i] = sum_q[i - 1];

        if (s[i] == '(') sum_l[i]++;
        if (s[i] == ')') sum_r[i]++;
        if (s[i] == '?') sum_q[i]++;
    }

    for (i = 1; i <= n; i++) {
        u = i - 1;
        base = 0;

        while (u + 1 <= n && base + (s[u + 1] != ')' ? +1 : -1) >= 0) {
            u++;
            base += (s[u] != ')' ? +1 : -1);
        }
        pl[i] = u;
    }

    for (i = 1; i <= n; i++) {
        u = i + 1;
        base = 0;

        while (u - 1 > 0 && base + (s[u - 1] != '(' ? +1 : -1) >= 0) {
            u--;
            base += (s[u] != '(' ? +1 : -1);
        }
        pr[i] = u;
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j += 2) {
            if (check(i, j))
                ans++;
        }
    }

    printf("%d", ans);




    return 0;
}