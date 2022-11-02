#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e7 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, k;
int ind[maxn];
void solve() {
    pair<int, int> c;
    ll ans=1ll<<60;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(ind[x] == 0) {
            ind[x] = i;
        } else {
            if(ans > x) {
                ans=x;
                c = make_pair(ind[x], i);
            }
        }
    }
    for(int i = 1; i < maxn; i++) {
        ll val;
        int last = 0;
        for(int j = i; j < maxn; j += i) {
            if(ind[j]) {
                if(last) {
                    if(ans > val * j/i) {
                        ans = val * j/i;
                        c = make_pair(ind[j], last);
                    }
                    break;
                } else {
                    last = ind[j];
                    val = j;
                }
            }
        }
    }
    if(c.first > c.second) swap(c.first, c.second);
    //cout << ans << "\n";
    cout << c.first << " "<< c.second << "\n";
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