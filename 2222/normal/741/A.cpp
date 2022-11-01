#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)      for(int i(a),b_(b);i<b_;++i)
#define REP(i,n)        for(int i=0;i<n;++i)
#define CL(a,x)         memset(a,x,sizeof(a))
#define all(a)          (a).begin(),(a).end()
#define sz(a)           int((a).size())
#define pb              push_back
#define X               first
#define Y               second
using ll =              long long;
using vi =              vector<int>;
using pii =             pair<int, int>;

int gcd(int x, int y) {
    for (; y; swap(x %= y, y));
    return x;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vi p(n);
    REP (i, n) {
        cin >> p[i];
        --p[i];
    }
    vector<bool> u(n);
    ll r = 1;
    REP (i, n) if (!u[i]) {
        int k = 0;
        for (int j = i; !u[j]; j = p[j]) {
            u[j] = true;
            ++k;
        }
        if (k % 2 == 0)
            k /= 2;
        r *= k / gcd(r % k, k);
    }
    sort(all(p));
    FOR (i, 1, n) if (p[i - 1] == p[i]) r = -1;
    cout << r << endl;
    return 0;
}