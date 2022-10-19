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
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

bool choose(int n, int p){
    return !(p & (n-p));
}

const int MP = 25;
const int MN = 1 << 20;
int n, k;
int arr[MN];
bitset<MN> precalc[MP]; // precalc[i][j] = chooseAtLeast(n-i, j)
bitset<MN> ans;

int main(){
    /*FR(i, 10){
        FR(j, i+1) cout << choose(i, j) << ' ';
        cout << endl;
    }*/

    boost();
    cin >> n >> k;
    FR(i, n) cin >> arr[i];

    FOR(i, 1, MP){
        int tmpN = n-i;
        bool cur = 0;
        FORR(j, tmpN, 0){
            cur ^= choose(tmpN, j);
            precalc[i][j] = cur;
        }
    }

    FR(i, n){
        ll v = arr[i];

        FOR(j, i+1, n+1){
            int offs = 2;
            if(i == 0) offs--;
            if(j == n) offs--;
            bool par = precalc[j-i+offs][max(0, k-offs)];
            if(par) ans.flip(v);

            if(arr[j] > MP) break;
            v *= 1 << arr[j];
            if(v >= MN) break;
        }
    }

    bool any = false;
    FORR(i, MN-1, 0){
        if(ans[i]) any = true, cout << 1;
        else if(any) cout << 0;
    }
    if(!any) cout << 0;
    cout << '\n';
}