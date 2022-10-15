#include <bits/stdc++.h>
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
//#define __DEBUG
#endif
#ifdef __DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = (1 << 8);
string ar[MAX];
const int MAX_LEN = 29;
vector<pair<string, int> > e[MAX_LEN], t[MAX_LEN], f[MAX_LEN];

int used[MAX];

void print(int n){
    for(int i =0 ; i <8; i++){
        cout << n % 2;
        n /= 2;
    }
    cout << endl;
}
string anses[1 << 8]={"!x&x",
    "!(x|y|z)",
    "!x&!y&z",
    "!x&!y",
    "!x&!z&y",
    "!x&!z",
    "!(!y&!z|x|y&z)",
    "!(x|y&z)",
    "!x&y&z",
    "!(!y&z|!z&y|x)",
    "!x&z",
    "!(!z&y|x)",
    "!x&y",
    "!(!y&z|x)",
    "!x&(y|z)",
    "!x",
    "!y&!z&x",
    "!y&!z",
    "!(!x&!z|x&z|y)",
    "!(x&z|y)",
    "!(!x&!y|x&y|z)",
    "!(x&y|z)",
    "!(!x&!y|x&y|z)|!x&!y&z",
    "!((x|y)&z|x&y)",
    "!x&y&z|!y&!z&x",
    "!x&y&z|!y&!z",
    "!x&z|!y&!z&x",
    "!x&z|!y&!z",
    "!x&y|!y&!z&x",
    "!x&y|!y&!z",
    "!x&(y|z)|!y&!z&x",
    "!x|!y&!z",
    "!y&x&z",
    "!(!x&z|!z&x|y)",
    "!y&z",
    "!(!z&x|y)",
    "!x&!z&y|!y&x&z",
    "!x&!z|!y&x&z",
    "!x&!z&y|!y&z",
    "!x&!z|!y&z",
    "!x&y&z|!y&x&z",
    "!(!x&z|!z&x|y)|!x&y&z",
    "!(x&y)&z",
    "!(!z&x|y)|!x&z",
    "!x&y|!y&x&z",
    "!(!y&z|x)|!y&x&z",
    "!x&y|!y&z",
    "!x|!y&z",
    "!y&x",
    "!(!x&z|y)",
    "!y&(x|z)",
    "!y",
    "!x&!z&y|!y&x",
    "!x&!z|!y&x",
    "!x&!z&y|!y&(x|z)",
    "!x&!z|!y",
    "!x&y&z|!y&x",
    "!(!x&z|y)|!x&y&z",
    "!x&z|!y&x",
    "!x&z|!y",
    "!x&y|!y&x",
    "!(!x&!y&z|x&y)",
    "!x&(y|z)|!y&x",
    "!x|!y",
    "!z&x&y",
    "!(!x&y|!y&x|z)",
    "!x&!y&z|!z&x&y",
    "!x&!y|!z&x&y",
    "!z&y",
    "!(!y&x|z)",
    "!x&!y&z|!z&y",
    "!x&!y|!z&y",
    "!x&y&z|!z&x&y",
    "!(!x&y|!y&x|z)|!x&y&z",
    "!x&z|!z&x&y",
    "!(!z&y|x)|!z&x&y",
    "!(x&z)&y",
    "!(!y&x|z)|!x&y",
    "!x&z|!z&y",
    "!x|!z&y",
    "!z&x",
    "!(!x&y|z)",
    "!x&!y&z|!z&x",
    "!x&!y|!z&x",
    "!z&(x|y)",
    "!z",
    "!x&!y&z|!z&(x|y)",
    "!x&!y|!z",
    "!x&y&z|!z&x",
    "!(!x&y|z)|!x&y&z",
    "!x&z|!z&x",
    "!(!x&!z&y|x&z)",
    "!x&y|!z&x",
    "!x&y|!z",
    "!x&(y|z)|!z&x",
    "!x|!z",
    "!y&x&z|!z&x&y",
    "!(!x&y|!y&x|z)|!y&x&z",
    "!y&z|!z&x&y",
    "!(!z&x|y)|!z&x&y",
    "!y&x&z|!z&y",
    "!(!y&x|z)|!y&x&z",
    "!y&z|!z&y",
    "!(!y&!z&x|y&z)",
    "!x&y&z|!y&x&z|!z&x&y",
    "!(!x&y|!y&x|z)|!x&y&z|!y&x&z",
    "!(x&y)&z|!z&x&y",
    "!(!z&x|y)|!x&z|!z&x&y",
    "!(x&z)&y|!y&x&z",
    "!(!y&x|z)|!x&y|!y&x&z",
    "!(x&y)&z|!z&y",
    "!x|!y&z|!z&y",
    "!(y&z)&x",
    "!(!x&y|z)|!y&x",
    "!y&z|!z&x",
    "!y|!z&x",
    "!y&x|!z&y",
    "!y&x|!z",
    "!y&(x|z)|!z&y",
    "!y|!z",
    "!(y&z)&x|!x&y&z",
    "!(!x&y|z)|!x&y&z|!y&x",
    "!(x&y)&z|!z&x",
    "!x&z|!y|!z&x",
    "!(x&z)&y|!y&x",
    "!x&y|!y&x|!z",
    "!x&y|!y&z|!z&x",
    "!(x&y&z)",
    "x&y&z",
    "!(x|y|z)|x&y&z",
    "!x&!y&z|x&y&z",
    "!x&!y|x&y&z",
    "!x&!z&y|x&y&z",
    "!x&!z|x&y&z",
    "!(!y&!z|x|y&z)|x&y&z",
    "!(x|y&z)|x&y&z",
    "y&z",
    "!(x|y|z)|y&z",
    "!x&z|y&z",
    "!x&!y|y&z",
    "!x&y|y&z",
    "!x&!z|y&z",
    "!x&(y|z)|y&z",
    "!x|y&z",
    "!y&!z&x|x&y&z",
    "!y&!z|x&y&z",
    "!(!x&!z|x&z|y)|x&y&z",
    "!(x&z|y)|x&y&z",
    "!(!x&!y|x&y|z)|x&y&z",
    "!(x&y|z)|x&y&z",
    "!(!x&!y|x&y|z)|!x&!y&z|x&y&z",
    "!((x|y)&z|x&y)|x&y&z",
    "!y&!z&x|y&z",
    "!y&!z|y&z",
    "!x&z|!y&!z&x|y&z",
    "!(x&z|y)|y&z",
    "!x&y|!y&!z&x|y&z",
    "!(x&y|z)|y&z",
    "!x&(y|z)|!y&!z&x|y&z",
    "!x|!y&!z|y&z",
    "x&z",
    "!(x|y|z)|x&z",
    "!y&z|x&z",
    "!x&!y|x&z",
    "!x&!z&y|x&z",
    "!x&!z|x&z",
    "!x&!z&y|!y&z|x&z",
    "!(x|y&z)|x&z",
    "(x|y)&z",
    "!(x|y|z)|(x|y)&z",
    "z",
    "!x&!y|z",
    "!x&y|x&z",
    "!(!y&z|x)|x&z",
    "!x&y|z",
    "!x|z",
    "!y&x|x&z",
    "!y&!z|x&z",
    "!y&(x|z)|x&z",
    "!y|x&z",
    "!x&!z&y|!y&x|x&z",
    "!(x&y|z)|x&z",
    "!x&!z&y|!y&(x|z)|x&z",
    "!x&!z|!y|x&z",
    "!y&x|y&z",
    "!(!x&z|y)|y&z",
    "!y&x|z",
    "!y|z",
    "!x&y|!y&x|x&z",
    "!x&!z|!y&x|y&z",
    "!x&y|!y&x|z",
    "!x|!y|z",
    "x&y",
    "!(x|y|z)|x&y",
    "!x&!y&z|x&y",
    "!x&!y|x&y",
    "!z&y|x&y",
    "!x&!z|x&y",
    "!x&!y&z|!z&y|x&y",
    "!(x|y&z)|x&y",
    "(x|z)&y",
    "!(x|y|z)|(x|z)&y",
    "!x&z|x&y",
    "!(!z&y|x)|x&y",
    "y",
    "!x&!z|y",
    "!x&z|y",
    "!x|y",
    "!z&x|x&y",
    "!y&!z|x&y",
    "!x&!y&z|!z&x|x&y",
    "!(x&z|y)|x&y",
    "!z&(x|y)|x&y",
    "!z|x&y",
    "!x&!y&z|!z&(x|y)|x&y",
    "!x&!y|!z|x&y",
    "!z&x|y&z",
    "!(!x&y|z)|y&z",
    "!x&z|!z&x|x&y",
    "!x&!y|!z&x|y&z",
    "!z&x|y",
    "!z|y",
    "!x&z|!z&x|y",
    "!x|!z|y",
    "(y|z)&x",
    "!(x|y|z)|(y|z)&x",
    "!y&z|x&y",
    "!(!z&x|y)|x&y",
    "!z&y|x&z",
    "!(!y&x|z)|x&z",
    "!y&z|!z&y|x&y",
    "!x&!y|!z&y|x&z",
    "(x|y)&z|x&y",
    "!(x|y|z)|(x|y)&z|x&y",
    "x&y|z",
    "!x&!y|x&y|z",
    "x&z|y",
    "!x&!z|x&z|y",
    "y|z",
    "!x|y|z",
    "x",
    "!y&!z|x",
    "!y&z|x",
    "!y|x",
    "!z&y|x",
    "!z|x",
    "!y&z|!z&y|x",
    "!y|!z|x",
    "x|y&z",
    "!y&!z|x|y&z",
    "x|z",
    "!y|x|z",
    "x|y",
    "!z|x|y",
    "x|y|z",
    "!x|x"};

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
    if(0){
    if(0){
        string s;
        cout << "string anses[1 << 8]={";
        while(cin >> s){
            cout << '"' << s << '"' << "," << endl;
        }
        cout << "}" << endl;
        return 0;
    }
    
    int x = 0, y = 0, z = 0;
    for(int i = 0; i < 8; i++){
        if((i / 4)){
            x |= (1 << i);
        }
        if((i / 2) % 2){
            y |= (1 << i);
        }
        if(i % 2){
            z |= (1 << i);
        }
    }
    for(int i = 0; i < 8; i++){
        if((i / 4)){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    cout << endl;
    for(int i = 0; i < 8; i++){
        if((i / 2) % 2){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    cout << endl;
    for(int i = 0; i < 8; i++){
        if(i % 2){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    cout << endl;
    
    f[1].push_back(make_pair("x", x));
    f[1].push_back(make_pair("y", y));
    f[1].push_back(make_pair("z", z));
    const int T = 14;
    for(int i = 1; i < MAX_LEN; i++){
        for(auto tt : f[i]){
            string s = tt.first;
            int ind = tt.second;
            if(ar[ind] == "" || (ar[ind].size() == s.size() && s < ar[ind])){
                ar[ind] = s;
            }
            if(ar[ind].size() + 2 < s.size()){
                continue;
            }
            if(i + 1 < MAX_LEN){
                f[i + 1].push_back(make_pair("!" + s, (MAX - 1) ^ ind));
            }
            t[i].push_back(tt);
        }
        for(auto tt : t[i]){
            string s = tt.first;
            int ind = tt.second;
            
            if(ar[ind] == "" || (ar[ind].size() == s.size() && s < ar[ind])){
                ar[ind] = s;
            }
            if(ar[ind].size() + 2 < s.size()){
                continue;
            }
            for(int j = 1; j <= i && i + j + 1 < MAX_LEN; j++){
                for(auto v : f[j]){
                    if(ar[ind & v.second].size() == 0 || ar[ind & v.second].size() + 2 < i + j + 1){
                        if(s < v.first)
                    t[i + j + 1].push_back(make_pair(s + "&" + v.first, ind & v.second));
                        else
                            
                            t[i + j + 1].push_back(make_pair(v.first + "&" + s, ind & v.second));
                    }
                }
            }
            e[i].push_back(tt);
        }
        for(auto tt : e[i]){
            string s = tt.first;
            int ind = tt.second;
            if(ar[ind] == "" || (ar[ind].size() == s.size() && s <= ar[ind])){
                ar[ind] = s;
            }
            if(ar[ind].size() + 2 < s.size()){
                continue;
            }
            assert((int) s.size() == i);
            for(int j = 1; j <= i && i + j + 1 < MAX_LEN; j++){
                for(auto v : t[j]){
                    if(ar[ind | v.second].size() == 0 || ar[ind | v.second].size() + 2 < i + j + 1){
                        if(s < v.first)
                    e[i + j + 1].push_back(make_pair(s + "|" + v.first, ind | v.second));
                        else
                            
                            e[i + j + 1].push_back(make_pair(v.first + "|" + s, ind | v.second));
                        
                    }
                }
            }
            if(i + 2 < MAX_LEN){
                f[i + 2].push_back(make_pair("(" + s + ")", ind));
            }
        }
        bool ok = true;
        int u = 0;
        for(int i = 0; i < MAX; i++){
            if(ar[i] == ""){
                ok = false;
            }else{
                u++;
            }
        }
        cout << "in " << i << " " << ((ld) u / ((ld) (1 << 8))) * 100 << endl;
        if(ok){
            cout << "break in " << i << endl;
            break;
        }
    }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < 8; i++){
            if(s[i] == '1'){
                ans |= (1 << i);
            }
        }
        cout << anses[ans] << endl;
    }
    if(0){
    ofstream cout("output2.txt");
    cout << "string anses[1 << 8]={";
    for(int i = 0; i < MAX; i++){
        if(i + 1 < MAX){
            cout << '"' << ar[i] << '"' << "," << endl;
        }else{
            cout << '"' << ar[i] << '"' << "};" << endl;
        }
    }
    cout.close();
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}