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

const int MAX = 1e5 + 10;

int n, m;
char a[MAX], b[MAX];

int last_b_1[MAX], last_b_2[MAX], how_many_b_1[MAX], how_many_b_2[MAX];

int solve(int l1, int r1, int l2, int r2){
    int b1 = how_many_b_1[r1] - how_many_b_1[l1 - 1];
    int b2 = how_many_b_2[r2] - how_many_b_2[l2 - 1];
    int sz1 = r1 - l1 + 1;
    int sz2 = r2 - l2 + 1;
    if(b1 > b2){
        return false;
    }
    if((b2 - b1) % 2 == 1){
        return false;
    }
    if(b1 == 0 && b2 == 0){// if we have only A's
        return (sz1 >= sz2 && (sz1 - sz2) % 3 == 0);
    }
    int a2 = r2 - last_b_2[r2]; // how many a's are in the suffix
    if(b1 == 0){// if first string does not contain B's
        return (sz1 > a2);
    }
    int a1 = r1 - last_b_1[r1];
    if(a1 < a2){
        return false;
    }
    if(a1 > a2){
        if(b1 == b2){
            if((a1 - a2) % 3 != 0){
                return false;
            }
        }
    }
    return true;
}

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
    
    string s;
    cin >> s;
    n = (int) s.size();
    for(int i = 0; i < n; i++){
        a[i + 1] = s[i];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 'C'){
            a[i] = 'B';
        }
        last_b_1[i] = (a[i] == 'B' ? i : last_b_1[i - 1]);
        how_many_b_1[i] = how_many_b_1[i - 1] + (a[i] == 'B' ? 1 : 0);
    }
    cin >> s;
    m = (int) s.size();
    for(int i = 0; i < m; i++){
        b[i + 1] = s[i];
    }
    for(int i = 1; i <= m; i++){
        if(b[i] == 'C'){
            b[i] = 'B';
        }
        last_b_2[i] = (b[i] == 'B' ? i : last_b_2[i - 1]);
        how_many_b_2[i] = how_many_b_2[i - 1] + (b[i] == 'B' ? 1 : 0);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d);
    }
    cout << endl;
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}