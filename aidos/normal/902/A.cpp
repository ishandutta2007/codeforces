#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, x = 0;
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a <= x) {
            x = max(x, b);
        }
    }
    if(x == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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