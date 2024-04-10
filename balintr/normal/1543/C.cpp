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
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const double EPS = 1e-10;

int t;
double v;
double total;

void solve(int gameNum, double curChance, double a, double b, double c){
    total += gameNum * curChance * c;

    if(a != 0){
        if(a <= v + EPS){
            if(b == 0) solve(gameNum + 1, curChance * a, 0, 0, 1);
            else solve(gameNum + 1, curChance * a, 0, b + a/2, c + a/2);
        }
        else {
            if(b == 0) solve(gameNum + 1, curChance * a, a - v, 0, c + v);
            else solve(gameNum + 1, curChance * a, a - v, b + v/2, c + v/2);
        }
    }

    if(b != 0){
        if(b <= v + EPS){
            if(a == 0) solve(gameNum + 1, curChance * b, 0, 0, 1);
            else solve(gameNum + 1, curChance * b, a + b/2, 0, c + b/2);
        }
        else {
            if(a == 0) solve(gameNum + 1, curChance * b, 0, b - v, c + v);
            else solve(gameNum + 1, curChance * b, a + v/2, b - v, c + v/2);
        }
    }
}

int main(){
    boost();
    cin >> t;
    cout.precision(9);
    cout << fixed;

    while(t--){
        total = 0;
        double a, b, c;
        cin >> a >> b >> c >> v;
        solve(1, 1, a, b, c);
        cout << total << '\n';
    }
}