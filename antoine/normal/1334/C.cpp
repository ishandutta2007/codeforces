#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
int n;
cin >> n;
vector<ll> a(n), b(n);
for(int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];
for(int i = 0; i < n; ++i)
    b[i] = min(b[i], a[(i+1)%n]);

    return accumulate(a.begin(), a.end(), 0LL) - accumulate(b.begin(), b.end(), 0LL) + *min_element(b.begin(), b.end());

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
        cout << f() << '\n';
    return 0;
}