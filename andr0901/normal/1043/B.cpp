#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1);
    a[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i + 1];
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        bool flag = 0;
        for (int j = i; j <= n; j++) {
            if (a[j] - a[j - i] != a[i]) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            ans.push_back(i);
    }
    //ans.push_back(n);
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}