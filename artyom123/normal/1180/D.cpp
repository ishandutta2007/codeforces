#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int l = 1, r = m, i = 1, j = n;
    while (l <= r) {
        if (l != r) {
            cout << i << " " << l << "\n";
            cout << j << " " << r << "\n";
            i++;
            j--;
            if (i <= n) {
                continue;
            }
            l++;
            r--;
            i = 1;
            j = n;
        }
        else {
            int y = 1;
            int v = n - 1;
            cout << y << " " << l << "\n";
            while (y != n / 2 + 1) {
                if (y < n / 2 + 1) {
                    cout << y + v << " " << l << "\n";
                    y += v;
                    v--;
                }
                else {
                    cout << y - v << " " << l << "\n";
                    y -= v;
                    v--;
                }
            }
            return 0;
        }
    }
    return 0;
}