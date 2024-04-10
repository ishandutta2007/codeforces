#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    map<int, int> a;
    int l = 0, r = 1;
    while (q--) {
        char c;
        int t;
        cin >> c >> t;
        if (c == 'R') {
            a[t] = r;
            r++;
        } else if (c == 'L') {
            a[t] = l;
            l--;
        } else {
            cout << min(a[t] - l - 1, r - a[t] - 1) << "\n";
        }
    }
    return 0;
}