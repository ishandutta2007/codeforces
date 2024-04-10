#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N], b[N];

char t[N];

int main()
{
    cin >> n;
    cin >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    int ans = 0;
    for (int x = 0; x < N * N; ++x)
    {
        int yans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (x >= b[i] && (x - b[i]) % a[i] == 0)
            {
                if (t[i] == '1')
                    t[i] = '0';
                else
                    t[i] = '1';
            }
            if (t[i] == '1')
                ++yans;
        }
        ans = max(ans, yans);
    }
    cout << ans << endl;
    return 0;
}