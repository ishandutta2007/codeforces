#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, k;
void solve(){
    cin >> n >> k;
    map<ll, ll> d;
    vector<ll> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= k;
        if(x != 0) {
            if(d.count(k-x)) {
                d[k - x] = d[k - x] + k;
            } else {
                d[k-x] = k - x;
            }
            a.emplace_back(d[k-x]);
        }
    }
    if(a.size() == 0) {
        cout << 0 << "\n";
        return;
    }
    cout << *max_element(a.begin(), a.end()) + 1 << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}