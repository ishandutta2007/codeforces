#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, m;
int a[maxn];
void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ll pl = 2;
    while(pl < n && a[2] == a[pl]) ++pl;
    if(a[2] > a[1]) {
        cout << pl - 2 << "\n";
        return;
    }
    if(a[1] > a[0]) {
        cout << (pl-1) * (pl-2)/2 << "\n";
        return;
    }
    cout << pl * (pl - 1) * (pl - 2)/6 << "\n";
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