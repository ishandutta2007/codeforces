#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int it=0; it < n; it++) {
        int cnt = 0;
        for(int i = 0; i < n; i++) cnt += a[i] == i;
        if(cnt == n) {
            cout <<"Yes\n";
            return;
        }
        for(int i = 0; i < n; i++) {
            if(i% 2==0) a[i] = (a[i] + 1) % n;
            else a[i] = (a[i] + n - 1) % n;
        }
    }
    cout << "No\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
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