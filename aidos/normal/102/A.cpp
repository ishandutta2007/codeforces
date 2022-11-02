#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;


bool u[111][111];
int a[111];
int mx = -1;
int n;
int m;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0, x, y; i < m; i++){
        scanf("%d %d", &x, &y);
        u[x-1][y-1] = 1;
        u[y-1][x-1] = 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            if(u[i][j]){
                for(int k = j + 1; k < n; k++){
                    if(u[k][j] && u[i][k]){
                        int sum = a[i] + a[j] + a[k];
                        if(mx == -1 || sum < mx) mx = sum;
                    }
                }
            }
        }
    cout << mx << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}