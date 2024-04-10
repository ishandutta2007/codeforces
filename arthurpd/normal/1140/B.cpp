#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;

        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '>')
                ans = min (ans, i);
            else
            {
                ans = min(ans, n - i - 1);
            }
        }

        cout << ans << endl;
    }
}