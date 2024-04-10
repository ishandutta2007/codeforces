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

const int MAX = 2e5 + 10;

ll ans[MAX];

vector<int> vec[MAX];

char ch[MAX];

int down[MAX];

bool used[MAX];

void dfs(int pos, int prev = -1) {
    down[pos] = 1;
    for (int a : vec[pos]) {
        if (a != prev && !used[a]) {
            dfs(a, pos);
            down[pos] += down[a];
        }
    }
}

int timer;

ll m[1 << 20];
int ind[1 << 20];

inline int get(int v){
    if(ind[v] != timer){
        ind[v] = timer;
        m[v] = 0;
    }
    return m[v];
}

inline void add(int v, ll val){
    if(ind[v] != timer){
        ind[v] = timer;
        m[v] = 0;
    }
    m[v] += val;
}

ll dfs1(int pos, int now, int prev = 0){
    now ^= (1 << ((int) ch[pos] - 'a'));
    ll res = get(now);
    for(int i = 0; i < 20; i++){
        res += get(now ^ (1 << i));
    }
    for(int a : vec[pos]){
        if(a != prev && !used[a]){
            res += dfs1(a, now, pos);
        }
    }
    ans[pos] += res;
    return res;
}

void dfs2(int pos, int now, int prev = 0){
    now ^= (1 << ((int) ch[pos] - 'a'));
    m[now]++;
    for(int a : vec[pos]){
        if(a != prev && !used[a]){
            dfs2(a, now, pos);
        }
    }
}

void culc(int pos){
    timer++;
    int y = (1 << ((int) ch[pos] - 'a'));
    add(y, 1);
    ans[pos]++;
    for(int a : vec[pos]){
        if(!used[a]){
            ans[pos] += dfs1(a, 0, pos);
            dfs2(a, y, pos);
        }
    }
    timer++;
    reverse(vec[pos].begin(), vec[pos].end());
    for(int a : vec[pos]){
        if(!used[a]){
            dfs1(a, 0, pos);
            dfs2(a, y, pos);
        }
    }
}

void build(int pos) {
    dfs(pos);
    int sz = down[pos];
    int prev = -1;
    int to = pos;
    while (to != -1){
        pos = to;
        to = -1;
        for (int v : vec[pos]) {
            if (!used[v] && v != prev && down[v] > (sz >> 1)) {
                to = v;
            }
        }
        prev = pos;
    }
    used[pos] = true;
    culc(pos);
    for(int a : vec[pos]){
        if(!used[a]){
            build(a);
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
    
    
    timer = 0;
    
    int n;
    cin >> n;
    
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    string t;
    cin >> t;
    for(int i = 0; i < n; i++){
        ch[i + 1] = t[i];
    }
    
    build(1);
    
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}