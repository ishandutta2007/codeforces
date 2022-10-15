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

string get(vector<int> h, string s){
    for(int i = s[0] - 1; i >= '0'; i--){
        h[i - '0'] ^= 1;
        
        int has = (int) s.size() - 1;
        for(int j : h){
            has -= j;
        }
        if(has >= 0){
            for(int j = 1; j < (int) s.size(); j++){
                if(has){
                    s[j] = '9';
                    has--;
                }else{
                    for(int z = 9; z >= 0; z--){
                        if(h[z]){
                            s[j] = '0' + z;
                            h[z] = 0;
                            break;
                        }
                    }
                }
            }
            s[0] = i;
            return s;
        }
        h[i - '0'] ^= 1;
    }
    return "";
}

void solve(string s){
    vector<int> has(10);
    for(char c : s){
        has[c - '0'] ^= 1;
    }
    string t = "";
    for(int i = 0; i < (int) s.size(); i++){
        t = s[s.size() - 1 - i] + t;
        int ind = s[(int) s.size() - 1 - i] - '0';
        has[ind] ^= 1;
        int problems = 0;
        for(int j = 0; j < 10; j++){
            problems += has[j];
        }
        if(problems <= i + 1){
            string m = get(has, t);
            if(m.size() > 0){
                for(int j = 0; j <= i; j++){
                    s[s.size() - 1 - j] = m[m.size() - 1 - j];
                }
                if(i + 1 == s.size() && s[0] == '0')
                    break;
                cout << s << endl;
                return;
            }
        }
    }
    for(int i = 2; i < (int) s.size(); i++){
        cout << "9";
    }
    cout << endl;
}

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
#else
    
#endif
    
    int t;
    cin >> t;
    
    
    string s;
    while(t--){
        cin >> s;
        solve(s);
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}