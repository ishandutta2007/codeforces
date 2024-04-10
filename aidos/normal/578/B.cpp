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

int n, a[200200];
ll sum[200200];
int k, x;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];              
    }

    ll maxi = 0;

    ll d = 1;
    for(int i = 0; i < k; i++)
        d = d * x;
    
    for(int i = n-1; i >= 0; i--){
        sum[i] = (sum[i + 1] | a[i]);
    }
    ll prev = 0;

    for(int i = 0; i < n; i++){
        maxi = max(maxi, ((prev | sum[i+1]) | (d*a[i]) ));
        prev |= a[i];
    }
    cout << maxi << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}