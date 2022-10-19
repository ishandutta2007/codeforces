#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, k;
        cin >> n >> k;
        int per = (k - 1) / (n - 1);
        cout << per * n + (k - 1) % (n - 1) + 1 << '\n';
    }
    return 0;
}