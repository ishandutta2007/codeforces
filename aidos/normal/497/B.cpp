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

int c[3][100100];
int n;
int get(int x){
    int cur1 = 0, cur2 = 0;
    int s1 = 0, s2 = 0;
    int pos = 1;
    while( pos <= n){
        int pos1 = lower_bound(c[1]+ pos, c[1] + n + 2, c[1][pos-1] + x) - c[1];
        int pos2 = lower_bound(c[2]+ pos, c[2] + n + 2, c[2][pos-1] + x) - c[2];
        if( pos1 == n+1 && pos2 == n+1) return -1;
        if(pos1 < pos2){
            pos = pos1 + 1;
            s1++;
        }
        else {
            pos = pos2+1;
            s2++;
        }
    }
    if(s1 == s2) return -1;
    if(s1 > s2){
        if( c[2][n] - c[2][n-1] > 0 ) return -1;
        return s1;
    }
    if(s1 < s2){
        if( c[1][n] - c[1][n-1] > 0 ) return -1;
        return s2;
    }
    return -1;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d", &n);
    for(int i = 1, x; i<=n; i++){
        scanf("%d", &x);
        c[1][i] = c[1][i-1];
        c[2][i] = c[2][i-1];
        c[x][i]++;
    }
    c[1][n+1] = inf;
    c[2][n+1] = inf;
    vector < pii > v;
    for(int i = 1; i<= n; i++){
        int g = get(i);
        if( g != -1 ) v.pb( mp(g, i));
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        printf("%d %d\n", v[i].f, v[i].s);
    }

    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}