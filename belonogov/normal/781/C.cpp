#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, m, k;
vector<int> e[N];
vector<int> st;
bool use[N];

void dfs(int v) {
    use[v] = 1;
    st.pb(v);
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs(u);
            st.pb(v);
        }
    }
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    dfs(0);
    for (int i = 0; i < k; i++) {
        int l = st.size() * 1ll * i / k;
        int r = st.size() * 1ll * (i + 1) / k; 
        printf("%d ", r - l);
        assert(r - l <= (n * 2 + k - 1) / k);
        for (int j = l; j < r; j++)
            printf("%d ", st[j] + 1);
        puts("");
    }    

    return 0;
}