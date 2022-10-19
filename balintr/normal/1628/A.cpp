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

const int MN = 2e5 + 5;
int t, n;
int arr[MN];
vi inds[MN];

void solve(){
    vi ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n-1; i >= 0; i--) {
        inds[arr[i]].pb(i);
    }

    int mx = n;
    int ind = -1;
    while(!inds[0].empty()){
        ind = 0;
        for (int i = 0; i <= mx; i++) {
            if(inds[i].empty()){
                mx = i;
                ans.pb(i);
                for (int j = 0; j < i; j++) {
                    while(!inds[j].empty() && inds[j].back() <= ind) inds[j].pop_back();
                }
            }
            else ind = max(ind, inds[i].back());
        }
    }

    for (int i = 0; i <= n; i++) {
        if(!inds[i].empty()) inds[i].clear();
    }

    while(ind++ < n-1) ans.pb(0);

    cout << SZ(ans) << '\n';
    for (int i = 0; i < SZ(ans); i++) {
        cout << ans[i] << " \n"[i == SZ(ans)-1];
    }
}

int main(){
    boost();
    cin >> t;
    while(t--){
        solve();
    }
}