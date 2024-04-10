#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
int last[maxn];
int pos[maxn];

void solve() {
    string s;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(pos[a[i]] == 0) pos[a[i]] = i;
    }
    vector<int> g;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        if(last[x]) {
           int z = 0;
           while(g[z] != x) z++;
           cout << g.size() - z << " ";
           g.erase(g.begin() + z);
           g.push_back(x);
        } else {
            int ans = g.size() + pos[x];
            for(int t: g) {
                if(pos[t] < pos[x]) ans--;
            }
            g.push_back(x);
            cout << ans << " ";
        }
        last[x] = 1;
    }

}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}