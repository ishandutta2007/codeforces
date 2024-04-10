#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    auto ask = [](int x) {
        cout << "? " << x << endl;
        int u;
        cin >> u;
        return u;
    };

    int l = 1, r = n;
    while (r > l) {
        int mid = (l + r) / 2;
        if (ask(mid) > ask(mid + 1)) l = mid + 1;
        else r = mid;
    }

    cout << "! " << l << endl;

    return 0;
}