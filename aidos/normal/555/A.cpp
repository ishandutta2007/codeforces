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
const int maxn = (int) 1e5 + 10;

using namespace std;

set  <pii > S;
vector < int > g[100100];
int n;
int k;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for(int i = 0, t, x; i < k; i++){
        scanf("%d", &t);
        for(int j = 0; j < t; j++){
            scanf("%d", &x);
            g[i].pb(x);
        }
    }
    
    for(int i = 0; i < k; i++){
        S.insert(mp(-g[i].back(), i));
    }
    int cnt = 0;
    while(S.size() > 0){
        pii fi = *S.begin();
        S.erase(S.begin());
        if(S.size() == 0) break;
        cnt++;
        g[fi.s].pop_back();
        if(g[fi.s].size() > 0) {
            cnt++;
            S.insert(mp(-g[fi.s].back(), fi.s));
        }
    }
    printf("%d\n", cnt);



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}