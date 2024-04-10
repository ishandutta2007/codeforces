#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 10;
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
#define mod % MOD
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
#define __DEBUG
#endif
#ifdef __DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 22;

int ar[MAX];

int dp1[1 << MAX];
int dp2[1 << MAX];
int dp3[1 << MAX];

int from[1 << MAX];
int prev[1 << MAX];

inline bool upd(int &a, int b){
    a = min(a, b);
    return a == b;
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
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < (1 << n); i++){
        dp3[i] = 1e9;
        dp2[i] = (1 << n) - 1;
    }
    
    for(int i = 0; i < n; i++){
        ar[i] |= (1 << i);
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ar[a] |= (1 << b);
        ar[b] |= (1 << a);
    }
    
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                dp1[i] |= ar[j];
                dp2[i] &= ar[j];
            }
        }
    }
    
    for(int i = 1; i < (1 << n); i++){
        if((i & dp2[i]) == i){
            dp3[i] = 0;
        }
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                if(upd(dp3[i | ar[j]], dp3[i] + 1)){
                    prev[i | ar[j]] = i;
                    from[i | ar[j]] = j;
                }
            }
        }
    }
    
    cout << dp3[(1 << n) - 1] << endl;
    int pos = (1 << n) - 1;
    vector<int> v;
    while(dp3[pos]){
        v.push_back(from[pos]);
        pos = prev[pos];
    }
    while(!v.empty()){
        cout << v.back() + 1 << " ";
        v.pop_back();
    }
    
}