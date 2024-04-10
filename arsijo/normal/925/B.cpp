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

int n;
ll x, y;
vector<pair<int, int> > v;

void solve(bool s){
    for(int i = 0; i + 1 < n; i++){
        ll here = v[i].first;
        ll g = x / here + (x % here ? 1 : 0);
        ll r = i + g - 1;
        if(r >= n - 1){
            continue;
        }
        ll l = r + 1;
        here = v[l].first;
        g = y / here + (y % here ? 1 : 0);
        ll r2 = l + g - 1;
        if(r2 >= n){
            continue;
        }
        vector<int> a, b;
        for(int z = i; z <= r; z++){
            a.push_back(v[z].second);
        }
        for(int z = (int) l; z <= r2; z++){
            b.push_back(v[z].second);
        }
        if(s){
            swap(a, b);
        }
        cout << "Yes" << endl;
        cout << a.size() << " " << b.size() << endl;
        for(int g : a){
            cout << g << " ";
        }
        cout << endl;
        for(int g : b){
            cout << g << " ";
        }
        cout << endl;
        exit(0);
    }
}

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    
#else
    
#endif
    
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    
    solve(false);
    swap(x, y);
    solve(true);
    cout << "No" << endl;
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}