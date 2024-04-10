#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int i;
    int x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

int qq;
map<int, int> q;

void ave(int x)
{
    ++q[x];
    if (q[x] == 1)
        ++qq;
}
void han(int x)
{
    --q[x];
    if (q[x] == 0)
        --qq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x;
        a[i].i = i;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i)
    {
        q[a[i + 1].x - a[i].x]++;
        if (q[a[i + 1].x - a[i].x] == 1)
            ++qq;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            han(a[i + 1].x - a[i].x);
            if (qq == 1)
            {
                cout << a[i].i << endl;
                return 0;
            }
            ave(a[i + 1].x - a[i].x);
            continue;
        }
        if (i == n)
        {
            han(a[n].x - a[n - 1].x);
            if (qq == 1)
            {
                cout << a[i].i << endl;
                return 0;
            }
            ave(a[n].x - a[n - 1].x);
            continue;
        }
        han(a[i].x - a[i - 1].x);
        han(a[i + 1].x - a[i].x);
        ave(a[i + 1].x - a[i - 1].x);
        if (qq == 1)
        {
            cout << a[i].i << endl;
            return 0;
        }
        ave(a[i].x - a[i - 1].x);
        ave(a[i + 1].x - a[i].x);
        han(a[i + 1].x - a[i - 1].x);
    }
    cout << -1 << endl;
    return 0;
}