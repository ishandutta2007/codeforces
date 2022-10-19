#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n;
ban a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x].l = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x].r = i;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    int minu = N;
    for (int i = n; i >= 1; --i)
    {
        if (minu < a[i].l)
            ++ans;
        minu = min(minu, a[i].l);
    }
    cout << ans << endl;
    return 0;
}