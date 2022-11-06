#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)2e5 + 9;
int a[MxN + 9];

bool f() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i) {
        a[i] += i;
        a[i] %= n;
        if(a[i] < 0)
            a[i] += n;
    }
    sort(a, a + n);
        for(int i = 0; i < n; ++i)
            if(a[i] != i)
                return false;
            return true;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << (f() ? "YES" : "NO") << '\n';
    }
    return 0;
}