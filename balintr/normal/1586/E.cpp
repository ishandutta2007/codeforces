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
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define LAST(v) (v)[SZ(v)-1]
#define SZ(v) ((int) (v).size())
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 3e5 + 5;
int n, m, q;
vi adjList[MN];
int par[MN], par1[MN];
bool vis[MN], vis1[MN];
set<pii> qByNode[MN];
pii qs[MN];
vi ans[MN];

int bfs(int src){
    queue<int> qu;
    qu.push(src);
    ms(par1, -1);
    ms(vis1, 0);
    vis1[src] = true;

    while(!qu.empty()){
        int n1 = qu.front(); qu.pop();
        if(vis[n1]) return n1;

        for(int n2 : adjList[n1]){
            if(vis1[n2]) continue;
            vis1[n2] = true;
            par1[n2] = n1;
            qu.push(n2);
        }
    }

    assert(false);
    return -1;
}

int main(){
    boost();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        qByNode[a].insert({b, i});
        qByNode[b].insert({a, i});
        qs[i] = {a, b};
    }

    int numOdd = 0;
    for (int i = 0; i < n; ++i) {
        numOdd += SZ(qByNode[i]) & 1;
    }

    if(numOdd){
        cout << "NO\n";
        cout << numOdd/2 << '\n';
        return 0;
    }

    bool done = false;
    while(!done){
        done = true;
        for (int i = 0; i < n; ++i) {
            if(!qByNode[i].empty()){
                ms(par, -1);
                ms(vis, 0);

                int a = i;
                int b = qByNode[a].begin()->fs;
                int ind = qByNode[a].begin()->sn;

                qByNode[a].erase(qByNode[a].begin());
                vis[a] = true;

                while(true){
                    int src = a;
                    ans[ind].pb(a);

                    int c = bfs(b);
                    while(a != c){
                        vis[a] = false;
                        a = par[a];
                        ans[ind].pb(a);
                    }
                    while(a != b){
                        int nxt = par1[a];
                        par[nxt] = a;
                        vis[nxt] = true;
                        a = nxt;
                        ans[ind].pb(a);
                    }

                    qByNode[a].erase({src, ind});

                    if(a == i) break;

                    assert(!qByNode[a].empty());
                    b = qByNode[a].begin()->fs;
                    ind = qByNode[a].begin()->sn;
                    qByNode[a].erase(qByNode[a].begin());
                }

                done = false;
                break;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < q; ++i) {
        cout << SZ(ans[i]) << '\n';
        if(ans[i][0] == qs[i].fs){
            for (int j = 0; j < SZ(ans[i]); ++j) {
                cout << ans[i][j]+1 << " \n"[j == SZ(ans[i])-1];
            }
        }
        else {
            for (int j = SZ(ans[i])-1; j >= 0; --j) {
                cout << ans[i][j]+1 << " \n"[j == 0];
            }
        }
    }
}