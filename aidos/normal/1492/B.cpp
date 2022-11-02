#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
int n, m, s;
int a[maxn];
int p[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int pos = n;
    int j = n;
    while(pos > 0) {
        while(p[j] == -1) j--;
        for(int i = p[j]; i <= pos; i++) {
            cout << a[i] << " ";
        }
        int npos=p[j];
        for(int i = npos; i <= pos; i++) {
            p[a[i]] = -1;
        }
        pos = npos - 1;
    }
    cout << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}