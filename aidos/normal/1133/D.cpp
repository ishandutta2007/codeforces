#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];
int b[maxn];
void solve() {
    cin >> n;
    map<pii, int> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt = 0, mx = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]==0) {
            if(b[i] == 0) cnt++;
            continue;
        }
        int z = __gcd(abs(b[i]), abs(a[i]));
        pii x = make_pair(-b[i]/z,a[i]/z);
        if(x.second < 0) {
            x.second *= -1;
            x.first *= -1;
        }
        m[x]++;
    }
    for(auto v: m) {
        mx = max(mx, v.second);
    }
    cout << mx + cnt << "\n";
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