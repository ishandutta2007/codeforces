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

int n, k;

struct Node {
    int dif, mn, mx;
};

bool input[1 << 19];

vector<Node> build(int l, int r){
    int len = r - l;
    if(l + 1 == r){
        vector<Node> res;
        if(input[l]) res.pb({INF, l, l});
        else res.pb({INF, INF, INF});
        return res;
    }

    int mid = (l + r)/2;
    vector<Node> lRes = build(l, mid);
    vector<Node> rRes = build(mid, r);

    vector<Node> ans;
    for(int i = 0; i < len/2; ++i){
        if(lRes[i].mn == INF && rRes[i].mn == INF) ans.pb({INF, INF, INF});
        else if(lRes[i].mn == INF) ans.pb(rRes[i]);
        else if(rRes[i].mn == INF) ans.pb(lRes[i]);
        else {
            ans.pb({min(rRes[i].mn - lRes[i].mx, min(lRes[i].dif, rRes[i].dif)), lRes[i].mn, rRes[i].mx});
        }
    }

    for(int i = 0; i < len/2; ++i){
        if(lRes[i].mn == INF && rRes[i].mn == INF) ans.pb({INF, INF, INF});
        else if(lRes[i].mn == INF) ans.pb({rRes[i].dif, rRes[i].mn ^ (len/2), rRes[i].mx ^ (len/2)});
        else if(rRes[i].mn == INF) ans.pb({lRes[i].dif, lRes[i].mn ^ (len/2), lRes[i].mx ^ (len/2)});
        else {
            ans.pb({min((lRes[i].mn ^ (len/2)) - (rRes[i].mx ^ (len/2)), min(lRes[i].dif, rRes[i].dif)), rRes[i].mn ^ (len/2), lRes[i].mx ^ (len/2)});
        }
    }

    return ans;
}

int main(){
    boost();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        input[a] = true;
    }

    auto ans = build(0, 1 << k);
    for (int i = 0; i < (1 << k); ++i) {
        cout << ans[i].dif << " \n"[i == (1 << k) - 1];
    }
}