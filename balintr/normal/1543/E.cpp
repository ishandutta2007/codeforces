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

const int MN = 1 << 16;
int t, k, n;
vi adjList[MN];
int label[MN], dist[MN];
int perm[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> k;
        n = 1 << k;
        for (int i = 0; i < n; ++i) {
            adjList[i].clear();
        }
        for (int i = 0; i < k*n/2; ++i) {
            int a, b;
            cin >> a >> b;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }

        memset(label, 0, n*sizeof(int));
        memset(dist, INF, n*sizeof(int));
        dist[0] = 0;

        queue<int> qu;
        for (int i = 0; i < k; ++i) {
            int n1 = adjList[0][i];
            label[n1] = 1 << i;
            dist[n1] = 1;
            qu.push(n1);
        }

        while(!qu.empty()){
            int n1 = qu.front(); qu.pop();
            for(int n2 : adjList[n1]){
                if(dist[n2] == INF){
                    dist[n2] = dist[n1] + 1;
                    qu.push(n2);
                }
                if(dist[n2] == dist[n1] + 1){
                    label[n2] |= label[n1];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            perm[label[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            cout << perm[i] << " \n"[i == n-1];
        }

        if(__builtin_popcount(k) != 1){
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            int color = 0;
            for (int j = 0; j < k; ++j) {
                if((label[i] >> j) & 1) color ^= j;
            }
            cout << color << " \n"[i == n-1];
        }
    }
}