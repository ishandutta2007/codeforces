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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9 + 19;

struct event {
    int type, x, y, k, id;
    event() { }
    event(int type, int x, int y, int k, int id): type(type), x(x), y(y), k(k), id(id) { }
};


int n, m;
int a[N];
int b[N];
int c[N];
int d[N];
int k[N];
vector < int > xx;
int answer[N];


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &c[i], &d[i], &k[i]);
    }

}

bool cmpX(event a, event b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.type > b.type;
}


void solve() {
    for (int i = 0; i < n; i++) {
        xx.pb(a[i]);
        xx.pb(b[i]);
    }
    for (int i = 0; i < m; i++) {
        xx.pb(c[i]);
        xx.pb(d[i]);
    }
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(xx), a[i]) - xx.begin();
        b[i] = lower_bound(all(xx), b[i]) - xx.begin();
    }
    for (int i = 0; i < m; i++) {
        c[i] = lower_bound(all(xx), c[i]) - xx.begin();
        d[i] = lower_bound(all(xx), d[i]) - xx.begin();
    }

    vector < event > e;
    
    for (int i = 0; i < n; i++)
        e.pb(event(1, a[i], b[i], 1, i));
    for (int i = 0; i < m; i++) 
        e.pb(event(2, c[i], d[i], k[i], i));

    sort(all(e), cmpX);
   
    set < pair < int, int > > q;
    bool flag = 1;
    for (auto g: e) {
        if (g.type == 1) {
            auto it = q.lower_bound(mp(g.y, -1));
            if (it == q.end()) {
                flag = 0;
                break;
            }
            int id = it->sc;
            assert(k[id] > 0);
            answer[g.id] = id;
            k[id]--;
            if (k[id] == 0)
                q.erase(it);
        }
        else 
            q.insert(mp(g.y, g.id));
    }

    if (!flag) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i] + 1);








}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}