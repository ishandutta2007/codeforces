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
const int N = 1000;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
pair<int,int> a[N];
ll p[N];
int t;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].S, &a[i].F);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        scanf("%lld",  &p[i]);
}

void solve() {
    sort(a, a + n);
    ll res = 0;
    int cur = 0;
    p[t] = 1e18;
    for (int i = t; i > 0; i--)
        p[i] -= p[i - 1];

    for (int i = 0; i < n; ) {
        ll d = min(a[i].S * 1ll, p[cur]);
        res += (cur + 1) * 1ll * a[i].F * d;
        a[i].S -= d;
        p[cur] -= d;
        if (p[cur] == 0) cur++;
        if (a[i].S == 0) i++;
    }
    cout << res << endl;
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