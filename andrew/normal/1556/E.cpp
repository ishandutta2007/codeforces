#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5 + 10;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct node{
    ll max, min;
};

ll c[N], pref[N];
node t[4 * N];

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v].min = t[v].max = pref[tl];
    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v].min = min(t[v << 1].min, t[v << 1 | 1].min);
        t[v].max = max(t[v << 1].max, t[v << 1 | 1].max);
    }
}

node T;
bool f = 0;

void get(int v, int tl, int tr, int l, int r){
    if(l > r)return;
    if(tl == l && tr == r){
        if(!f){
            T = t[v];
            f = 1;
        }else{
            T.min = min(T.min, t[v].min);
            T.max = max(T.max, t[v].max);
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    get(v << 1, tl, tm, l, min(r, tm));
    get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector <ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        c[i] = b[i] - a[i];
        pref[i] = pref[i - 1] + c[i];
    }

    build(1, 1, n);


    while(q--){
        int l, r;
        cin >> l >> r;
        f = 0;
        get(1, 1, n, l, r);
        if(pref[r] - pref[l - 1] != 0 || T.min - pref[l - 1] < 0){
            cout << "-1\n";
        }else{
            cout << T.max - pref[l - 1] << "\n";
        }
    }
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    //cin >> t;
    t = 1;

    while(t--){
        solve();
    }

    return 0;
}