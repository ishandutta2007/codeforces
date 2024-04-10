#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x :a)
        cin >> x;

    for (int i = 1; i < n; ++i)
        if (a[i] % 2 != a[i - 1] % 2) {
            sort(a.begin(), a.end());

            break;

        }
    for (int x : a)
        cout << x << ' ';
    return 0;
}