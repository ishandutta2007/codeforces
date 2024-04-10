#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for(int i = 0; i + 1 < n; i++) {
        if(s[i] == '0') {
            continue;
        }
        int j = i + 1;
        while(j < n && s[j - 1] == '1') {
            j++;
        }
        sort(a + i, a + j);
        i = j - 1;
    }
    if(is_sorted(a, a + n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}