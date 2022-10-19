#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> v(a.size() + b.size());
    auto it = set_difference(a.begin(), a.end(), b.begin(), b.end(), v.begin());
    v.resize(it - v.begin());
    cout << v[0] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    vector<int> c(n - 2);
    for (int &el : a) {
        cin >> el;
    }
    for (int &el : b) {
        cin >> el;
    }
    for (int &el : c) {
        cin >> el;
    }
    solve(a, b);
    solve(b, c);
}