#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int x;
    int i;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, m, k;
int a[N];
ban b[N];

bool c[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i].x = a[i];
        b[i].i = i;
    }
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    long long ans = 0;
    for (int i = 1; i <= m * k; ++i)
    {
        ans += b[i].x;
        c[b[i].i] = true;
    }

    cout << ans << endl;
    int x = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            ++x;
            if (x % m == 0 && x != m * k)
                cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}