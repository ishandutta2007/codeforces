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

int n;

const int MAX = 1e3 + 10;

string names[MAX];

struct pack{
    int name;
    int version;
    int dist;
    int pos;
    pack(int n, int v, int d, int p){
        name = n;
        version = v;
        dist = d;
        pos = p;
    }
};

bool operator<(pack a, pack b){
    if(a.dist != b.dist){
        return a.dist < b.dist;
    }
    if(a.version != b.version){
        return a.version > b.version;
    }
    return a.name < b.name;
}

set<pack> s;

vector<pair<ii, int> > vec[MAX];

map<string, int> m;

int used[MAX];

bool added[MAX];

bool empty_string(string &s){
    for(char c : s){
        if('a' <= c && c <= 'z'){
            return false;
        }
    }
    return true;
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

    int n;
    cin >> n;
    
    int sz = 0;
    
    map<ii, int> inds;
    
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(empty_string(s)){
            cin >> s;
        }
        if(m[s] == 0){
            m[s] = ++sz;
            names[sz] = s;
        }
        int ver;
        cin >> ver;
        inds[make_pair(m[s], ver)] = i;
        if(i == 1){
            added[1] = true;
            ::s.insert(pack(m[s], ver, 0, 1));
        }
        int q;
        cin >> q;
        while(q--){
            string a;
            int v;
            cin >> a >> v;
            if(m[a] == 0){
                m[a] = ++sz;
                names[sz] = a;
            }
            vec[i].push_back(make_pair(make_pair(m[a], v), 0));
        }
    }
    
    
    vector<pair<string, int> > v;
    
    while(!s.empty()){
        pack p = *s.begin();
        s.erase(s.begin());
        if(used[p.name])
            continue;
        used[p.name] = true;
        //cout << "$ " << p.name << " " << p.version << " " << p.version << " " << vec[p.pos].size() << endl;
        if(p.dist != 0){
            v.push_back(make_pair(names[p.name], p.version));
        }
        for(auto a : vec[p.pos]){
            int name = a.first.first;
            int v = a.first.second;
            int ind = inds[make_pair(name, v)];
          //  cout << "# " << ind << " " << added[ind] << endl;
            if(!added[ind]){
                added[ind] = true;
              //  cout << "+" << endl;
                s.insert(pack(name, v, p.dist + 1, ind));
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << v.size() << endl;
    for(auto a : v){
        cout << a.first << " " << a.second << endl;
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}