#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    s += 'b';
    int n = s.size();
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1])
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}