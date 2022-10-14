#include <bits/stdc++.h>

using namespace std;

bool cmpa(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

bool cmpb(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a, b;
    map<pair<int, int>, int> pos;
    for (int i = 0; i < n; i++) {
        pair<int,int> x;
        cin >> x.first >> x.second;
        pos[x] = i + 1;
        if (x.first < x.second) {
            a.push_back(x);
        }
        else {
            b.push_back(x);
        }
    }
    sort(a.begin(), a.end(), cmpa);
    sort(b.begin(), b.end(), cmpb);
    if (a.size() < b.size()) {
        cout << b.size() << endl;
        for (auto u : b) {
            cout << pos[u] << ' ';
        }
    }
    else {
        cout << a.size() << endl;
        for (auto u : a) {
            cout << pos[u] << ' ';
        }
    }
    return 0;
}