#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e6;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int ans = 1;
    int curl = 1;
    frab(i, 1, n) {
        if (a[i] >= a[i - 1]) {
            curl++;
            ans = max(ans, curl);
        }
        else {
            curl = 1;
        }
    }
    cout << ans;
}