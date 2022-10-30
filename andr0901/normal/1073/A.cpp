#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector <int> symb(26, 0);
            for (int k = i; k <= j; k++) symb[s[k] - 'a']++;
            bool flag = 0;
            for (int k = 0; k < 26; k++) {
                if (2 * symb[k] > (j - i + 1)) {
                    flag = 1;
                }
            }
            if (!flag) {
                cout << "YES\n";
                for (int k = i; k <= j; k++) cout << s[k];
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}