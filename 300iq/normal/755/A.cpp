#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return (x != 1);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int x = 1; x <= 1000; x++)
    {
        if (!prime(n * x + 1))
        {
            cout << x << '\n';
            return 0;
        }
    }

}