#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300000008;

bitset<N> c;
bitset<N> cc;

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    c[0] = c[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (c[i])
            continue;
        if (i * 1LL * i >= N)
            break;
        for (int j = i * i; j < N; j += i)
            c[j] = 1;
    }
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = 0;
    if (l <= 2 && 2 <= r)
        ++ans;
    for (int i = l; i <= r; ++i)
    {
        if (c[i])
            continue;
        if ((i % 4) == 1)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}