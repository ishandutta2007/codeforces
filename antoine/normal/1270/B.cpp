#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)2e5 + 9;
int a[MxN + 9];

void f() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i < n; ++i)
        if(abs(a[i] - a[i+1]) > 1) {
            cout << "YES\n" << i << ' ' << i + 1 << '\n';
            return;
        }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int _t;
    cin >> _t;
    while(_t--)
        f();
    return 0;
}