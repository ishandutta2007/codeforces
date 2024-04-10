#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    vector<int> arr_sorted = arr;
    sort(arr_sorted.begin(), arr_sorted.end());
    vector<vector<int>> ans;
    auto make = [&](vector<int> d) {
        ans.push_back(d);
        vector<vector<int>> arr2;
        int pos = 0;
        for (int &x : d) {
            arr2.push_back({});
            for (int i = 0; i < x; i++) {
                arr2.back().push_back(arr[pos + i]);
            }
            pos += x;
        }
        reverse(arr2.begin(), arr2.end());
        arr.clear();
        for (auto &el : arr2) {
            for (auto &el2 : el) {
                arr.push_back(el2);
            }
        }
    };

    while (arr != arr_sorted) {
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }
        for (int k = 1; k < n; k++) {
            if (pos[k] < pos[k - 1]) {
                int fst = pos[k];
                int cnt = 1;
                while (k + cnt == arr[pos[k] + cnt]) {
                    cnt++;
                }
                int snd = fst + cnt;
                int thrd = pos[k - 1] + 1;
                vector<int> arr_ = {fst, snd - fst, thrd - snd, n - thrd};
                vector<int> arr__;
                for (int &el : arr_) {
                    if (el != 0) {
                        arr__.push_back(el);
                    }
                }
                make(arr__);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &el : ans) {
        cout << el.size() << ' ';
        for (auto &el2 : el) {
            cout << el2 << ' ';
        }
        cout << endl;
    }
}