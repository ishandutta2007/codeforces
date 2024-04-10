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
int t, n;
int arr[MN], brr[MN];
int sz[MN];

bool solve(){
    cin >> n;
    FR(i, n){
        int a; cin >> a; a--;
        arr[i] = a;
        sz[a] = 1;
    }

    FR(i, n) cin >> brr[i];

    int j = 0;
    FR(i, n){
        int b = --brr[i];
        while(j < n && (arr[j] != b || !sz[arr[j]])){
            sz[arr[j]]++;
            int a = arr[++j];
        }
        if(j == n) return false;
        sz[arr[j]]--;
    }

    return true;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cout << (solve() ? "YES\n" : "NO\n");
        FR(i, n) arr[i] = sz[i] = 0;
    }
}