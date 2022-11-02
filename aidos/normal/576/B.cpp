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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int a[100100];
int n;
int p[1001000];
bool used[100100];

vector < int > g[100100];
vector < pii > ans;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; i++){
        if( i == a[i]){
            cout << "YES\n";
            for(int j = 1; j <= n; j++){
                if( i != j) printf("%d %d\n", i, j);
            }
            return 0;
        }
    }
    for(int i = 1; i <= n; i++){
        if(used[i]) continue;
        int j = i;
        vector < int > v;
        while(!used[j] ){
            used[j] = 1;
            v.pb(j);
            j = a[j];
        }
        int cur = v.size();
        if(g[cur].size() == 0){
            g[cur] = v;
        }
        else {
            for(int k = 0; k < cur; k++){
                ans.pb( mp(v[k], g[cur][k]));
            }
        }
    }

    if( g[2].size() == 0){
        cout << "NO\n";
        return 0;
    }
    for(int i = 3; i <= n; i+=2){
        if(g[i].size() != 0){
            cout << "NO\n";
            return 0;
        }
    }

    for(int i = 4; i <= n; i+=2){
        for(int j = 0; j < g[i].size(); j++){
            ans.pb( mp(g[2][j % 2], g[i][j]) );
        }
    }
    ans.pb( mp(g[2][0], g[2][1]));
    cout << "YES\n";
    forit(it, ans){
        printf("%d %d\n", it->f, it->s);
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}