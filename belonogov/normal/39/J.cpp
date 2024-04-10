#include <iostream>
#include <string>

using namespace std;
const int MAXN = 1e6 + 3;
bool a[MAXN], b[MAXN];
int res[MAXN];

int main()
{
    int n, i, ans = 0;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    n = s1.length();
    for (i = 0; i < n; i++)
    {
        if (s1[i] == s2[i] && (i == 0 || a[i - 1]))
            a[i] = true;
    }
    for (i = n; i > 0; i--)
    {
        if (s1[i] == s2[i - 1] && (i == n || b[i + 1]))
            b[i] = true;
    }
    b[n + 1] = true;
   /* if (b[1])
    {
        res[ans++] = 1;
    }*/
    for (i = 0; i <= n; i++)
    {
        if ((i == 0 || a[i - 1]) && b[i + 1])
        {
            res[ans++] = i + 1;
        }
    }
    cout << ans << "\n";
    for (i = 0; i < ans; i++)
        cout << res[i] << " ";
    return 0;
}