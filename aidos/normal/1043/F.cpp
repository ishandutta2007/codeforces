#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn], b[maxn];
void solve() {
    cin >> n;
    int g = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
        g =__gcd(x, g);
        if(x == 1) {
            cout << 1 << "\n";
            return;
        }
    }
    if(g != 1) {
        cout << -1 << "\n";
        return;
    }
    n = 300100;
    vector<int> b;
    for(int i = 1; i <= n; i++) {
        if(a[i] > 0) {
            for(int j = i * 2; j <= n; j+=i) {
                a[j] = 0;
            }
            b.emplace_back(i);
        }
    }
    int ans = min(20, (int)b.size());
    while(clock() * 1.0/CLOCKS_PER_SEC < 0.3) {
        random_shuffle(b.begin(), b.end());
        for(int i = ans - 1; i < b.size(); i++) {
            int g = 0;
            for(int j = 0; j < ans - 1; j++) {
                g = __gcd(g, b[i - j]);
                if(g == 1) {
                    ans = j + 1;
                    break;
                }
            }
        }
        if(ans == 2) break;
    }
    cout << ans << "\n";
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