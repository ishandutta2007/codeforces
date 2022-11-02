#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int a[3];
int u[maxn];
bool ok() {
    memset(u, 0, sizeof u);
    int cur = 0;
    for(int i = 0; i < maxn; i++) {
        if(u[i] == 0) {
            if(cur == 3) return 0;
            for(int j = i; j < maxn; j += a[cur]) {
                u[j] = 1;
            }
            cur++;
        }
    }
    return 1;
}
void solve() {
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a + 3);
    do{
        if(ok()) {
            cout << "YES\n";
            return;
        }
    }while(next_permutation(a, a + 3));
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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