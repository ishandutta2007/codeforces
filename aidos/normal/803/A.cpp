#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[111][111];
void solve() {
    cin >> n >> k;
    if(k > n * n) {
        cout << -1 << "\n";
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(k > 0) {
            k--;
            a[i][i] = 1;
        }
        for(int j = i + 1; j < n; j++) {
            if(k > 1) {
                a[i][j] = 1;
                a[j][i] = 1;
                k -= 2;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
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