#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e6 + 123;
const int mod = 1e9 + 9;
int n;
pair<int, int> a[maxn];
pair<int, int> u[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    //n = min(n, 3000);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int d = a[j].first - a[i].first;
            if(u[d].first) {
                cout << "YES\n";
                cout << u[d].first << " " << a[j].second << " " << u[d].second << " " << a[i].second << "\n";
                return;
            }
        }
        for(int j = 0; j < i; j++) {
            u[a[i].first - a[j].first] = make_pair(a[j].second, a[i].second);
        }
    }
    cout << "NO\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}