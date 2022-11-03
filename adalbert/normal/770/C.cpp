///Lol kek cheburek///
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;
typedef double ld;

#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase

#define elif else if
#define all(v) (v).begin(),(v).end()
#define len(s) int((s).size())

#define fi first
#define se second
#define x first
#define y second

#define fpos krevedka
#define left Levo
#define right ishtenem
#define next nastupniy
#define prev poperedniy
#define div dilyty_sukotay

#define I64 "%lld"

#define I "%d"
#define II I I
#define III II I
#define IIII II II
#define IIIII III II
#define IIIIII III III
#define IIIIIII IIII III
#define IIIIIIII IIII IIII

#define dbg cout << "dbg\n"
#define files(name) freopen(name".in", "r", stdin);freopen(name".out","w", stdout);
#define UOIfiles(name) freopen(name".dat", "r", stdin);freopen(name".sol","w", stdout);


ld sqr(ld x) {return x * x;}

const ll md = 1e9 + 7;
const ll md2 = 2e9 + 7;
const ld PI = acos(-1);
const int MAXN = 2e6 + 1;
const int INF = 1e9 + 1;
const int RNG = 1e8 + 10;
const pii turns[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const char signs[4] = {'D', 'L', 'R', 'U'};

///end template ///

int n, k;
int mainNodes[MAXN];
vi g[MAXN];

int vis[MAXN];
bool isCycle;
vi ans;

void dfs(int v)
{
    vis[v] = 1;

    for(auto to : g[v]) {
        if(vis[to] == 0) {
            dfs(to);
        }
        else if(vis[to] == 1) {
            isCycle = true;
        }
    }
    vis[v] = 2;
    ans.pb(v);
}


int main()
{
    //UOIfiles("split");
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    scanf(II, &n, &k);
    for(int i = 0; i < k; i++)
        scanf(I, &mainNodes[i]);

    for(int i = 1; i <= n; i++) {
        int sz;
        scanf(I, &sz);
        g[i].resize(sz);
        for(int j = 0; j < len(g[i]); j++) {
            scanf(I, &g[i][j]);
        }
    }

    for(int i = 0; i < k; i++) {
        if(vis[mainNodes[i]] == 0) {
            dfs(mainNodes[i]);
        }
    }

    if(isCycle) {
        cout << -1;
    }
    else {
        cout << len(ans) << "\n";
        for(auto x : ans) {
            cout << x << " ";
        }
    }

}