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
ll k;
ll a[55];
int b[55];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    int len = -1;
    for(int i = 0; i <= n; i++){
        if(a[i] >= k){
            len = i;
            break;
        }
    }
    int x = n - len + 1;
    for(int i = 1; i <= n - len; i++){
        printf("%d ", i);
    }

    for(int i = 0; i < len; ){
        
        if(a[len -i-1] >= k) {
            cout << i + x << " ";
            i++;
        }
        else {
            k -= a[len-i-1];
            cout << i + x + 1 << " " << i + x << " " ;
            i+=2;
        }
    }

        


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}