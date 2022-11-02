#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll k;
void solve() {
    cin >> k;
    if(k < 10) {
        cout << k << "\n";
        return;
    }
    k -= 9;
    ll d = 9;
    int len = 2;
    while(true) {
        ll en = d * 10 + 9;
        if(len*(en - d) < k) {
            k -= len * (en - d);
            d = en;
            len++;
            continue;
        }
        break;
    }
    ll h = (k - 1)/len;
    d++;
    d += h;
    k -= len * h;
    string s = to_string(d);
    cout << s[k-1] << "\n";
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