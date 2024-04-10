#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 1; i * i < n + 10; i++) {
            s.insert(n / i);
        }
        for (int i = 0; i * i < n; i++) {
            s.insert(i);
        }
        cout << s.size() << '\n';
        for (auto u : s) {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}