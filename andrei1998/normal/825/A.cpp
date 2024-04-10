#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main()
{
    int n; cin >> n;
    string str;
    cin >> str;
    str += '0';
    lint ans = 0;
    int cnt = 0;
    for (auto it: str) {
        if (it == '0') {
            ans *= 10;
            ans += cnt;
            cnt = 0;
        }
        else
            ++ cnt;
    }
    cout << ans << '\n';
    return 0;
}