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

int n;
vector<pair<int,int>> e[N];
ll aa[N];
ll h[N];
int tin[N];
int tout[N];
int tmr;
int tree[N];

void dfs(int v, ll hh) {
    //db2(v, hh);
    h[v] = hh;
    tin[v] = tmr++;
    for (auto x: e[v])
        dfs(x.F, hh + x.S);
    tout[v] = tmr;
}


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%lld", &aa[i]);
    for (int i = 1; i < n; i++) {
        int v, c;
        scanf("%d%d", &v, &c); v--;
        e[v].pb(mp(i, c));
    }

}

struct Event {
    int type;
    ll x;
    int l, r, id;
    void Epr() {
        cerr << "type x: " << type << " " << x << "    l r id: " << l << " " << r << " " << id << endl;
    }
};


void add(int pos, int val) {
    for (; pos <= n; pos |= (pos + 1))
        tree[pos + 1] += val;
}

int get(int r) {
    int res = 0;
    for (; r > 0; r &= (r - 1))
        res += tree[r];
    return res;
}

int get(int l, int r) {
    return get(r) - get(l);
}

vector<int> solve() {
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        a[i] = aa[i];
    for (int i = 0; i <= n; i++)
        tree[i] = 0;
    tmr = 0;
    dfs(0, 0);
    for (int i = 0; i < n; i++)
        a[i] -= h[i];
    vector<Event> event;
    for (int i = 0; i < n; i++) {
        event.pb({1, -a[i], -1, -1, tin[i]});
        event.pb({2, h[i], tin[i] + 1, tout[i], i});
    }
    //for (int i = 0;
    //for (int i = 0; i < n; i++)
        //db2(h[i], a[i]);
    //for (auto x: event)
        //x.Epr();

    sort(all(event), [](Event A, Event B) {
                return A.x < B.x || (A.x == B.x && A.type < B.type);
            });
    //cerr << endl;
    //for (auto x: event)
        //x.Epr();
    
    vector<int> answer(n);
    for (auto x: event) {
        if (x.type == 1) {
            add(x.id, 1);
            //db3("add ", x.id, 1);
        }   
        else {
            //db3(x.id, x.l, x.r);
            answer[x.id] = get(x.l, x.r);
        }
    }

    return answer;
}
int cc;

void dfs2(int v, int hh) {
    //db2(v, hh);
    if (hh <= aa[v])
        cc++;
    for (auto x: e[v])
        dfs2(x.F, hh + x.S);
}

vector<int> stupid() {
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        cc = 0;
        dfs2(i, 0); 
        cc--;
        answer.pb(cc);
    }
    return answer;
}

void printAns(vector<int> answer) {
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
    puts("");

}

int par[N];
int pc[N];

void genTest() {
    n = rand() % 100 + 1;
    //n = 4;
    int T = 10;
    for (int i = 0; i < n; i++)
        aa[i] = rand() % T + 1;
    for (int i = 0; i < n; i++) 
        e[i].clear();
    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        int c = rand() % T;
        par[i - 1] = v;
        pc[i - 1] = c;
        e[v].pb(mp(i, c));
    }
}

void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << aa[i] << " ";
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << par[i] + 1 << " " << pc[i]  << endl;
    }

}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);         
        genTest();
        //db("here");
        auto r1 = solve();
        //db("tut");
        auto r2 = stupid();
        if (r1 != r2) {
            for (auto x: r1)
                cerr << x << " ";
            cerr << endl;
            for (auto x: r2)
                cerr << x << " ";
            cerr << endl;
            printTest();
        }
        assert(r1 == r2);
        db("OK");
    }
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        printAns(solve());
        //printAns(stupid());
    }
    else {
        stress();
    }

    return 0;
}