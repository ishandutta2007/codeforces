#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = 998244353;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];
void solve() {
    cin >> n;
    set<pii> S;
    S.insert(make_pair(n, 0));
    for(int i = 1; i <= n; i++) {
        pii x = *(--S.end());
        S.erase(--S.end());
        int len = x.first;
        int pos = -x.second;
        int l = pos;
        int r = pos + len - 1;
        int mid = (l + r)/2;
        a[mid] = i;
        if(l < mid) {
            S.insert(make_pair(mid-l, -l));
        }
        if(mid < r) {
            S.insert(make_pair(r-mid, -mid-1));
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}