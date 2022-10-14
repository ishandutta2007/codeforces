#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

#define pb push_back

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> arr(n);
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    int ans = 0;
    for (auto &l : arr) {
        cin >> l;
        if (l == 4) {
            a++;
        }
        if (l == 8) {
            if (a == 0) {
                ans++;
                continue;
            }
            b++;
            a--;
        }
        if (l == 15) {
            if (b == 0) {
                ans++;
                continue;
            }
            c++;
            b--;
        }
        if (l == 16) {
            if (c == 0) {
                ans++;
                continue;
            }
            d++;
            c--;
        }
        if (l == 23) {
            if (d == 0) {
                ans++;
                continue;
            }
            e++;
            d--;
        }
        if (l == 42) {
            if (e == 0) {
                ans++;
                continue;
            }
            e--;
        }
    }
    cout << ans + a + 2 * b + 3 * c + 4 * d + 5 * e;
    return 0;
}