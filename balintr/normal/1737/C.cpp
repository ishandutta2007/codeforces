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

int t, n;
pii tar;
vpii vec;

void rot(pii &p){
    p = {p.sn, n-p.fs-1};
}

bool solve(){
    vec.clear();
    cin >> n;
    FR(i, 3){
        int x, y;
        cin >> x >> y;
        x--; y--;
        vec.pb({x, y});
    }
    cin >> tar.fs >> tar.sn;
    tar.fs--; tar.sn--;

    FR(i, 4){
        rot(tar);
        for(pii &p : vec) rot(p);
        sort(ALL(vec));

        if(vec[0] == pii{0, 0} && vec[1] == pii{0, 1} && vec[2] == pii{1, 0}) return tar.fs == 0 || tar.sn == 0;
    }

    for(pii p : vec) if((tar.fs & 1) == (p.fs & 1) && (tar.sn & 1) == (p.sn & 1)) return true;
    return false;
}

int main(){
    boost();
    cin >> t;
    while(t--) cout << (solve() ? "YES\n" : "NO\n");
}