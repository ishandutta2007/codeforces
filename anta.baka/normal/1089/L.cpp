#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int inf = 1e9+100;
const int nax = 1e5;

int n, k;
int a[nax], b[nax];
vi who[nax];
int need;
vi cand;
ll ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) who[a[i]].pb(b[i]);
    for(int i = 0; i < k; i++) {
        if(who[i].empty()) need++;
        else {
            sort(all(who[i]));
            for(int j = 0; j < sz(who[i]) - 1; j++) cand.pb(who[i][j]);
        }
    }
    sort(all(cand));
    for(int i = 0; i < need; i++) ans += cand[i];
    cout << ans;
}