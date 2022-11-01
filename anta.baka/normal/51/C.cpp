#include <bits/stdc++.h>
using namespace std;
using ld = double;

int n, a[200000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ld lf = 0, rg = 1e9;
    for(int go = 0; go < 100; go++) {
        ld md = (lf + rg) / 2;

        bool ok = true;
        ld x = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(a[i] > x) {
                if(cnt == 3) {
                    ok = false;
                    break;
                }
                cnt++;
                x = a[i] + 2 * md;
            }

        if(ok) rg = md;
        else lf = md;
    }
    cout.precision(6);
    cout << fixed << lf << endl;
    vector<ld> coord;
    ld x = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > x) {
            coord.push_back(a[i] + lf);
            x = a[i] + 2 * lf;
        }
    coord.resize(3, 0);
    sort(coord.begin(), coord.end());
    for(ld x : coord) cout << fixed << x << ' ';
}