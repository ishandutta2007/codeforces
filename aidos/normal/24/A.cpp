#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

int n;

vector < pii > v[111];
bool used[111];

int get(int x, int p){
    if(used[x]) return 0;
    used[x] = 1;
    for(int i = 0; i < v[x].size(); i++){
        int to = v[x][i].f;
        int c = v[x][i].s;
        if( to == p) continue;
        return get(to, x) + c;
    }
    return 0;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0, a, b, c; i < n; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        v[a].pb(mp(b, 0));
        v[b].pb(mp(a, c));
    }
    int mi  = get(0, v[0][1].f);
    memset(used, 0, sizeof used);
    cout << min(mi, get(0, v[0][0].f)) << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}