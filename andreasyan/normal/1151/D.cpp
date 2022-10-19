#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int a, b;
};
bool operator<(const ban& a, const ban& b)
{
    return (a.a - a.b) > (b.a - b.b);
}

int n;
ban a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].a >> a[i].b;
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i].a * 1LL * (i - 1) + a[i].b * 1LL * (n - i);
    cout << ans << endl;
    return 0;
}