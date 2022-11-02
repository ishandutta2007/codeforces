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


int n, t;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> t;
    if( n == 1){
        if( t == 10) cout << -1 << endl;
        else cout << t << endl;
        return 0;
    }
    int col = n - 1;
    if( t == 10 ) col--;
    cout <<t;
    for(int i = 0; i < col; i++)
        cout << '0';
    cout << endl;


    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}