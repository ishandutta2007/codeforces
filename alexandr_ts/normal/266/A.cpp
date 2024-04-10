#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int n, ans;
    ans = 0;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - ans; j++)
            if (s[j] == s[j + 1])
            {
                ans++;
                s.erase(j, 1);
            }
    cout << ans;
    return 0;
}