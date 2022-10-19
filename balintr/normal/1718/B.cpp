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

bool solve(){
    int k; cin >> k;
    multiset<pii> st;
    ll sum = 0;
    FR(i, k){
        int a; cin >> a;
        st.insert({a, INF});
        sum += a;
    }

    if(k == 1) return sum == 1;

    vector<ll> fibs{1, 1};
    sum -= 2;
    while(sum > 0){
        fibs.pb(fibs[SZ(fibs)-1] + fibs[SZ(fibs)-2]);
        sum -= fibs.back();
    }
    if(sum) return false;

    int n = SZ(fibs);
    vector<bool> used(n);

    while(!st.empty()){
        auto lst = --st.end();
        auto [v, req] = *lst;

        bool found = false;
        FORR(i, min(n-1, req), 0){
            if(!used[i] && fibs[i] <= v){
                used[i] = true;
                v -= fibs[i];

                if(i && v >= fibs[i-1]) req = i-2;
                found = true;
                break;
            }
        }

        if(!found) return false;
        st.erase(lst);
        if(v) st.insert({v, req});
    }

    return true;
}

int main(){
    boost();
    int t; cin >> t;
    while(t--) cout << (solve() ? "YES\n" : "NO\n");
}