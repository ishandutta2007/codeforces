#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
int a[maxn];
int p[maxn];
bool cmp(int i, int j) {
    return a[i] > a[j];
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i;
    }
    sort(p, p + n, cmp);
    cout << p[0] + 1 << " " << a[p[1]] << "\n";

}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}