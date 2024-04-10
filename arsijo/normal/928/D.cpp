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
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
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

const int MAX = 3e5 + 10;

int t[MAX][26];
bool finish[MAX];
int used[MAX];

int timer;

int add(string s){
    int now = 1;
    int extra = 0;
    bool already_created_new = false;
    int ans = (int) s.size();
    for(char c : s){
        if(t[now][c - 'a']){
            now = t[now][c - 'a'];
            if(used[now] == 1){
                extra++;
            }
        }else{
            if(!already_created_new){
                if(finish[now] && extra > 2){
                    ans -= extra - 2;
                }
            }
            already_created_new = true;
            now = (t[now][c - 'a'] = ++timer);
        }
    }
    if(finish[now]){
        ans -= max(0, extra - 2);
    }else{
        int now = 1;
        for(char c : s){
            now = t[now][c - 'a'];
            used[now]++;
        }
        finish[now] = true;
    }
    return ans;
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
    
    timer = 1;

    int ans = 0;
    
    string s;
    while(getline(cin, s)){
        for(int i = 0; i < (int) s.size(); i++){
            if('a' <= s[i] && s[i] <= 'z'){
                string t;
                t += s[i];
                while(i + 1 < (int) s.size() && 'a' <= s[i + 1] && s[i + 1] <= 'z'){
                    t += s[++i];
                }
                int a = add(t);
                ans += a;
            }else{
                ans++;
            }
        }
        ans++;
    }
    
    cout << ans << endl;
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}