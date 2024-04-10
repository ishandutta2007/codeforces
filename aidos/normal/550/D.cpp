#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;

void solve() {
    cin >> k;
    if(k % 2 == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if(k == 1) {
        cout << 2 << " " << 1 << "\n";
        cout << 1 << " " << 2 << "\n";
        return;
    }
    n=2*k+4;
    cout << n << " " << n * k/2 << "\n";
    for(int i = 2; i <= k; i++) {
        cout << 1 << " " << i << "\n";
        cout << 1 + n/2 << " " << i + n/2 << "\n";
        cout << k + 1 << " " << i << "\n";
        cout << k + 2 << " " << i << "\n";
        cout << k + 1 + n/2 << " " << i + n/2<< "\n";
        cout << k + 2 + n/2 << " " << i + n/2 << "\n";
    }
    for(int i=2; i <= k; i++){
        for(int j = i + 1; j <= k; j++) {
            if(j - i == 1 && i % 2 == 0) continue;
            cout << i << " " << j << "\n";
            cout << i+n/2 << " " << j+n/2 << "\n";
        }
    }
    cout << k + 1 << " " << k + 2 << "\n";
    cout << n/2 + k + 1 << " " << n/2 + k + 2 << "\n";
    cout << 1 << " " << n/2 + 1 << "\n";
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