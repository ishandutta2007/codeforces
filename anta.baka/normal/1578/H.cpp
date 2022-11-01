#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> a;
    long long s = 0;
    while (n--) {
        int x;
        cin >> x;
        if (s + x >= 0) {
            a.insert(x);
            s += x;
        } else if (!a.empty()) {
            int l = *a.begin();
            if (x >= l) {
                a.erase(a.begin());
                a.insert(x);
                s += -l + x;
            }
        }
    }
    cout << a.size();
}