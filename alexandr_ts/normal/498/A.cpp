#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e5;

struct pt {
    ll x, y;
};// a[N];

int main() {
    pt st, en;
    cin >> st.x >> st.y >> en.x >> en.y;
    ll cnt = 0, n;
    cin >> n;
    fr(i, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        int t1 = (a * st.x + b * st.y + c) / abs((a * st.x + b * st.y + c));
        int t2 = (a * en.x + b * en.y + c) / abs((a * en.x + b * en.y + c));
        if (t1 * t2 < 0)
            cnt++;
    }
    cout << cnt;
}