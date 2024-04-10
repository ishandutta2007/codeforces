#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m, k;
int a[maxn];
void solve() {
    cin >> n;
    set<int> good, bad;
    map<int, int> ind;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i + 1;
        if (bad.count(a[i])) continue;
        if (good.count(a[i])) {
            good.erase(a[i]);
            bad.insert(a[i]);
        } else {
            good.insert(a[i]);
        }
    }
    if(good.size() == 0) {
        cout << -1 << "\n";
    }
     else {
         cout << ind[*good.begin()] << "\n";
     }
}

int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}