#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;  i++) {
        cin >> arr[i];
        arr[i]--;
    }
    set<int> cur;
    int ind = 0;
    int ans = 0;
    while (ind < n) {
        ans++;
        cur.insert(arr[ind]);
        while (ind < n && cur.size()) {
            auto it = cur.find(ind);
            if (it != cur.end()) {
                cur.erase(it);
            }
            ind++;
            if (ind == n || cur.empty()) {
                break;
            }
            cur.insert(arr[ind]);
        }
    }
    cout << ans << endl;
    return 0;
}