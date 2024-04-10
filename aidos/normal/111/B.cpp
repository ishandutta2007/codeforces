#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, m, k;
vector<int> g[maxn];
vector<int> d[maxn];
int a[maxn];
int last[maxn];
void solve(){
    for(int i = 1; i < maxn; i++) {
        for(int j = i; j < maxn; j += i) d[j].emplace_back(i);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for(int to: d[x]) {
            if(last[to] < i - y) {
                ans++;
            }
            last[to] = i;
        }
        cout << ans << "\n";
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