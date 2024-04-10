#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, k, s, t;
ll c[N];
ll v[N];
ll pos[N];
ll pref[N];


ll getSum(int l, int r) {
    return pref[r] - pref[l];
}

void read() {
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &c[i], &v[i]);
    for (int i = 0; i < k; i++)
        scanf("%lld", &pos[i]);
}

void solve() {
    pos[k++] = 0;
    pos[k++] = s;
    sort(pos, pos + k);
    vector<int> l;
    for (int i = 0; i < k - 1; i++)
        l.pb(pos[i + 1] - pos[i]);
    sort(all(l));
    for (int i = 0; i < (int)l.size(); i++) {
        pref[i + 1] = pref[i] + l[i]; 
    }

    ll answer = INF;
    for (int i = 0; i < n; i++) {
        if (v[i] < l.back()) continue;

        int g = upper_bound(all(l), v[i] / 2) - l.begin();
        ll p1 = getSum(0, g); 
        ll p2 = getSum(g, l.size()) * 2;
        p2 -= (l.size() - g) * 1ll * v[i] - getSum(g, l.size());
        if (p1 + p2 <= t)
            answer = min(answer, c[i]);
    }

    if (answer == INF) answer = -1;

    cout << answer << endl;
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}