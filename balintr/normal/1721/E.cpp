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
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

template <typename T, int MSZ>
struct RMQ {
    T table[__lg(MSZ)+1][MSZ];
    int sz, height;

    void init(int inSz){
        sz = inSz;
        height = __lg(sz)+1;
        for (int k = 1, pw = 1; k < height; ++k, pw *= 2) {
            int len = sz - pw*2 + 1;
            for (int j = 0; j < len; ++j) {
                table[k][j] = max(table[k-1][j], table[k-1][j+pw]);
            }
        }
    }

    // Min of [l, r)
    T query(int l, int r){
        assert(l < r);
        int k = __lg(r-l);
        return max(table[k][l], table[k][r - (1 << k)]);
    }

    // Access the bottom row of the sparse table
    inline T& operator[](int i){
        return table[0][i];
    }
};

const int X = 3858331;
const int MOD = 1e9 + 7;
const int MN = 1e6 + 11;
const int MT = 11;
int n, q, t;
string str;
int pws[MN], hashes[MN], sa[MN], saSz;
RMQ<int, MN> rmq;
int ans[MT], arr[MT];

bool cmpSubStr(int a, int b, int len){
    ll h1 = hashes[a+len] - (ll) hashes[a]*pws[len];
    ll h2 = hashes[b+len] - (ll) hashes[b]*pws[len];
    return !((h1 - h2) % MOD);
}

int lcp(int a, int b){
    int lo = 0, hi = SZ(str) - max(a, b);
    while(lo < hi){
        int mid = (lo+hi+1)/2;
        if(cmpSubStr(a, b, mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

bool cmpSa(int a, int b){
    int l = lcp(a, b);
    return str[a+l] < str[b+l];
}

int k;
bool cmpKthChar(int a, int b){return str[a+k] < str[b+k];}

int main(){
    pws[0] = 1;
    FR(i, MN-1) pws[i+1] = (ll) pws[i] * X % MOD;
    boost();
    cin >> str;
    n = SZ(str);
    bool hasDifChars = false;
    FR(i, n){
        hashes[i+1] = ((ll) hashes[i]*X + str[i]) % MOD;
        hasDifChars |= str[i] != str[0];
    }

    if(hasDifChars){
        FR(i, n) if(cmpSubStr(0, n-i, i)) sa[saSz++] = i;
        sort(sa, sa + saSz, cmpSa);
    }
    else {
        saSz = n;
        iota(sa, sa + saSz, 0);
        reverse(sa, sa + saSz);
    }

    //dbgArr(sa, saSz);
    FR(i, saSz) rmq[i] = sa[i];
    rmq.init(saSz);

    cin >> q;
    while(q--){
        string tStr; cin >> tStr;
        t = SZ(tStr);
        str.pb(0);
        for(char ch : tStr) str.pb(ch);

        int l = 0, r = saSz;
        FR(i, t){
            k = i;
            l = lower_bound(sa + l, sa + r, n+1, cmpKthChar) - sa;
            r = upper_bound(sa + l, sa + r, n+1, cmpKthChar) - sa;
            //cerr << l << ' ' << r << '\n';
            ans[i] = l == r ? 0 : rmq.query(l, r)+i+1;
        }
        //cerr << endl;

        str.erase(str.begin() + n);
        FOR(i, n, n+t) hashes[i+1] = ((ll) hashes[i]*X + str[i]) % MOD;

        ms(arr, INF);
        FOR(i, 1, t){
            int p1 = lcp(0, i) + i - n - 1;
            if(p1 >= 0) arr[p1] = min(arr[p1], i);
            int p2 = lcp(0, n+i) + i-1;
            if(p2 >= 0) arr[p2] = min(arr[p2], n+i);
        }

        //dbgArr(arr, t);

        int cur = INF;
        FORR(i, t-1, 0){
            cur = min(cur, arr[i]);
            ans[i] = max(ans[i], n+i-cur+1);
        }

        FR(i, t) cout << ans[i] << " \n"[i == t-1];

        FR(i, t) str.pop_back();
    }
}