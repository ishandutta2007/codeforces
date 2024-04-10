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


int p[N], res[N];
vector <pii> v[N], v1[N];
 
struct node{
    pii val, val1;
    node *l, *r;
    node(){
        l = r = nullptr;
        val = val1 = {0, 0};
    }
};
 
void push(node *v){
    if(v -> l != nullptr){
        (v -> l) -> val = max((v -> l) -> val, v -> val1);
        (v -> l) -> val1 = max((v -> l) -> val1, v -> val1);
    }
    if(v -> r != nullptr){
        (v -> r) -> val = max((v -> r) -> val, v -> val1);
        (v -> r) -> val1 = max((v -> r) -> val1, v -> val1);
    }
}
 
void modify(node *v, int tl, int tr, int l, int r, pii val){
    if(l > r)return;
    if(tl == l && tr == r){
        v -> val = max(v -> val, val);
        v -> val1 = max(v -> val1, val);
        return;
    }
    int tm = (tl + tr) >> 1;
    if(v -> l == nullptr){
        v -> l = new node();
    }
    if(v -> r == nullptr){
        v -> r = new node();
    }
    push(v);
    modify(v -> l, tl, tm, l, min(r, tm), val);
    modify(v -> r, tm + 1, tr, max(l, tm + 1), r, val);
    v -> val = max((v -> l) -> val, (v -> r) -> val);
}
 
pair <int, int> get(node *v, int tl, int tr, int l, int r){
    if(l > r || v == nullptr){
        return {0, 0};
    }
    if(tl == l && tr == r){
        return v -> val;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    pii res = v -> val1;
    return max(res, max(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r)));
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    
    vector <int> ss;

    for(int i = 1; i <= m; i++){
        int x, l, r;
        cin >> x >> l >> r;
        v1[x].p_b({l, r});
        ss.p_b(l);
        ss.p_b(r);
    }

    sort(all(ss));
    //ss.erase(unique(all(ss), ss.end()));

    for(int i = 1; i <= n; i++){
        for(auto j : v1[i]){
            v[i].p_b(m_p(lower_bound(all(ss), j.fi) - ss.begin() + 1, lower_bound(all(ss), j.se) - ss.begin() + 1));
        }
        v1[i].clear();
    }
 
    int ans = 0;
 
    node *root = new node();
    const int R = 6e5;
 
    for(int i = 1; i <= n; i++){
        int x = 0;
        for(auto j : v[i]){
            pii f = get(root, 1, R, j.fi, j.se);
            if(f.fi > x){
                x = f.fi;
                p[i] = f.se;
            }
        }   
        res[i] = x + 1;
        if(res[i] > res[ans]){
            ans = i;
        }
        for(auto j : v[i]){
            modify(root, 1, R, j.fi, j.se, m_p(res[i], i));
        }
    }
 
    cout << n - res[ans] << "\n";
 
    set <int> st;
 
    for(int i = 1; i <= n; i++){
        st.insert(i);
    }
 
    int x = ans;
    while(x){
        st.erase(x);
        x =  p[x];
    }
 
    for(auto i : st){
        cout << i << " ";
    }
    cout << "\n";
 
    return 0;
}