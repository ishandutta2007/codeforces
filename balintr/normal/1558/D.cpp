#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const ll MOD = 998244353;
const int MN = 4e5 + 20;

namespace Mod {
    ll fact[MN];

    void initFact(){
        fact[0] = 1;
        for (int i = 1; i < MN; ++i) {
            fact[i] = fact[i-1] * i % MOD;
        }
    }

    ll fpow(ll a, ll b){
        ll res = 1;
        ll pw2 = a;
        while(b){
            if(b & 1) res = (res * pw2) % MOD;
            pw2 = (pw2 * pw2) % MOD;
            b >>= 1;
        }
        return res;
    }

    inline ll modInv(ll a){
        return fpow(a, MOD - 2);
    }

    inline ll choose(ll a, ll b){
        return fact[a] * modInv(fact[b]) % MOD * modInv(fact[a - b]) % MOD;
    }
}
using namespace Mod;
int t, n, m;

struct Node;
Node *root;

struct Node {
    int val;
    bool addedBump;
    Node *par;
    Node *child[2];
    int lazyAdd;

    inline bool side(){
        return par->child[1] == this;
    }

    inline void addLazy(int v){
        val += v;
        lazyAdd += v;
    }

    inline void pushDown(){
        if(child[0]) child[0]->addLazy(lazyAdd);
        if(child[1]) child[1]->addLazy(lazyAdd);
        lazyAdd = 0;
    }

    void rotate(){
        Node *p = par;
        p->pushDown();
        pushDown();
        bool s = side();
        if(p->par) p->par->child[p->side()] = this;
        par = p->par;
        if(child[!s]) child[!s]->par = p;
        p->child[s] = child[!s];
        child[!s] = p;
        p->par = this;
    }

    void splay(){
        while(par){
            if(par->par) (side() == par->side() ? par : this)->rotate();
            rotate();
        }
        pushDown();
        root = this;
    }
};

Node nodes[MN];
int ni;

Node* find(int v){
    if(root == nullptr) return nullptr;
    Node *n1 = root;
    while(true){
        n1->pushDown();
        if(v == n1->val){
            n1->splay();
            return n1;
        }

        if(v < n1->val){
            if(n1->child[0]) n1 = n1->child[0];
            else {
                n1->splay();
                return nullptr;
            }
        }
        else {
            if(n1->child[1]) n1 = n1->child[1];
            else {
                n1->splay();
                return nullptr;
            }
        }
    }
}

void insert(int v, bool addedBump){
    if(root == nullptr){
        root = nodes + ni;
        nodes[ni++] = {v, addedBump};
        return;
    }

    Node *n1 = root;
    while(true){
        n1->pushDown();
        if(v <= n1->val){
            n1->val++;
            if(n1->child[1]) n1->child[1]->addLazy(1);
            if(n1->child[0]) n1 = n1->child[0];
            else {
                n1->child[0] = nodes + ni;
                nodes[ni++] = {v, addedBump, n1};
                n1->child[0]->splay();
                return;
            }
        }
        else {
            if(n1->child[1]) n1 = n1->child[1];
            else {
                n1->child[1] = nodes + ni;
                nodes[ni++] = {v, addedBump, n1};
                n1->child[1]->splay();
                return;
            }
        }
    }
}

int main(){
    boost();
    initFact();

    cin >> t;
    while(t--){
        ni = 0;
        root = nullptr;
        cin >> n >> m;

        int bumps = 0;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            Node *f = find(y-1);
            if(f){
                if(f->addedBump){
                    f->addedBump = false;
                    insert(y, true);
                }
                else {
                    bumps++;
                    insert(y, true);
                }
            }
            else {
                bumps++;
                insert(y, true);
            }
        }

        ll ans = choose(n+n-1, n-1);
        int a = n+n-2;
        int b = n-1;
        for (int i = 0; i < bumps; ++i) {
            ans += MOD - choose(a, b);
            a--; b--;
        }

        cout << ans % MOD << '\n';
    }
}