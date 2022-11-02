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

int n;
int c[100100];
ll cur[100100];
int v[100100];
int q;
ll con = -1000000000000000ll;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &q);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
        c[i]--;
    }
    
    while(q--){
        int a, b;
        scanf("%d %d\n", &a, &b);
        ll ans1 = con, ans2 = con, ans = 0;
        int c1=-1, c2 = -1;
        for(int i = 0; i < n; i++){
            cur[i] = con;   
        }
        for(int i = 0; i < n; i++){
            ll anscur = cur[c[i]] + v[i] * 1ll * a;
            anscur = max(anscur, b * 1ll * v[i]);
            if( c[i] != c1 ) {
                anscur = max(anscur, ans1 + b * 1ll * v[i]);
            }
            if(c[i] != c2) {
                anscur = max(anscur, ans2 + b * 1ll * v[i]);
            }
            if(c1 == c[i]){
                ans1 = max(anscur, ans1);
            }
            else if(c2 == c[i]) {
                ans2 = max(anscur, ans2);
            }   
            else if(ans1 < anscur){
                ans2 = ans1;
                c2 = c1;
                ans1 = anscur;
                c1 = c[i];
            }
            else if(ans2 < anscur){
                ans2 = anscur;
                c2 = c[i];
            }
            if(ans1 < ans2){
                swap(ans1, ans2);
                swap(c1, c2);
            }
    //      cout << ans1 << " "<< ans2 << " "<< anscur << endl;
            cur[c[i]] = max(cur[c[i]], anscur);
        }
        for(int i = 0; i < n; i++)
            ans = max(ans, cur[c[i]]);
        ans = max(ans1, ans);
        ans = max(ans2, ans);
        printf("%I64d\n", ans);
    //  return 0;
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}