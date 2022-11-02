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


char c[10100];
char d[1000100];
int n, m;
int nxt[10100][26];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s %s\n", c, d);
    n = strlen(c);
    m = strlen(d);
    for(int i = 0; i < 26; ++i)
        nxt[n][i] = -1;
    for(int i = n-1; i >= 0; i--){
        nxt[n][c[i] - 'a'] = i;
    }
    for(int i = n-1; i >= 0; --i){
        for(int j = 0; j < 26; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][c[i] - 'a'] = i;
    }
    int cnt = 1;
    int st = 0;
    for(int i = 0; i < m; i++){
        int val = nxt[st][d[i] - 'a'];
        if( val == -1){
            cout << -1 << endl;
            return 0;
        }
        if(val < st) cnt++;
        st = val + 1;
    }
    cout << cnt << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}