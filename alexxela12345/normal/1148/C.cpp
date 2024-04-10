#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        pos[arr[i]] = i;
    }
    vector<pair<int, int>> ops;
    for (int i = 0; i < n - 1; i++) {
        if (i == pos[i]) {
            continue;
        }
        if (i * 2 < n) {
            if ((pos[i] - i) * 2 >= n) {
                ops.push_back({pos[i], i});
                swap(arr[pos[i]], arr[i]);
                swap(pos[i], pos[arr[pos[i]]]);
            } else if (pos[i] * 2 < n) {
                ops.push_back({pos[i], n - 1});
                ops.push_back({n - 1, i});
                ops.push_back({pos[i], n - 1});
                swap(arr[pos[i]], arr[i]);
                swap(pos[i], pos[arr[pos[i]]]);
            } else {
                ops.push_back({pos[i], 0});
                ops.push_back({0, n - 1});
                ops.push_back({n - 1, i});
                ops.push_back({n - 1, 0});
                ops.push_back({pos[i], 0});
                swap(arr[pos[i]], arr[i]);
                swap(pos[i], pos[arr[pos[i]]]);
            }
        } else {
            if (pos[i] * 2 < n) {
                ops.push_back({pos[i], n - 1});
                ops.push_back({n - 1, 0});
                ops.push_back({0, i});
                ops.push_back({n - 1, 0});
                ops.push_back({pos[i], n - 1});
                swap(arr[pos[i]], arr[i]);
                swap(pos[i], pos[arr[pos[i]]]);
            } else {
                ops.push_back({pos[i], 0});
                ops.push_back({0, i});
                ops.push_back({0, pos[i]});
                swap(arr[pos[i]], arr[i]);
                swap(pos[i], pos[arr[pos[i]]]);
            }
        }
    }
    cout << ops.size() << endl;
    for (auto el : ops) {
        cout << el.first + 1 << " " << el.second + 1<< endl;
    }
}