#include <bits/stdc++.h>
using namespace std;
const int N = 102, INF = 1000000009;

int n, t;
int s[N], d[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> s[i] >> d[i];
    int minu = INF, mini;
    for (int i = 1; i <= n; ++i)
    {
        while (s[i] < t)
        {
            s[i] = s[i] + d[i];
        }
        if (s[i] < minu)
        {
            minu = s[i];
            mini = i;
        }
    }
    cout << mini << endl;
    return 0;
}