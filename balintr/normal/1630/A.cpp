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

const int MN = 1 << 16;
int t, n;
bool used[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        fill(used, used + n, 0);
        int a, b;
        cin >> a;
        b = (~a) & (n-1);

        if(a == n-1){
            if(n == 4){
                cout << "-1\n";
                continue;
            }
            else {
                used[0] = used[1] = used[2] = used[3] = used[n-1] = used[n-2] = used[n-3] = used[n-4] = true;
                cout << "1 3\n";
                cout << n-2 << ' ' << n-4 << '\n';
                cout << "2 " << n-1 << '\n';
                cout << "0 " << n-3 << '\n';
            }
        }
        else if(a == 0){
            cout << "0 " << n-1 << '\n';
            used[0] = used[n-1] = true;
        }
        else {
            cout << "0 " << b << '\n';
            cout << n-1 << ' ' << a << '\n';
            used[0] = used[b] = used[n-1] = used[a] = true;
        }

        for (int i = 1; i < n-1; i++) {
            if(used[i]) continue;
            int c = (~i) & (n-1);
            cout << i << ' ' << c << '\n';
            used[i] = used[c] = true;
        }
        //cout << endl;
    }
}