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

bool ok[26];

bool check[26];

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
    
    int n;
    cin >> n;
    
    for(int i = 0; i < 26; i++){
        ok[i] = true;
    }
    
    int finish = n;
    
    bool found = false;
    
    vector<pair<char, string> > v;
    
    char answer;
    
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == '!'){
            string s;
            cin >> s;
            v.push_back(make_pair(c, s));
            for(int i = 0; i < 26; i++){
                check[i] = false;
            }
            for(char c : s){
                check[c - 'a'] = true;
            }
            for(int i = 0; i < 26; i++){
                if(!check[i]){
                    ok[i] = false;
                }
            }
        }else if(c == '.'){
            string s;
            cin >> s;
            
            v.push_back(make_pair(c, s));
            for(char c : s){
                ok[c - 'a'] = false;
            }
        }else{
            char c;
            cin >> c;
            if(i + 1 == n){
                answer = c;
            }else{
                ok[c - 'a'] = false;
                v.push_back(make_pair('?', string(1, c)));
            }
        }
        if(!found){
            int a = 0;
            for(int i = 0; i < 26; i++){
                if(ok[i]){
                    a++;
                }
            }
            if(a == 1){
                finish = i;
                found = true;
            }
        }
    }
    
    int ans = 0;
    for(int i = finish + 1; i < (int) v.size(); i++){
        if(v[i].first == '!'){
            ans++;
        }else if(v[i].first == '?'){
            ans++;
        }
    }
    
    cout << ans << endl;
    
}