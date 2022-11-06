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

int n, i, a, b;
char s[maxN];
ll posL[maxN], posR[maxN];
ll ans[maxN], aux[maxN];

void solve() {
    int i;
    int pa, pb;
    int on_left, on_right;

    memset(ans, 0, sizeof(ans));

    a = b = 0;
    for (i = 0; i <= n + 1; i++)
        if (s[i] == 'U')
            posL[++a] = i;
    for (i = 0; i <= n + 1; i++)
        if (s[i] == 'D')
            posR[++b] = i;

    for (i = 2; i <= a; i++) posL[i] += posL[i - 1];
    for (i = 2; i <= b; i++) posR[i] += posR[i - 1];
    pa = 0; pb = 1;

    for (i = 1; i <= n; i++) {
        if (posL[pa + 1] - posL[pa] < i && pa < a) pa++;
        if (posR[pb] - posR[pb - 1] <= i && pb < b) pb++;

        if (s[i] == 'D') continue;

        on_left = pa;
        on_right = b - pb + 1;

        if (on_left < on_right) {
            on_right = on_left;
            ans[i] = 2 * (posR[pb + on_right - 1] - posR[pb - 1]) - 2 * (posL[pa] - posL[pa - on_left]);
            ans[i] += -i + 0;
        } else {
            on_left = on_right - 1;
            ans[i] = 2 * (posR[pb + on_right - 1] - posR[pb - 1]) - 2 * (posL[pa] - posL[pa - on_left]);
            ans[i] -= i + (n + 1);
        }

        if (ans[i] < 0) while(1);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    scanf("%s", s + 1);
    s[0] = 'U'; s[n + 1] = 'D';

    solve();
    memcpy(aux, ans, sizeof(ans));

    reverse(s, s + n + 2);
    for (i = 0; i <= n + 1; i++) s[i] = (s[i] == 'U' ? 'D' : 'U');
    solve();
    reverse(ans + 1, ans + n + 1);
    for (i = 1; i <= n; i++) ans[i] = max(ans[i], aux[i]);

    for (i = 1; i <= n; i++) printf("%lld ", ans[i]);

    return 0;
}