// naive problems
#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
    T data = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        data = (data << 3) + (data << 1) + ch - '0';
        ch = getchar();
    }
    x = f * data;
}

int a[201], b[201];
signed main()
{
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    for (int i = 1; i <= m; ++i)
        read(b[i]);
    bool flag;
    int cnt;
    for (int ans = 0; ans < 512; ++ans)
    {
        cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            flag = false;
            for (int j = 1; j <= m; ++j)
                if ((a[i] & b[j] | ans) == ans)
                {
                    flag = true;
                    break;
                }
            if (flag)
                cnt++;
            else
                break;
        }
        if (cnt == n)
        {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}