#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> cnt(26, vector<int>(26, 0));
    int mx = 0;
    char ax = 'A', ay = 'A';
    for (int i = 0; i < n - 1; ++i) {
        int x = s[i] - 'A';
        int y = s[i + 1] - 'A';
        ++cnt[x][y];
        if (cnt[x][y] >= mx) {
            mx = cnt[x][y];
            ax = 'A' + x;
            ay = 'A' + y;
        }
    }
    cout << (char) ax << (char) ay << '\n';
    return 0;
}