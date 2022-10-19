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
int arr[MN], brr[MN], freq[MN];
vi adjList[MN];
int deg[MN];
int qu[MN], ql, qr;

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;

        FR(i, n) cin >> arr[i], freq[--arr[i]]++;
        FR(i, n) cin >> brr[i], brr[i]--;

        int mxFreq = 0;
        FR(i, n) if(freq[i] > freq[mxFreq]) mxFreq = i;
        FR(i, n){
            if(arr[i] == mxFreq || brr[i] == mxFreq) continue;
            adjList[arr[i]].pb(brr[i]);
            deg[brr[i]]++;
        }

        FR(i, n) if(i != mxFreq && !deg[i]) qu[qr++] = i;
        while(ql < qr){
            int n1 = qu[ql++];
            for(int n2 : adjList[n1]) if(!--deg[n2]) qu[qr++] = n2;
        }

        cout << (qr == n-1 ? "AC\n" : "WA\n");

        ql = qr = 0;
        FR(i, n){
            deg[i] = 0;
            adjList[i].clear();
            freq[i] = 0;
        }
    }
}