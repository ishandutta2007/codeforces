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

int n, m;

vector<vector<int> > v;

bool check(int a, int b){
    if(a > b){
        swap(a, b);
    }
    if(a % m != 0 && abs(a - b) == 1){
        return true;
    }
    return (a + m == b);
}

void check(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i && check(v[i - 1][j], v[i][j])){
                return;
            }
            if(j && check(v[i][j - 1], v[i][j])){
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    exit(0);
}

void make(){
    vector<int> v1, v2;
    if(n == 3 && m == 3){
        v[0][0] = 8;
        v[0][1] = 1;
        v[0][2] = 5;
        v[1][0] = 4;
        v[1][1] = 3;
        v[1][2] = 9;
        v[2][0] = 6;
        v[2][1] = 7;
        v[2][2] = 2;
        return;
    }
    if(n >= m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i + j) % 2 == 0){
                    v1.push_back(i * m + j + 1);
                }else{
                    v2.push_back(i * m + j + 1);
                }
            }
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val;
            if(!v1.empty()){
                val = v1.back();
                v1.pop_back();
            }else{
                val = v2.back();
                v2.pop_back();
            }
            v[i][j] = val;
        }
    }
    }else{
        
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
            if((i + j) % 2 == 0){
                v1.push_back(i * m + j + 1);
            }else{
                v2.push_back(i * m + j + 1);
            }
        }
    }
        
            for(int j = 0; j < m; j++){
                for(int i = 0; i < n; i++){
                int val;
                if(!v1.empty()){
                    val = v1.back();
                    v1.pop_back();
                }else{
                    val = v2.back();
                    v2.pop_back();
                }
                v[i][j] = val;
            }
        }
    }
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
    
    cin >> n >> m;
    
    v.resize(n);
    for(int i = 0; i < n; i++){
        v[i].resize(m);
    }
    
    make();
    
    check();
    
    cout << "NO" << endl;
    
}