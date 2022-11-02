#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];

void solve() {
    cin >> n;
    vector<int> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(d.size() > 0 && d.back() == a[i]) {
            a[i]++;
            d.pop_back();
        }
        d.push_back(a[i]);
    }
    cout << d.size() << "\n";
    for(int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}