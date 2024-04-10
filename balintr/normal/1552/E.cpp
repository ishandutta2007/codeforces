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

const int MN = 105;
const int TSZ = 1 << 14;
int n, k;
vi inds[MN];
bool used[MN];
pair<pii, int> opts[10005];
pii ans[MN];

int tree[TSZ*2], lazy[TSZ*2];

void pushDown(int i){
    tree[i*2] += lazy[i];
    tree[i*2+1] += lazy[i];
    lazy[i*2] += lazy[i];
    lazy[i*2+1] += lazy[i];
    lazy[i] = 0;
}

int update(int i, int segL, int segR, int l, int r){
    if(r <= segL || l >= segR) return tree[i];
    if(l <= segL && r >= segR){
        lazy[i]++;
        return ++tree[i];
    }
    pushDown(i);
    int mid = (segL + segR)/2;
    return tree[i] = max(update(i*2, segL, mid, l, r), update(i*2+1, mid, segR, l, r));
}

int query(int i, int segL, int segR, int l, int r){
    if(r <= segL || l >= segR) return 0;
    if(l <= segL && r >= segR) return tree[i];
    pushDown(i);
    int mid = (segL + segR)/2;
    return max(query(i*2, segL, mid, l, r), query(i*2+1, mid, segR, l, r));
}

int main(){
    boost();
    cin >> n >> k;
    int lim = (n + k-2)/(k-1);

    for (int i = 0; i < n*k; ++i) {
        int c; cin >> c; c--;
        inds[c].pb(i);
    }

    int oi = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < k; ++j) {
            opts[oi++] = {{inds[i][j], inds[i][j-1]}, i};
        }
    }
    sort(opts, opts + oi);

    for (int i = 0; i < oi; ++i) {
        auto [p, c] = opts[i];
        if(used[c]) continue;
        auto [r, l] = p;
        r++;
        int qRes = query(1, 0, TSZ, l, r);
        if(qRes == lim) continue;
        update(1, 0, TSZ, l, r);
        ans[c] = {l+1, r};
        used[c] = true;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i].fs << ' ' << ans[i].sn << '\n';
    }
}