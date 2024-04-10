#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define filename ""
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, d;
vector<int> g[maxn];
map<int, int> M;
int a[maxn];
set<pii> S;
pii b[maxn];
void rec(int l, int r) {
    if(l > r) return;
    int m = (l + r)/2;
    rec(l, m-1);
    rec(m+1, r);
    for(int i = l; i <= r; i++) {
        for(int &v: g[i]) {
            S.insert(make_pair(a[m], v));
        }
    }
}
void solve() {
    cin >> n;
    int sz = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        b[i] = make_pair(x, y);
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++) {
        int x = b[i].first;
        int y = b[i].second;
        if(M.count(x) == 0) {
            M[x] = sz;
            a[sz] = x;
            sz++;
        }
        g[M[x]].emplace_back(y);
    }
    
    rec(0, sz-1);
    cout << S.size() << "\n";
    for(pii x: S) {
        cout << x.first << " "<< x.second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}