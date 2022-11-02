#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
int n, m;
pair<int, int> a[maxn];
int ansa[maxn];
int ansb[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int d = n/3;
    for(int i = 0; i < n; i++) {
        if(i < d) {
            ansa[a[i].second] = i;
            ansb[a[i].second] = a[i].first - i;
        } else if(i < 2 * d){
            ansb[a[i].second] = i;
            ansa[a[i].second] = a[i].first - i;
        } else if(i < 3 * d){
            ansb[a[i].second] = 3*d-1-i;
            ansa[a[i].second] = a[i].first - ansb[a[i].second];
        } else if(i == 3 * d + 1){
            ansb[a[i].second] = a[i].first;
        } else {
            ansa[a[i].second] = a[i].first;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << ansa[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; i++) {
        cout << ansb[i] << " ";
    }
    cout << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}