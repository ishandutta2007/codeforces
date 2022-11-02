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


int a[maxn];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
        cnt += a[i];
    }
    if(a[n-1] || cnt == n-2 && !a[n-2]){
        cout << "NO\n";
        return 0;
    }
        
    cout << "YES\n";
    int p = 0;
    while(a[p]) p++;
    for(int i = 0; i <= p; i++){
        if(i) cout << "->";
        cout << a[i];
    }
    if(p + 1 < n) cout << "->(";
    for(int i = p + 1; i + 1< n; i++){
        if( i>p+1) cout << "->";
        cout << a[i];
    }
    if(p+1 < n) cout << ")->"<< a[n-1];
    
    





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}