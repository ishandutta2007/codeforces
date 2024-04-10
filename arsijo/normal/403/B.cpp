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

vector<int> primes;

bool prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

const int MAX = 5e3 + 10;

int ar[MAX];

vector<int> bad;

int gcd(int a, int b){
    while(a && b){
        if(a >= b){
            a %= b;
        }else{
            b %= a;
        }
    }
    return a + b;
}

int culc(int val){
    int ans = 0;
    for(int a : bad){
        while(val % a == 0){
            val /= a;
            ans--;
        }
    }
    for(int a : primes){
        while(val % a == 0){
            ans++;
            val /= a;
        }
    }
    if(val > 1){
        ans++;
    }
    return ans;
}

int n, m;

int g[MAX];

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
#else
    
#endif
    
    for(int i = 2; i * i <= (int) 1e9; i++){
        if(prime(i)){
            primes.push_back(i);
        }
    }
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    
    while(m--){
        int a;
        cin >> a;
        bad.push_back(a);
    }
    
    g[1] = ar[1];
    for(int i = 2; i <= n; i++){
        g[i] = gcd(g[i - 1], ar[i]);
    }
    
    for(int i = n; i; i--){
        if(g[i] != g[i + 1]){
            int res = culc(g[i]);
            if(res < 0){
                for(int j = 1; j <= i; j++){
                    ar[j] /= g[i];
                    g[j] /= g[i];
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += culc(ar[i]);
    }
    
    cout << ans << endl;
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}