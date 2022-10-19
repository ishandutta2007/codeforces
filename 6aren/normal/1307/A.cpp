#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int a[105];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= d; i++) {
            for (int j = 2; j <= n; j++) {
                if (a[j] > 0) {
                    a[j - 1]++;
                    a[j]--;
                    break;
                }
            }
        }
        cout << a[1] << '\n';
    }
    return 0;
}