#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
int a, b, c;
void solve() {
    cin >> a >> b >> c;
    cin >> n;
    vector <pii> cur;
    for(int i = 0; i < n; i++) {
        string val;
        cin >> x >> val;
        if(val == "USB") cur.push_back(make_pair(x, 0));
        else cur.push_back(make_pair(x, 1));
    }
    sort(cur.begin(), cur.end());
    int cnt = a + b + c;
    ll cost = 0;
    for(int i = 0; i < cur.size(); i++) {
        if(cur[i].second == 0 && a > 0) {
            a--;
            cost += cur[i].first;
            continue;
        }
        if(cur[i].second == 1 && b > 0) {
            b--;
            cost += cur[i].first;
            continue;
        }
        if(c == 0) continue;
        c--;
        cost += cur[i].first;
    }
    cout << cnt - a - b - c << " " << cost << "\n";
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