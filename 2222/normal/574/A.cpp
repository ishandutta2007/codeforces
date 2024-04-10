#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int res = 0;
    for (; a[0]++ <= max_element(a.begin() + 1, a.end())[0]--; )
        ++res;
    cout << res << endl;
    return 0;
}