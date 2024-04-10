#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, m, k;
int l[maxn];
int r[maxn];
vector<int> qu[maxn];
int id[maxn];
int ans[maxn];
int t[maxn];
int get(int pos) {
    int res = 0;
    while(pos >= 0) {
        res += t[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}
void upd(int pos, int val) {
    while(pos <= 2 * n) {
        t[pos] += val;
        pos |= (pos + 1);
    }
}
void solve(){
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        a.emplace_back(l[i]);
        a.emplace_back(r[i]);
    }
    sort(a.begin(), a.end());
    memset(id, -1, sizeof id);
    for(int i = 0; i < n; i++) {
        l[i] = lower_bound(a.begin(), a.end(), l[i]) - a.begin();
        r[i] = lower_bound(a.begin(), a.end(), r[i]) - a.begin();
        id[r[i]] = i;
    }
    vector<int> st;
    for(int i = 0; i < 2*n; i++) {
        if (id[i] == -1) continue;
        int cur = id[i];
        ans[cur] = get(2*n) - get(l[cur]);
        upd(l[cur], 1);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
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