#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> x(n + 2);
        for (int i = 1; i <= n; i++) cin >> x[i];
        int ans = 0;
        int l = 0, r = n + 1;
        int a = 0, b = 0;
        bool swit = 0;
        bool done = 0;
        int preva = 0, prevb = 0;
        while (1) {
            if (done) break;
            ans++;
            if (swit == 0) {
                while (preva <= prevb) {
                    l++;
                    a += x[l];
                    preva += x[l];
                    if (l + 1 == r) {
                        done = 1;
                        break;
                    }
                }
                prevb = 0;
            } else {
                while (prevb <= preva) {
                    r--;
                    b += x[r];
                    prevb += x[r];
                    if (r - 1 == l) {
                        done = 1;
                        break;
                    }
                }
                preva = 0;
            }
            swit ^= 1;
        }
        cout << ans << ' ' << a << ' ' << b << "\n";
    }
    return 0;
}