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
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
set < pll > S1, S2, S3;
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int k,n1,n2,n3,t1,t2,t3;
    ll cur = 0;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2>> t3;
    for(int i = 0; i < k; i++){
        ll ti = 0;
        while( S1.size() == n1){
            ti = S1.begin()->f;
            S1.erase(S1.begin());
        }
        ti+=t1;
        while( S2.size() == n2){
            ti = max(S2.begin()->f, ti);
            S2.erase(S2.begin());
        }
        ti+=t2;
        while( S3.size() == n3){
            ti = max(S3.begin()->f, ti);
            S3.erase(S3.begin());
        }
        ti+=t3;
        cur = max(cur, ti);
        S1.insert(mp(ti-t3-t2, i));
        S2.insert(mp(ti-t3, i));
        S3.insert(mp(ti, i));
    }
    cout << cur << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}