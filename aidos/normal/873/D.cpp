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
int a[maxn];
void A(int l, int r) {
    if(k == 0) { 
        sort(a + l, a + r);
        return;
    }
    if(l + 1 >= r) return;
    int mid = (l + r)/2;
    k-=2;
    A(l, mid);
    A(mid, r);
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        a[i] = n-i;
    }
    if(k % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    k--;
    A(0, n);
    if(k != 0) {
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
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