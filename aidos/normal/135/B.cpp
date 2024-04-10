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

pii a[10];
int b[10];
bool ok(pii x1, pii x2, pii x3, pii x4){
    pii a1 = mp(x2.f-x1.f, x2.s-x1.s);
    pii a2 = mp(x3.f-x2.f, x3.s-x2.s);
    pii a3 = mp(x4.f-x3.f, x4.s-x3.s);
    pii a4 = mp(x1.f-x4.f, x1.s-x4.s);
    return (a1.f * 1ll * a2.f + a1.s * 1ll * a2.s) == 0 && (a3.f * 1ll * a2.f + a3.s * 1ll * a2.s) == 0&& (a3.f * 1ll * a4.f + a3.s *1ll *  a4.s) == 0 && (a1.f * 1ll * a4.f + a1.s * 1ll * a4.s) == 0;
}
ll sqr(int x){
    return x * x;
}
ll dis(pii a, pii b){
    return sqr(a.f - b.f) + sqr(a.s - b.s);
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n=8;
    for(int i = 0; i < n; i++){
        cin >> a[i].f >> a[i].s;
        b[i] = i;
    }
    do{
        if( ok(a[b[0]], a[b[1]], a[b[2]], a[b[3]]) && ok(a[b[4]], a[b[5]], a[b[6]], a[b[7]]) && dis(a[b[0]], a[b[1]]) == dis(a[b[1]], a[b[2]])){
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                cout << b[i] + 1;
                if( i % 4== 3) cout << "\n";
                else cout << " ";
            }
            return 0;
        }
    }
    while(next_permutation(b, b+ n));
    cout << "NO\n";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}