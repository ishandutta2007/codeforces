#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
const int K = 18;
int st[N][K];
int lg[N];

int get(int l, int r) {
    int b = lg[r - l + 1];
    return __gcd(st[l][b], st[r - (1 << b) + 1][b]);
}

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    lg[1] = 0;
    for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> s(n);
    vector <pair <int, int> > d;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        d.push_back({s[i], i});
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        st[i][0] = s[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 1; k < K; k++) {
            st[i][k] = st[i][k - 1];
            if (i + (1 << (k - 1)) < n) {
                st[i][k] = __gcd(st[i][k], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int f = get(l, r);
        int res = upper_bound(d.begin(), d.end(), make_pair(f, r)) - lower_bound(d.begin(), d.end(), make_pair(f, l));
        cout << r - l + 1 - res << '\n';
    }
}