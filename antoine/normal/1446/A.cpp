#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    int n;
    ll W;
    cin >> n >> W;
    vector<int> a(n);

    for(int &x: a)
        cin >> x;

    ll sum = 0;
    vector<int> res;

    const ll th = (W + 1) / 2;

    for(int i = 0; i < n; ++i) {
        if(a[i] > W)
            continue;
        if(a[i] >= th) {
            sum = a[i];
            res = vector<int>{i};
            break;
        }
        if(sum < th) {
            sum += a[i];
            res.push_back(i);
        }
    }
    if(sum < th) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << '\n';
    for(int i:  res)
        cout << i + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;

    while(t--) {
        f();
    }
    return 0;
}