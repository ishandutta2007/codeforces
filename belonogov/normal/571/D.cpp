#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 10;
const int INF = 1e9 + 19;

struct DSU {
    vector < int > p;
    vector < vector < int > > who;
    int n;
    void init(int _n) { 
        n = _n;
        p.resize(n);
        who.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            who[i].pb(i);
        }
    }
    int getId(int v) {
        return p[v] == v? v: p[v] = getId(p[v]);
    }
       int getSize(int v) {
        v = getId(v);
        return who[v].size();
    }
};

struct Query {
    char ch;
    int v, u;
    void read() {
        scanf(" %c", &ch);
        if (ch == 'U' || ch == 'M') {
            scanf("%d%d", &v, &u);
            v--;
            u--;
        }
        else  {
            scanf("%d", &v);
            v--;
        }
    }

};

int n, m;
vector < Query > query;
vector < pair < long long, int > > add[N]; // data time
vector < int > lastArm;
pair < long long, int > b[N]; // what, when
DSU study;
DSU army;


void read() {
    scanf("%d%d", &n, &m);
    query.resize(m);
    for (int i = 0; i < m; i++)
        query[i].read();
}

bool mycmp(const pair < long long, int > & a, const pair < long long, int > & b) {
    return a.sc < b.sc;
}

long long getVal(int v) {
    int t1 = lastArm[army.getId(v)];
    int t2 = b[v].sc;
    assert(t1 != t2);
    long long init = (t1 < t2)? b[v].fr: 0;
    int boss = study.getId(v);        
    int pos = lower_bound(add[boss].begin(), add[boss].end(), mp(-1ll, max(t2, t1)), mycmp) - add[boss].begin();
    assert(pos > 0); 
    return init + add[boss].back().fr - add[boss][pos - 1].fr;
}

void solve() {
    study.init(n);
    army.init(n);
    lastArm.assign(n, -2);
    for (int i = 0; i < n; i++)
        b[i] = mp(0, -1);
    for (int i = 0; i < n; i++)
        add[i].pb(mp(0, -3));
    for (int i = 0; i < m; i++) {
        auto x = query[i];
        if (x.ch == 'U') {
            int v = x.v;
            int u = x.u;
            v = study.getId(v);
            u = study.getId(u);
            if (study.who[v].size() < study.who[u].size())
               swap(v, u); 
            for (int j = 0; j < (int)study.who[u].size(); j++) {
                auto x = study.who[u][j];
                study.who[v].pb(x);
                b[x] = mp(getVal(x), i);
            }
            study.who[u].clear();
            study.p[u] = v;
        }
        else if (x.ch == 'M') {
            int v = x.v;
            int u = x.u;
            v = army.getId(v);
            u = army.getId(u);
            if (army.who[v].size() < army.who[u].size())
               swap(v, u); 
            for (int j = 0; j < (int)army.who[u].size(); j++) {
                int x = army.who[u][j];
                army.who[v].pb(x);
                b[x] = mp(getVal(x), i);
            }
            army.who[u].clear();
            army.p[u] = v;
        }
        else if (x.ch == 'Q') {
            printf("%lld\n", getVal(x.v));
        }
        else if (x.ch == 'A') {
            int v = study.getId(x.v);  
            add[v].pb(mp(add[v].back().fr + study.getSize(v), i));
        }
        else if (x.ch == 'Z') {
            int v = army.getId(x.v);
            lastArm[v] = i;
        }
        else
            assert(false);

    }
}

int main(){
    read();
    solve();
}