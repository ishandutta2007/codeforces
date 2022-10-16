#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < 9 * t; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < 9; ++j) {
            if (str[j] == '1') {
                str[j] = '2';
            }
        }
        cout << str << '\n';
    }
    return 0;
}