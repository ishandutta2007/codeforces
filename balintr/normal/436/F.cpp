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
#define dbg(x) {cout << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cout << #arr; FR(i, n) cout << ' ' << arr[i]; cout << endl;}

struct Line {
    int m;
    ll b, x;
};

bool operator<(int x, Line l){
    return x < l.x;
}

ll isect(Line a, Line b){
    ll num = a.b-b.b, denom = b.m-a.m;
    return num/denom + ((num^denom)>0) * bool(num % denom);
}

const int BSZ = 500, BC = 201;
const int MN = BSZ*BC;
int n, cost;
vi upds[MN];
int arr[MN];
Line hull[BC][BSZ];
int hsz[BC];
int pop[BC];

void buildHull(int b){
    int suf = pop[b];
    int qr = 0;
    FOR(i, b*BSZ, (b+1)*BSZ){
        Line l = {i, (ll) suf*i, 0};
        while(qr && isect(l, hull[b][qr-1]) <= hull[b][qr-1].x) qr--;
        l.x = qr ? isect(l, hull[b][qr-1]) : 0;
        hull[b][qr++] = l;
        suf -= arr[i];
    }
    hsz[b] = qr;
}

int main(){
    boost();
    cin >> n >> cost;
    int mx = 0;
    FR(i, n){
        int a, b;
        cin >> a >> b;
        upds[b].pb(a);
        mx = max(mx, b);
    }
    FR(i, BC) buildHull(i);

    int rem = n;
    FR(i, mx+2){
       pll ans = {0, 0};
        int cur = 0;
        FORR(j, BC-1, 0){
            Line l = upper_bound(hull[j], hull[j] + hsz[j], cur)[-1];
            ans = max(ans, {l.b + (ll) l.m * cur, l.m});
            cur += pop[j];
        }
        cout << ans.fs + (ll) rem*cost*i << ' ' << ans.sn << '\n';
        for(int a : upds[i]) rem--, arr[a]++, pop[a/BSZ]++, buildHull(a/BSZ);
    }
}