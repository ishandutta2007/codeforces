#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n;
string s;
pair<ll, int> cnta[111];
pair<ll, int> cntb[111];
void solve() {
    cin >> n >> s;

    for(int mask = 0; mask < (1<<n); mask++) {
        int ca = 0;
        int cb = 0;
        ll da = 0;
        ll db = 0;
        ll xa = 0;
        ll xb = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) {
                da = da * 10 + s[i] - '0';
                xa = xa * 10 + s[n + i] - '0';
                ca++;
            } else {
                db = db * 10 + s[i] - '0';
                xb = xb * 10 + s[n + i] - '0';
                cb++;
            }
        }
        for(int i = ca; i < n; i++) {
            da *= 10;
        }
        for(int i = cb; i < n; i++) {
            db *= 10;
        }
        cnta[ca] = max(cnta[ca], make_pair(da + db, mask));
        cntb[ca] = max(cntb[ca], make_pair(xa + xb, mask));
    }
    ll ans = -1;
    int cur;
    for(int i = 0; i <= n; i++) {
        if(cnta[i].first + cntb[n - i].first > ans) {
            ans = cnta[i].first + cntb[n - i].first;
            cur = i;
        }
    }
    for(int i = 0; i < n; i++) {
        if(cnta[cur].second & (1<<i)) cout << "H";
        else cout << "M";
    }
    for(int i = 0; i < n; i++) {
        if(cntb[n-cur].second & (1<<i)) cout << "H";
        else cout << "M";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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