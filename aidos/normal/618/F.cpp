#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)1000200;
const ll inf = (1ll<<50);
int n;
int a[maxn];
int b[maxn];
map<int, int> was;

vector<int> e;

void out2(vector<int> x) {
    cout << x.size() << "\n";
    for(int v: x) cout << v << " ";
    cout << "\n";
}
void out(int pos) {
    vector<int> x, y;
    for(int i = pos; i < e.size(); i++) {
        if(e[i] < 0) x.push_back(-e[i]);
        else y.push_back(e[i]);
    }
    out2(x);
    out2(y);
    exit(0);
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int cur = 0;
    int sum = 0;
    was[sum] = 0;
    int r = 0;
    for(int i = 0; i < n; i++){
        while(sum >= 0) {
            e.push_back(r + 1);
            sum -= b[r];
            if(was.count(sum)) {
                out(was[sum]);
            }
            r++;
            was[sum] = e.size();
        }
        sum += a[i];
        e.push_back(-i-1);
        if(was.count(sum)) out(was[sum]);
        was[sum] = e.size();
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}