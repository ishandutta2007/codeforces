#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    int n = sqrt(2 * (a + b));
    while (n * (n + 1) > 2 * (a + b)) n--;
    int cura = a, curb = b;
    vector <int> ans;
    for (int i = n; i > 0; i--) {
        if (a < i) {
            b -= i;
            ans.push_back(i);
        } else a -= i;
    }
    cout << n - ans.size() << "\n";
    for (int i = n; i > 0; i--) {
        if (cura < i) {
            curb -= i;
        } else {
            cura -= i;
            cout << i << " ";
        }
    }
    cout << "\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}