#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    int n, k;
    string a, b;
    cin >> n>>k >> a >> b;
    vector<int> v(26, 0);
    for(char c : a)
        ++v[c-'a'];
    for(char c:  b)
        --v[c-'a'];
    for(int i = 0; i < 25; ++i) {
        if(v[i] < 0 || v[i] % k) {
            cout << "No\n";
            return;
        }
        v[i+1] += v[i];
    }
    cout << "Yes\n";
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