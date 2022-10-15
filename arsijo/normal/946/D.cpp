#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
    return (t * t);
}
inline void read(ll &n) {
    n = 0;
    _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
}
inline bool read(int &n) {
    n = 0;
    _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n') {
            if (ccc == '\n')
                return true;
            break;
        }
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
    return false;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
    long long x = y;
    kkkk = 0;
    if (x < 0) {
        putchar('-');
        x *= -1;
    }
    if (!x){
        ++kkkk; wwww[kkkk] = '0';
    }else
        while (x) {
            ++kkkk;
            wwww[kkkk] = char(x % 10 + '0');
            x /= 10;
        }
    for (int i = kkkk; i >= 1; --i)
        putchar(wwww[i]);
}
#ifdef LOCAL
//#define __DEBUG
#endif
#ifdef __DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n, m, k;

const int MAX = 510;

string ar[MAX];

int dp1[MAX][MAX];

int dp2[MAX][MAX];

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    input;
    output;
#else
    
#endif
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            dp1[i][j] = dp2[i][j] = 1e9;
        }
    }
    
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        int has = 0;
        for(int j = 0; j < m; j++){
            has += (ar[i][j] == '1');
        }
        for(int a = 0; a < m; a++){
            int used = 0;
            for(int b = a; b < m; b++){
                used += (ar[i][b] == '1');
                dp1[i][has - used] = min(dp1[i][has - used], b - a + 1);
            }
        }
        dp1[i][has] = 0;
    }
    
    dp2[0][0] = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(dp2[i][j] < 1e9){
                for(int z = 0; j + z <= k; z++){
                    dp2[i + 1][j + z] = min(dp2[i + 1][j + z], dp2[i][j] + dp1[i + 1][z]);
                }
            }
        }
    }
    
    int ans = 1e9;
    for(int i = 0; i <= k; i++){
        ans = min(ans, dp2[n][i]);
    }
    
    cout << ans << endl;
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}