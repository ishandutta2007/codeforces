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

int a[200100];
int b[200100];
int c[500100];
int n, m;
int k;
void get(int x, int &c1, int &c2, int &c3){
    int col = upper_bound(a, a + n, x) - a;
    int col2 = upper_bound(b, b + m, x) - b;
    int ans2 = 2 * col + (n - col) * 3;
    int ans3 = 2 * col2 + (m - col2) * 3;
    int ans1 = ans2 - ans3;
    if( ans1 < c1) return;
    if( ans1 > c1 || c2<ans2){
        c1 = ans1;
        c2 = ans2;
        c3 = ans3;
        
    }
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i];
    }
    cin >> m;
    for(int j = 0; j < m; j++){
        cin >> b[j];
        c[j + n] = b[j];
    }
    sort(a, a + n);
    sort( b, b + m);
    sort(c, c + n + m) ;
    k = unique(c, c + n + m) - c;
    int ans1 = 2*(n-m);
    int ans2 = 2 * n;
    int ans3 = 2 * m;
    
    for(int i = 0; i < k; i++){
        get(c[i], ans1, ans2, ans3);
    }
    get(0, ans1, ans2, ans3);
    cout << ans2 << ":" << ans3 << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}