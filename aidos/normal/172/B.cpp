#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int r[maxn];
int a, b;
int m;
void solve() {
    cin >> a >> b >> m >> r[0];
    for(int i = 1; i < maxn; i++) {
        r[i] = (r[i - 1] * a + b) % m;
    }
    vector<int> s;
    for(int i = 2e5; i < maxn;i++) {
        s.emplace_back(r[i]);
    }
    int n = (int) s.size();
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[0]) {
            cout << i << "\n";
            return;
        }
    }
    cout << n << "\n";
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