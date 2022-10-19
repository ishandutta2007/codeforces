#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;

int n, m, w;
int a[N];

bool stg(int x)
{
    queue<int> s;
    int mm = m;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && s.front() < i)
            s.pop();
        if ((a[i] + s.size()) < x)
        {
            int y = x - (a[i] + s.size());
            if (mm < y)
                return false;
            mm -= y;
            for (int j = 0; j < y; ++j)
                s.push(i + w - 1);
        }
    }
    return true;
}

int byn()
{
    int l = 1, r = 1000000000 + m;
    while ((r - l) > 4)
    {
        int mid = (l + r) / 2;
        if (stg(mid))
            l = mid;
        else
            r = mid;
    }
    for (int mid = r; mid >= l; --mid)
        if (stg(mid))
            return mid;
    assert(false);
}

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << byn() << endl;
    return 0;
}