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

int is_p(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0) return 1;
    }
    return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector < int > v;
    for(int i = 2; i <= n; i++){
        if( !is_p(i)){
            int j = i;
            while( j <= n){
                v.pb( j );
                j *= i;
            }
        }
    }
    cout << v.size() << endl;
    forit(it, v){
        cout << *it<< " ";
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}