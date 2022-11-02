#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int p[maxn];
void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        if(p[i] % p[0] != 0) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << 2 * n << "\n";
    for(int i = 0; i < n; i++) {
        cout << p[0] << " " << p[i] << " ";
    }
}

int main() {
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