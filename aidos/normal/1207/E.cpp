#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m;
void out(vector<int> a) {
    cout << "?";
    for(int i = 0; i < a.size(); i++) {
        cout << " " << a[i];
    }
    cout << endl;
}
void solve() {
    vector<int> a;
    for(int i = 1;  i< (1<<7); i++) {
        if(a.size() < 100) a.push_back(i);
    }
    out(a);
    int x;
    cin >> x;
    for(int i = 0; i < a.size(); i++) {
        a[i] <<= 7;
    }
    out(a);
    int y;
    cin >> y;
    cout << "! " << (x&((1<<14) - (1<<7))) + (y & ((1<<7)-1)) << endl;
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}