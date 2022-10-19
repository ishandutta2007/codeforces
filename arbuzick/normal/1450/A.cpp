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
        string a;
        cin >> a;
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i)
            cnt[a[i]-'a']++;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                cout << char(i+'a');
            }
        }
        cout << '\n';
    }
    return 0;
}