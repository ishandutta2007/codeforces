#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s = s1 + "#";
    int f[n];
    int l = 0, r = 0;
    int z[n];
    if (s[0] == s[1])
    {
        z[1] = 1;
        l = 1;
        r = 2;
    }
    else
        z[1] = 0;
    for (int i = 2; i < n; i++)
    {
        z[i] = max(0, min(z[i - l], r - i));
        while (s[z[i]] == s[i + z[i]])
            z[i]++;
        if (z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    int ma = -1;
    for (int i = 1; i < n; i++)
    {
        if (z[i] >= i)
            ma = max(ma, i);
    }
    if (ma == -1)
        cout << n;
    else
        cout << n - ma + 1;
}