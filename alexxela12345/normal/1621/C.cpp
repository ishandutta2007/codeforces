#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int cnt = 0;

int ask(int i) {
    cnt++;
    cout << "? " << i + 1  << endl;
    int x;
    cin >> x;
    return x - 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> used(n);
    cnt = 0;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
        vector<int> arr;
        int cur = i;
        int cntt = 0;
        while (arr.size() < 2 || arr.back() != arr[0]) {
            cur = ask(i);
            arr.push_back(cur);
            cntt++;
        }
        if (arr.back() == arr[0])
            arr.pop_back();
        for (int el : arr)
            used[el] = 1;
        for (int i = 0; i  < (int) arr.size(); i++) {
            ans[arr[i]] = arr[(i + 1) % (int) arr.size()];
        }
    }
    cout << "!";
    for (int el : ans) {
        cout << " " << el + 1;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}