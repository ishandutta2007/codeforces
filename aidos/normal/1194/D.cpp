#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
int n, m;
void solve() {
    cin >> n >> m;
    if(m % 3 > 0) {
        if(n % 3 == 0) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
        return;
    }
    n %= (m + 1);
    if(n % 3 > 0 || n == m) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}


int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}