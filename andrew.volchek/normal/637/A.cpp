#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int R = (int)1e6 + 5;
const int N = 1010;

int cnt[R], lst[R];
int a[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        int x = a[i];
        cnt[x]++;
        lst[x] = i;
    }

    auto best = make_pair(cnt[0], -lst[0]);

    for (int i = 1; i < R; i++) {
        best = max(best, make_pair(cnt[i], -lst[i]));
    }

    printf("%d\n", a[-best.second]);

    return 0;
}