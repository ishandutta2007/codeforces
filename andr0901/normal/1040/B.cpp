#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> ans;
    int curr = k + 1;
    while (curr < n) {
        ans.push_back(curr);
        curr += k * 2 + 1;
    }
    //cout << curr << " ";
    if (curr - k <= n) {
        for (int i = 0; i < ans.size(); i++) {
            ans[i] -= curr - n;
        }
        ans.push_back(n);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    return 0;
}