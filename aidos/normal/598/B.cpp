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


char c[100100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    
    string s;
    cin >> s;
    int m, l, r, k;
    cin >> m;

    for(int t = 0; t < m; t++){
        cin >> l >> r >> k;
        l--;
        r--;
        k %= ( r - l + 1);
        for(int i = l ; i <= r; i++){
            int j = i - k;
            if( j < l){
                j = r - (l - j) + 1;
            }
            c[i] = s[j];
        }
        for(int i = l; i <= r; i++)
            s[i] = c[i];
    }
    cout << s << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}