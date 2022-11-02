#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int p[maxn];
int pos[maxn];
int ans[maxn];
void solve() {
    cin >> n >> k;
    set<int> s;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        s.insert(i);
    }
    int mv = 1;
    for(int i = n; i >= 1; i--) {
        if(s.count(pos[i])) {
            s.erase(pos[i]);

            ans[pos[i]] = mv;
            for(int j = 0; j < k; j++) {
                auto it = s.lower_bound(pos[i]);
                if(it == s.begin()) break;
                it--;
                ans[*it] = mv;
                s.erase(it);
            }
            for(int j = 0; j < k; j++) {
                auto it = s.lower_bound(pos[i]);
                if(it == s.end()) break;
                ans[*it] = mv;
                s.erase(it);
            }
            mv = 3 - mv;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
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