#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    
    for (int i = 0; i < n; i++) {
        auto it = b.lower_bound(n - a[i]);
        if (it == end(b)) {
            it = begin(b);
        }
        cout << (a[i] + *it) % n << ' ';
        b.erase(it);
    }
    
    return 0;
}