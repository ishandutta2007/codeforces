#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
vector<int> g[maxn];
int a[maxn];
int ans[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] <= m) g[a[i]].emplace_back(i);
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j += i) {
            ans[j] += g[i].size();
        }
    }
    int ind = 1;
    for(int i = 1; i <= m; i++) {
        if(ans[ind] < ans[i]) ind = i;
    }
    cout << ind << " "<< ans[ind] << "\n";
    for(int i = 1; i <= n; i++) {
        if(ind % a[i] == 0) cout << i << " ";
    }

}


int main() {
    ios_base::sync_with_stdio(0);
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