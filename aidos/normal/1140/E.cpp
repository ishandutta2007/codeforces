#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, k;
ll dp[2][maxn];
ll get(int id, int pos) {
    if(pos == 1) {
        if(id) return k-1;
        return k - 2;
    }
    ll &res = dp[id][pos];
    if(res != -1) return res;
    res = 0;
    if(id) {
        res = get(0, pos-1) * (k - 1) % mod;
    } else {
        res = (get(0, pos-1) * (k-2) + get(1, pos-1)) % mod;
    }
    return res;
}
ll calc(vector<int> a) {
    if(a.size() == 0) return 1;
    ll ans = 1;
    for(int i = 1; i < a.size(); i++) {
        if(a[i] == a[i-1] && a[i] > 0) return 0;
    }
    for(int i = 0; i < a.size(); ) {
        if(a[i] > 0) {
            i++;
            continue;
        }
        int j = i;
        while(i < a.size() && a[i] == -1) {
            i++;
        }
        int len = i - j;
        if(j == 0 && i == a.size()) {
            ans = (ans * k) % mod;
            for(int t = 1; t < len; t++) {
                ans = (ans * (k-1)) % mod;
            }
        }else if(j == 0 || i == a.size()){
            for(int t = 0; t < len; t++) {
                ans = (ans * (k-1)) % mod;
            }
        } else {
            ans = (ans * get(a[i] == a[j-1], len)) % mod;
        }
    }
    return ans;
}
void solve() {
    cin >> n >> k;
    vector<int> a, b;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i % 2 == 0) a.emplace_back(x);
        else b.emplace_back(x);
    }
    cout << calc(a) * calc(b) % mod << "\n";

}


int main() {
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