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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
int a[1010][1010];
int x[1010];
int y[1010];
int n, m, k, p;
ll d1[1000100];
ll d2[1000100];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            x[i] += a[i][j];
            y[j] += a[i][j];
        }
    }
    set < pll > S1, S2;
    for(int i =  0 ; i < m; i++){
        S1.insert( mp( -y[i], i ) );
    }
    for(int i =  0 ; i < n; i++){
        S2.insert( mp( -x[i], i ) );
    }
    for(int i = 1; i <= k; i++){
        d1[i] = d1[i-1];
        pll x = *S1.begin();
        d1[i] += -x.f;
        x.f += n * p;
        S1.erase(S1.begin());
        S1.insert(x);

        d2[i] = d2[i-1];
        x = *S2.begin();
        d2[i] -= x.f;
        x.f += m * p;
        S2.erase(S2.begin());
        S2.insert(x);
    }
    ll ans = -inf * 1ll * inf;

    for(int i = 0; i <= k; i++){
        ans = max(ans, d1[i] + d2[k-i] - 1ll * i * (k - i) * p);
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}