#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
typedef long double f80;
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int log2(int x){
    int c = 0;
    while(x){
        c++;
        x >>= 1;
    }
    return c - 1;
}
struct node{
    node *l, *r;
    int val, lz;
    node() : l(NULL), r(NULL), val(0), lz(0) {}
};
class dynamic_segtree{
public:
    node *tr;
    int n;
    void init(int nn){
        n = nn;
        tr = NULL;
    }
    void pushdown(node * &cur, int s,int e){
        if(!cur) return;
        if(!cur -> lz) return;
        cur -> val = 1;
        if(s != e){
            if(!cur -> l) cur -> l = new node();
            cur -> l -> lz = cur -> lz;
            if(!cur -> r) cur -> r = new node();
            cur -> r -> lz = cur -> lz;
        }
        cur -> lz = 0;
    }
    int getval(node * &cur){
        if(!cur) return 0;
        return cur -> val;
    }
    void update(node * &cur,int s,int e,int l,int r){
        if(!cur) cur = new node();
        pushdown(cur, s, e);
        if(s > r || e < l) return;
        if(l <= s && e <= r){
            cur -> lz = 1;
            pushdown(cur, s, e);
            return;
        }
        int m = (s + e) >> 1;
        update(cur -> l, s, m, l, r);
        update(cur -> r, m + 1, e, l, r);
        cur -> val = getval(cur -> l) + getval(cur -> r);
    }
    void update(int l,int r){
        update(tr, 0, n, l, r);
    }
} T, T1;

bool pos = 1;
vector<pii> ans;

void solve(node * &cur, node * &cur1,int s,int e){
    T.pushdown(cur, s, e);
    T1.pushdown(cur1, s, e);
    if(s == e){
        if(T.getval(cur) && T1.getval(cur1))
        {
            pos = 0;
            return;
        }
    }
    if(!T.getval(cur)) return;
    if(!T1.getval(cur1)) { ans.pb({s, e}); return; }
    int m = (s + e) >> 1;
    solve(cur -> l, cur1 -> l, s, m);
    if(!pos) return;
    solve(cur -> r, cur1 -> r, m + 1, e);
    if(!pos) return;
}

pii get(string s){
    int n = s.size();
    bool bb = 0;
    int x = 0;
    int l = 0;
    int val = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == '/') bb = 1;
        else if(bb){
            x = x * 10 + s[i] - '0';
        }
        else{
            if(s[i] == '.'){
                l = l * 256 + val;
                val = 0;
            }
            else
                val = 10 * val + s[i] - '0';
        }
    }
    if(bb) x = 32 - x;
    x = 1LL << x;
    l = l * 256 + val;
    l = (l / x) * x;
    return {l, l + x - 1};
}
void print(int l,int r){
    int x = log2(r - l + 1);
    assert((1LL << x) == r - l + 1);
    x = 32 - x;
    string s = "";
    int val = l / 16777216;
    s += to_string(val);
    s += '.';
    val = (l / 65536) % 256;
    s += to_string(val);
    s += '.';
    val = (l / 256) % 256;
    s += to_string(val);
    s += '.';
    val = l % 256;
    s += to_string(val);
    s += '/';
    s += to_string(x);
    cout << s << endl;
}
string s;
signed main(){
    IO;
    //freopen("inp.txt", "r", stdin);
    int tot = (1LL << 32) - 1;
    T.init(tot);
    T1.init(tot);
    int n;
    cin >> n;
    fr(i, 1, n){
        cin >> s;
        pii q = get(s);
        assert(q.fi >= 0 && q.fi <= q.se && q.se <= tot);
        if(s[0] == '-'){
            T.update(q.fi, q.se);
        }
        else{
            T1.update(q.fi, q.se);
        }
    }
    solve(T.tr, T1.tr, 0, tot);
    if(!pos)
        {cout << -1; return 0;}
    assert((int)ans.size() > 0);
    cout << (int)ans.size() << endl;
    for(pii x : ans)
        print(x.fi, x.se);
    return 0;
}