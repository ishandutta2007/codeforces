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
const int N = 1111;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct Team {
    string name, city;
    string res;
    int id;
};

map<string,int> p;
bool use[N];
vector<string> e[N];
set<string> used;

int dfs(int v) {
    use[v] = 1;
    for (auto s: e[v]) {
        if (used.count(s)) continue;
        if (p.count(s) == 0 || (use[p[s]] == 0 && dfs(p[s]))) {
            p[s] = v;
            return 1;
        }
    }
    return 0;
}
    
int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<Team> g;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        g.pb({a.substr(0, 3), b.substr(0, 1), "", i});
    }
    sort(all(g), [](Team A, Team B) {
            return A.name < B.name;
            });

    
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && g[i].name == g[j].name; i++);
        if (i - j > 1) {
            set<string> h;
            for (int k = j; k < i; k++) {
                string tmp = g[k].name.substr(0, 2) + g[k].city; 
                g[k].res = tmp;
                h.insert(tmp);
                used.insert(tmp);
            }
            if ((int)h.size() != i - j) {
                puts("NO");
                return 0;
            }
        }
        else {
            int id = g[j].id;
            string tmp = g[j].name.substr(0, 2) + g[j].city; 
            e[id].pb(g[j].name);
            e[id].pb(tmp);
        }
    }

    sort(all(g), [](Team A, Team B) {
            return A.id< B.id;
            });

    for (int i = 0; i < n; i++) {
        if (!e[i].empty()) {
            memset(use, 0, sizeof(use));
            if (!dfs(i)) {
                puts("NO");
                return 0;
            }
        }
    }  

    for (auto x: p) {
        g[x.S].res = x.F;
    }

    used.clear();
    for (auto x: g)
        used.insert(x.res);
    if ((int)used.size() != n) {
        puts("NO");
        return 0;
    }


    cout << "YES" << endl;
    for (auto x: g) {
        cout << x.res << "\n";
        assert(!x.res.empty());
    }

    return 0;
}