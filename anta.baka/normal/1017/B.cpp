#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
const int maxn = 1e6, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
        char x; cin >> x; a[i] = x - '0';
    }
    for(int i = 0; i < n; i++) {
        char x; cin >> x; b[i] = x - '0';
    }
    ll c0 = 0, c1 = 0, c01 = 0, c11 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            c0++;
            if(b[i] == 1) c01++;
        }
        if(a[i] == 1) {
            c1++;
            if(b[i] == 1) c11++;
        }
    }
    cout << c0 * c1 - c01 * c11;
}