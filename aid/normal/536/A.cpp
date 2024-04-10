#include <iostream>

using namespace std;

const int MAXX = 1000 * 1000 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a, b;
    int n;
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++) {
        int l, t, m;
        cin >> l >> t >> m;
        if(a + (l - 1) * b > t) {
            cout << -1 << '\n';
            continue;
        }
        int ll = l, rr = MAXX;
        while(ll < rr - 1) {
            int mm = (ll + rr) / 2;
            if(a + (mm - 1) * b > t) {
                rr = mm;
                continue;
            }
            long long sum = ((2 * a + (mm - 1) * b) * mm) / 2 -
                (l > 1? ((2 * a + (l - 2) * b) * (l - 1)) / 2 : 0);
            if((sum + t - 1) / t > m)
                rr = mm;
            else
                ll = mm;
        }
        cout << ll << '\n';
    }
    return 0;
}