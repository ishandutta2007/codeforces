#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int a[maxn];
void solve() {
    cin >> n;
    if(n == 0) {
        cout << "YES\n";
        for(int x: {1, 1, 3, 3}) {
            cout << x << "\n";
        }
        return;
    }
    if(n == 1) {
        int y;
        cin >> y;
        cout << "YES\n";
        for(int x: {1, 3, 3}) {
            cout << x*y << "\n";
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if(n == 4) {
        if(a[0] + a[3]==a[1] + a[2] && a[3] == a[0] * 3) {
            cout << "YES\n";
        }else cout << "NO\n";
        return;
    }
    //a[0]  + a[3] = a[1] + a[2]
    //a[3]  = 3*a[0]
    //4*a[0] = a[1] + a[2]
    //4*a[0]
    if(n == 2) {
        if(a[1] > a[0] * 3) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << 4 * a[0] - a[1] << "\n";
        cout << 3 * a[0] << "\n";
        return;
    }
    if(a[1] + a[2] == 4*a[0]) {
        cout <<"YES\n";
        cout << 3 * a[0] << "\n";
        return;
    }
    if(a[2] == 3 * a[0]) {
        cout << "YES\n";
        cout << 4 * a[0] - a[1] << "\n";
        return;
    }
    if(a[2] % 3 == 0 && a[0] + a[1] == a[2] * 4/3) {
        cout <<"YES\n";
        cout<<a[2]/3 << "\n";
        return;
    }
    cout << "NO\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}