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
const int N = 5e5;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
int a[N];
ll pref[N];
bool use[N];


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + max(0, a[i]);

    map<int,int> f;
    ll answer = -1e18;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (f.count(a[i]) == 0) {
            f[a[i]] = i;
        }
        else {
            ll res = a[i] * 2 + pref[i] - pref[f[a[i]] + 1];
            if (res > answer) {
                answer = res;
                l = f[a[i]];
                r = i;
            }
        }
    }

    use[l] = 1;
    use[r] = 1;
    for (int i = l + 1; i < r; i++)
        if (a[i] >= 0)
            use[i] = 1;

    vector<int> tmp;
    for (int i = 0; i < n; i++)
        if (!use[i])
            tmp.pb(i);
            
    cout << answer << " " << tmp.size() << endl;
    for (auto x: tmp)
        cout << x + 1 << " ";
    cout << endl;
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