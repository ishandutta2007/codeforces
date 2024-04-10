#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    //sort(a, a + n);
    cout << -a[0] << " ";
    for(int i = 1; i < n; i ++) {
        if(i & 1) cout << a[i] << " ";
        else cout << -a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}