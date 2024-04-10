#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            if (i + 4 * j < n && s[i] == '*' && s[i + j] == '*' && s[i + 2 * j] == '*' && s[i + 3 * j] == '*' && s[i + 4 * j] == '*')
            {
                cout << "yes";
                return 0;
            }
    cout << "no";
    return 0;
}