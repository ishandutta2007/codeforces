#include <bits/stdc++.h>
using namespace std;
#define ll long long



signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    vector<int> ans;
    for (int el : arr1) {
        if (find(arr2.begin(), arr2.end(), el) != arr2.end()) {
            ans.push_back(el);
        }
    }
    for (auto el : ans)
        cout << el << " ";
}