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
int n;
int arr[MN], lst[MN];

int p, ans;
void addRange(int e){
    ans += e - p - 1;
    int mx = -1;
    for (int i = p+1; i < e; i++) {
        mx = max(mx, lst[arr[i]]);
    }
    p = e;
    if(mx > e){
        addRange(mx);
    }
}

int main(){
    boost();
    cin >> n;
    fill(lst, lst + n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        lst[arr[i]] = i;
    }

    p = ans = 0;
    while(p < n){
        if(lst[arr[p]] == p) p++;
        else addRange(lst[arr[p]]);
    }

    cout << ans << '\n';
}