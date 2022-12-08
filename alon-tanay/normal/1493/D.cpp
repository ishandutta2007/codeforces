#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

const int mx = 200005;

int n;

ll pw(ll b, ll e) {
    if(e == 0) { return 1LL; }
    if(e&1) {
        return (b*pw((b*b)%MODL,e/2))%MODL;
    }
    return pw((b*b)%MODL,e/2);
}

int MN(multiset<int> &m) {
    if(m.size() == n) {
        return *m.begin();
    }
    return 0;
}

ll res = 1;
multiset<int> ps[mx];
map<int,int> ds[mx];
ll sieve[mx];
void update(int i, int x) {
    int y = x;
    while(y > 1) {
        int p = sieve[y];
        int c = 0;
        while((y%p)==0) {
            y /= p;
            c ++;
        }
        auto it = ds[i].find(p);
        if(it != ds[i].end()) {
            int lst = it->second;
            int lp = MN(ps[p]);
            // if(p == 2) { cout << "lp: " << lp << endl; }
            ps[p].erase(ps[p].find(lst));
            ps[p].insert(lst+c);
            int np = MN(ps[p]);
            // if(p == 2) { cout << "np: " << np << endl; }
            res *= pw(p,np-lp);
            res %= MODL;
            it->second = lst+c;
        } else {
            ds[i].insert({p,c});
            int lp = MN(ps[p]);
            // if(p == 2) { cout << "lp: " << lp << endl; }
            ps[p].insert(c);
            int np = MN(ps[p]);
            // if(p == 2) { cout << "np: " << np << endl; }
            res *= pw(p,np-lp);
            res %= MODL;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(ll i = 2; i < mx; i ++) {
        if(sieve[i]) { continue; }
        sieve[i] = i;
        for(ll j = i*i; j < mx; j += i) {
            sieve[j] = (sieve[j] == 0 ? i : min(sieve[j],i));
        }
    }

    int q;
    cin >> n >> q;
    vector<int> as(n);
    int idx = 0;
    for(int &a : as) {
        cin >> a;
        update(idx++,a);
    }
    // for(int i = 0; i < n; i ++) {
    //     cout << (ds[i].find(2) == ds[i].end() ? 0 : ds[i][2]) << " ";
    // }
    // cout << "\n";
    for(int qi = 0; qi < q; qi ++) {
        int i, x;
        cin >> i >> x;
        i --;
        update(i,x);
        cout << res << "\n";
        
        // for(int i = 0; i < n; i ++) {
        //     cout << (ds[i].find(2) == ds[i].end() ? 0 : ds[i][2]) << " ";
        // }
        // cout << "\n";
    }
    return 0;
}