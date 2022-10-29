#include <bits/stdc++.h>
using namespace std;

#define MAXN 312345

int main(void)
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 2; i + 1 <= n; i++)
    {
        ans += i * (long long) (i + 1);
    }

    cout << ans << endl;
}