#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j + 4 * i >= n)
                continue;
            if(s[j] == '*' && s[j + i] == '*' && s[j + 2 * i] == '*' && s[j + 3 * i] == '*' && s[j + 4 * i] == '*')
            {
                cout << "yes\n";
                return 0;
            }
        }
    }
    cout << "no\n";
    return 0;
}