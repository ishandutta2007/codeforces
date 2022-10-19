#include <bits/stdc++.h>
using namespace std;

bool cmp1(pair<pair<int, int>, int> el1, pair<pair<int, int>, int> el2) {
    return el1.first.second > el2.first.second;
}

bool cmp2(pair<pair<int, int>, int> el1, pair<pair<int, int>, int> el2) {
    return el1.first.second < el2.first.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<pair<pair<int, int>, int>> a1, a2;
    for (int i = 0; i < n; i++) {
        if (arr[i].first > arr[i].second) {
            a2.push_back({arr[i], i});
        } else {
            a1.push_back({arr[i], i});
        }
    }
    sort(a1.begin(), a1.end(), cmp1);
    sort(a2.begin(), a2.end(), cmp2);
    if (a1.size() > a2.size()) {
        cout << a1.size() << endl;
        for (int i = 0; i < a1.size(); i++) {
            cout << a1[i].second + 1 << " ";
        }
        cout << endl;
    } else {
        cout << a2.size() << endl;
        for (int i = 0; i < a2.size(); i++) {
            cout << a2[i].second + 1 << " ";
        }
        cout << endl;
    }
}