#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int a[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, h, m;
    cin >> n>>h>>m;

    fill(a, a+99, h);

    while(m--) {
        int l,r,x;
        cin >> l >> r >> x;
        while(l <= r) {
            a[l] = min(a[l], x);
            l++;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += a[i] * a[i];
    cout << ans;
    return 0;
}