#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    char a[n][7];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 7; j++)
            cin >> a[i][j];
    int ret = 0;
    for(int j = 0; j < 7; j++) {
        int nw = 0;
        for(int i = 0; i < n; i++)
            nw += (a[i][j] == '1');
        ret = max(ret, nw);
    }
    cout << ret;
}