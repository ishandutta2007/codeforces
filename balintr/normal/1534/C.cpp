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
#define sc second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}

const int MN = 4e5 + 5;
const ll MOD = 1e9 + 7;
int t, n;
int arr[2][MN];
vi adjList[MN];
bool vis[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        memset(vis, 0, n*sizeof(bool));
        for (int i = 0; i < n; ++i) {
            adjList[i].clear();
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                arr[i][j]--;
            }
        }

        for (int i = 0; i < n; ++i) {
            adjList[arr[0][i]].pb(arr[1][i]);
            adjList[arr[1][i]].pb(arr[0][i]);
        }

        ll ans = 1;
        for (int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            ans *= 2;
            ans %= MOD;

            vis[i] = true;
            queue<int> qu;
            qu.push(i);

            while(!qu.empty()){
                int n1 = qu.front(); qu.pop();
                for(int n2 : adjList[n1]){
                    if(vis[n2]) continue;
                    vis[n2] = true;
                    qu.push(n2);
                }
            }
        }

        cout << ans << '\n';
    }
}