#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e5;
const int INF = 2e9;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    fr(i, n) {
        int pos = lower_bound(a + i, a + n, a[i] * 2 + 1) - a;
        //cout << i << " " << a[i] << " "  << pos << endl;
        ans = max(ans, pos - i);
    }
    cout << n - ans;
}