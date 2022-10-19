#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MOD = 1e9 + 1;
const int MN = 2e5 + 5;
int n;

struct Node {
    int v, lazy;
    Node *child[2];

    void pushDown(){
        child[0]->v += lazy;
        child[0]->lazy += lazy;
        child[1]->v += lazy;
        child[1]->lazy += lazy;
        lazy = 0;
    }

    // Add x
    int update(int segL, int segR, int l, int r, int x){
        if(r <= segL || l >= segR) return v;
        if(l <= segL && r >= segR){
            lazy += x;
            return v += x;
        }
        int mid = (segL + segR)/2;
        if(!child[0]) child[0] = new Node{segL};
        if(!child[1]) child[1] = new Node{mid};
        pushDown();
        return v = min(child[0]->update(segL, mid, l, r, x), child[1]->update(mid, segR, l, r, x));
    }

    int query(int segL, int segR, int p){
        if(segL + 1 == segR) return v;
        int mid = (segL + segR)/2;
        if(!child[0]) child[0] = new Node{segL};
        if(!child[1]) child[1] = new Node{mid};
        pushDown();
        if(p < mid) return child[0]->query(segL, mid, p);
        else return child[1]->query(mid, segR, p);
    }

    int lower_bound(int segL, int segR, int x){
        if(v >= x) return segL;
        if(segL + 1 == segR) return segR;
        int mid = (segL + segR)/2;
        if(!child[0]) child[0] = new Node{segL};
        if(!child[1]) child[1] = new Node{mid};
        pushDown();
        int rRes = child[1]->lower_bound(mid, segR, x);
        return rRes == mid ? child[0]->lower_bound(segL, mid, x) : rRes;
    }

    int upper_bound(int segL, int segR, int x){
        if(v > x) return segL;
        if(segL + 1 == segR) return segR;
        int mid = (segL + segR)/2;
        if(!child[0]) child[0] = new Node{segL};
        if(!child[1]) child[1] = new Node{mid};
        pushDown();
        int rRes = child[1]->upper_bound(mid, segR, x);
        return rRes == mid ? child[0]->upper_bound(segL, mid, x) : rRes;
    }
};

Node *root = new Node{};

int main(){
    boost();
    cin >> n;
    int ans = 0;
    while(n--){
        int t; cin >> t;
        int lb = root->lower_bound(0, MOD, t);
        int ub = root->upper_bound(0, MOD, t);
        //cout << "lb " << lb << " ub " << ub << endl;
        root->update(0, MOD, 0, lb, 1);
        root->update(0, MOD, ub, MOD, -1);

        int k; cin >> k;
        while(k--){
            int q; cin >> q;
            q = (q + ans) % MOD;
            //cout << "q " << q << endl;
            ans = root->query(0, MOD, q);
            cout << ans << '\n';
        }
    }
}