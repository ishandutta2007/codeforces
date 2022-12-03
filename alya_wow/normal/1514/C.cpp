#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int z = 1;
    vector<int> ans;
    for (int i = 1; i < n; i++)
    if (gcd(i, n) == 1) {
        int p = (z * (long long)i) % n;
        ans.push_back(i);
        z = p;
    }
    if (z != 1) {
        for (int i = 0; i < ans.size(); i++)
            if (ans[i] == z) {
                ans.erase(ans.begin() + i);
                break;
            }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i <<  ' ';
}