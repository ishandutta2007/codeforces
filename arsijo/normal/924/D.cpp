#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-6;
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


const int MaxN = 1e5 + 15;
const long long INF = 1e9 * 1ll * 1e9;

struct num{
    ll first, second;
    bool operator<(const num b) const{
        return (first * b.second < second * b.first);
    }
    bool operator==(num b){
        return (first * b.second == second * b.first);
    }
    num(){
        first = second = 0;
    }
    num(ll a, ll b){
        first = a;
        second = b;
    }
};

pair<num, num> a[MaxN];

int t[MaxN];

void add(int pos, int val){
    for(int i = pos; i < MaxN; i |= (i + 1)){
        t[i] += val;
    }
}

int sum(int pos){
    int ans = 0;
    for(int i = pos; i >= 0; i &= (i + 1), i--){
        ans += t[i];
    }
    return ans;
}

num ar[MaxN];

int n;
ll maxW;

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
    
    cin >> n >> maxW;
    
    for(int i = 1; i <= n; ++i)
    {
        ll v, x;
        cin >> x >> v;
        
        ll t1 = abs(v - maxW);
        ll t2 = abs(v + maxW);
        x = abs(x);
        a[i] = make_pair(num(x, t1), num(x, t2));
    }
    
    sort(a + 1, a + n + 1);
    ar[0] = num(-1, 1);
    vector<pair<num, num> > v;
    for(int i = 1; i <= n; i++){
        ar[i] = a[i].first;
        v.push_back(make_pair(a[i].second, a[i].first));
    }
    
    sort(v.begin(), v.end());
    ll all = n * 1LL * (n - 1) / 2;
    
    for(int i = 0; i < n; ){
        vector<pair<num, num> > g;
        num now = v[i].first;
        while(i < n && (v[i].first == now)){
            g.push_back(v[i]);
            i++;
        }
        for(auto a : g){
            int l = 0, r = n;
            while(l < r){
                int x = (l + r + 1) >> 1;
                if(ar[x] < a.second){
                    l = x;
                }else{
                    r = x - 1;
                }
            }
            all -= sum(l);
        }
        for(auto a : g){
            int l = 0, r = n;
            while(l < r){
                int x = (l + r + 1) >> 1;
                if(ar[x] < a.second){
                    l = x + 1;
                }else if(ar[x] == a.second){
                    l = r = x;
                    break;
                }else{
                    r = x - 1;
                }
            }
            add(l, +1);
        }
        
    }
    
    cout << all << '\n';
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}