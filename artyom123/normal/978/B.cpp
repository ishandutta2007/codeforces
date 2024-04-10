#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int now = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'x') {
            now = 0;
        }
        if (s[i] == 'x') {
            now++;
        }
        if (now == 3) {
            ans++;
            now = 2;
        }
    }
    cout << ans;
    return 0;
}