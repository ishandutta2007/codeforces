#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
int n, k;
cin >> n >> k;
vector<int> res;
for(int i = (k+1)/2; i <= n; ++i)
    if(i !=k )
        res.push_back(i);
    cout << res.size() << '\n';
    for(int x : res)
        cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        f();
    }
    return 0;
}