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

const int MN = 2e5 + 5;
int n, q;
bool arr[MN];
vpii compr;
int valArr[MN];

int main(){
    boost();
    string str;
    cin >> n >> q >> str;
    FR(i, n) arr[i] = str[i] - '0';

    int prv = -1;
    FR(i, n){
        if(arr[i] == prv) compr.pb({i, prv});
        prv = arr[i];
    }

    int sz = SZ(compr);
    FR(i, sz) valArr[i+1] = valArr[i] + (compr[i].sn ? 1 : -1);

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;

        l = lower_bound(ALL(compr), pii{l+1, 0}) - compr.begin();
        r = lower_bound(ALL(compr), pii{r, 0}) - compr.begin();

        int len = r-l;
        int x = abs(valArr[l] - valArr[r]);

        cout << 1 + x + (len-x)/2 << '\n';
    }
}