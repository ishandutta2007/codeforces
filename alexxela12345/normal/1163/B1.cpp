#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    vector<int> cnt(10);
    int max_x = 1;
    for (int i = 0; i < n; i++) {
        cnt[arr[i]]++;
        map<int, int> cnt2;
        for (int j = 0; j < 10; j++) {
            if (cnt[j] != 0) {
                cnt2[cnt[j]]++;
            }
        }
        if (cnt2.size() == 1) {
            if (cnt2.begin()->first == 1 || cnt2.begin()->second == 1) {
                max_x = i + 1;
            }
        } else if (cnt2.size() == 2) {
            int a = cnt2.begin()->first;
            int aa = cnt2[a];
            int b = cnt2.rbegin()->first;
            int bb = cnt2[b];
            if (a == 1 && aa == 1) {
                max_x = i + 1;
            } else if (b == a + 1 && bb == 1) {
                max_x = i + 1;
            }
        }
    }
    cout << max_x << endl;
}