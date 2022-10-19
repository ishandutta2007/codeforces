#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        vector<int> cnt1(3), cnt2(3);
        int v = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'X')
                    cnt1[(i+j)%3]++, v++;
                if (s[i][j] == 'O')
                    cnt2[(i+j)%3]++, v++;
            }
        }
        int p = 0;
        for (int i = 1; i < 3; ++i)
            if (cnt1[i] < cnt1[p])
                p = i;
        int p2 = 0;
        if (p == 0)
            p2++;
        for (int i = 1; i < 3; ++i)
            if (cnt2[i] < cnt2[p2] && i != p)
                p2 = i;
        if (cnt1[p]+cnt2[p2] > v/3) {
            p2 = 0;
            for (int i = 1; i < 3; ++i)
                if (cnt2[i] < cnt2[p2])
                    p2 = i;
            p = 0;
            if (p2 == 0)
                p++;
            for (int i = 1; i < 3; ++i)
                if (cnt1[i] < cnt1[p] && i != p2)
                    p = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i+j)%3 == p && s[i][j] == 'X')
                    cout << 'O';
                else if ((i+j)%3 == p2 && s[i][j] == 'O')
                    cout << 'X';
                else
                    cout << s[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}