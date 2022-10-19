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
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

const int MN = 505;
int t, n, m;
int disA[MN], disB[MN], disC[MN], qu[MN], ql, qr;
vpii adjList[MN];

void bfs(vi srcs, int *dis){
    ql = qr = 0;
    fill_n(dis, n, INF);
    for(int s : srcs) qu[qr++] = s, dis[s] = 0;

    while(ql < qr){
        int n1 = qu[ql++];
        for(auto [n2, c] : adjList[n1]){
            if(dis[n2] == INF){
                dis[n2] = dis[n1] + 1;
                qu[qr++] = n2;
            }
        }
    }

    //dbgArr(dis, n);
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        FR(i, m){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            adjList[a].pb({b, c});
            adjList[b].pb({a, c});
        }

        bfs({0}, disA);
        bfs({n-1}, disB);

        vi srcs;
        FR(i, n) if(disA[i] + disB[i] == disA[n-1]) srcs.pb(i);
        bfs(srcs, disC);

        ll ans = LLINF;
        FR(n1, n){
            for(auto [n2, c] : adjList[n1]){
                ans = min(ans, (ll) c * (disA[n1] + disB[n2] + 1));
                ans = min(ans, (ll) c * (disB[n1] + disA[n2] + 1));
                ans = min(ans, (ll) c * (min(disC[n1], disC[n2]) + disA[n-1] + 2));
            }
        }

        cout << ans << '\n';

        FR(i, n) adjList[i].clear();
    }
}