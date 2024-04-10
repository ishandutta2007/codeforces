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
#define dbgArr(arr, n) {cout << #arr; FR(_i, n) cout << ' ' << arr[_i]; cout << endl;}

const int MN = 2005;
int n;
int arr[MN];

int query(int a){
    cout << "? " << a << endl;

#ifdef WIN32
    int r = 1;
    int cur = 0;
    FR(i, n){
        if(arr[i] > a) return 0;
        if(cur + arr[i] > a) cur = 0, r++;
        cur += arr[i] + 1;
    }
    return r;
#endif

    int res; cin >> res;
    return res;
}

int main(){
    boost();
    cin >> n;

#ifdef WIN32
    FR(i, n) cin >> arr[i];
#endif

    int lo = n, hi = 4 << 20;
    while(lo < hi){
        int mid = (lo+hi)/2;
        int qRes = query(mid);
        if(qRes == 1) hi = mid;
        else lo = mid+1;
    }

    int ans = lo;
    FOR(i, 2, n+1){
        int req = (ans-1)/i;
        if(!req) continue;
        int qRes = query(req);
        if(qRes) ans = min(ans, req*qRes);
    }
    cout << "! " << ans << endl;
}