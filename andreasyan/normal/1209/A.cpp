#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
bool c[N];

bool cc[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        c[x] = true;
    }
    int ans = 0;
    for (int i = 1; i < N; ++i)
    {
        if (cc[i])
            continue;
        if (!c[i])
            continue;
        ++ans;
        for (int j = i; j < N; j += i)
        {
            cc[j] = true;
        }
    }
    cout << ans << endl;
    return 0;
}