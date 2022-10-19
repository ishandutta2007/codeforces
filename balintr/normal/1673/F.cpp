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

const int MASK = 0b101010101;
const int MN = 32;
int dif[MN] = {1, 4, 1, 16, 1, 4, 1, 64, 1, 4, 1, 16, 1, 4, 1, 256, 1, 4, 1, 16, 1, 4, 1, 64, 1, 4, 1, 16, 1, 4, 1};
int pref[MN];
int n, k;

int main(){
    boost();
    cin >> n >> k;
    FR(i, MN-1) pref[i+1] = pref[i] ^ dif[i];

    FR(i, n){
        FR(j, n-1){
            cout << dif[j]*2 << " \n"[j == n-2];
        }
    }
    FR(i, n-1){
        FR(j, n){
            cout << dif[i] << " \n"[j == n-1];
        }
    }
    cout << flush;

    int x = 0, y = 0;
    while(k--){
        int v; cin >> v;

        FR(i, MN){
            if((pref[x] ^ pref[i]) == (v & MASK)){
                x = i;
                break;
            }
        }
        FR(i, MN){
            if((pref[y] ^ pref[i]) == ((v >> 1) & MASK)){
                y = i;
                break;
            }
        }

        cout << x+1 << ' ' << y+1 << endl;
    }
}