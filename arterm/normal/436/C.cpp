//#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;

#define M 1010
#define N 107

int n, m, k, w, p[M];
char s[M][N];
pair<int, pair<int, int> > e[M*M];
int h = 0;
vector<int> g[M];
bool u[M];

void read(){
    //cin >> n >> m >> k >> w;
    char ch;
    scanf("%d%d%d%d", &n, &m, &k, &w);
    scanf("%c", &ch);
    for (int i = 1; i <= k; ++i){
        int x = 0;
        for (int j = 0; j < n; ++j, scanf("%c", &ch))
        for (int k = 0; k < m; ++k, ++x)
            scanf("%c", &s[i][x]);
    }
    n *= m;
}

void make(void){
    for (int i = 1; i <= k; ++i)
        e[h++] = make_pair(n, make_pair(0, i));
    for (int i = 1; i <= k; ++i)
    for (int j = i + 1; j <= k; ++j){
        int sum = 0;
        for (int f = 0; f < n; ++f)
        if (s[i][f] != s[j][f])
            ++sum;
        e[h++] = make_pair(sum * w, make_pair(i, j));
    }
}

void ini(void){
    for (int i = 0; i < M; ++i)
        p[i] = i;
}

int get(int x){
    return p[x] == x ? x : get(p[x]);
}

void uni(int x, int y){
    x = get(x);
    y = get(y);
    p[x] = y;
}

void add(int x, int y){
    g[x].push_back(y);
    g[y].push_back(x);
}

void dfs(int v){
    u[v] = 1;
    for (auto &to : g[v])
    if (!u[to]){
        //cout << to << " " << v << "\n";
        printf("%d %d\n", to, v);
        dfs(to);
    }
}

void kill(void){
    ini();
    sort(e, e + h);
    int ans = 0;
    for (int i = 0, x, y; i < h; ++i){
        x = get(e[i].second.first);
        y = get(e[i].second.second);
        if (x != y){
            uni(x, y);
            ans += e[i].first;
            add(e[i].second.first, e[i].second.second);
        }
    }
    //cout << ans << "\n";
    printf("%d\n", ans);
    dfs(0);
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    //ios_base::sync_with_stdio(0);
#endif

    read();

    make();

    kill();

    return 0;
}