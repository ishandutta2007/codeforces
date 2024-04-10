#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    cin >> n >> k;
    set<int> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int x = 1;
    for(int it = 1; it <= k; it++) {
        while(s.count(x)) ++x;
        x++;
        while(s.count(x)) ++x;
    }
    cout << x-1 << "\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}