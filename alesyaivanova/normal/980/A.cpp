#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            k++;
    }
    if (k == n || k % (n - k) == 0)
        cout << "YES";
    else
        cout << "NO";
}