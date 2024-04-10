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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

int n, qq;
long long t[N];
long long res[N];
int p[N];
int cntCh[N];
set < pair < long long, int > > ch[N];
set < pair < long long, int > > q;

void read() {
    scanf("%d%d", &n, &qq); 
    for (int i = 0; i < n; i++)
        scanf("%lld", &t[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); 
        p[i]--;
        cntCh[p[i]]++;
    }
}

long long getCost(int v) {
    return t[v] / (cntCh[v] + 2);
}

long long getCostMe(int v) {
    return t[v] - getCost(v) * (cntCh[v] + 1);
}

void remMain(int i) {
    if (ch[i].empty()) return;
    q.erase(mp(ch[i].begin()->fr + getCost(i), ch[i].begin()->sc));
    q.erase(mp(ch[i].rbegin()->fr + getCost(i), ch[i].rbegin()->sc));
}

void addMain(int i) {
    if (ch[i].empty()) return;
    q.insert(mp(ch[i].begin()->fr + getCost(i), ch[i].begin()->sc));
    q.insert(mp(ch[i].rbegin()->fr + getCost(i), ch[i].rbegin()->sc));
}

void solve() {
    for (int i = 0; i < n; i++) {
        res[p[i]] += getCost(i);
        res[i] += getCostMe(i);
        //res[i] += t[i] - getCost(i) * (cntCh[i] + 1);
    }     

    for (int i = 0; i < n; i++) {
        ch[p[i]].insert(mp(res[i], i));
    }
    
    for (int i = 0; i < n; i++) {
        if (!ch[i].empty()) {
            addMain(i);
        }
    }

    for (int i = 0; i < qq; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int v, u;
            scanf("%d%d", &v, &u); v--; u--;
            //db3(v, u, p[v]);
            //db(getCost(v));
            

            remMain(p[v]);
            remMain(p[p[v]]);
            remMain(p[p[p[v]]]);

            ch[p[v]].erase(mp(res[v], v));
            ch[p[p[v]]].erase(mp(res[p[v]], p[v]));
            ch[p[p[p[v]]]].erase(mp(res[p[p[v]]], p[p[v]]));

            res[p[v]] -= getCost(v);
            res[p[v]] -= getCostMe(p[v]);
            res[p[p[v]]] -= getCost(p[v]);
            cntCh[p[v]]--;

            res[p[p[v]]] += getCost(p[v]);
            res[p[v]] += getCostMe(p[v]);


            ch[p[p[p[v]]]].insert(mp(res[p[p[v]]], p[p[v]]));
            ch[p[p[v]]].insert(mp(res[p[v]], p[v]));

            addMain(p[p[p[v]]]);
            addMain(p[p[v]]);
            addMain(p[v]);

            //second


            remMain(u);
            remMain(p[u]);
            remMain(p[p[u]]);

            ch[p[u]].erase(mp(res[u], u));
            ch[p[p[u]]].erase(mp(res[p[u]], p[u]));

            res[u] -= getCostMe(u);
            res[p[u]] -= getCost(u);

            cntCh[u]++;

            res[u] += getCostMe(u);
            res[p[u]] += getCost(u);

            res[u] += getCost(v);

            ch[p[p[u]]].insert(mp(res[p[u]], p[u]));
            ch[p[u]].insert(mp(res[u], u));
            ch[u].insert(mp(res[v], v));
            

            addMain(p[p[u]]);
            addMain(p[u]);
            addMain(u);

            p[v] = u;
        }
        else if (type == 2) {
            int v;
            scanf("%d", &v); v--;
            //db2(res[v], getCost(p[v]));
            printf("%lld\n", res[v] + getCost(p[v]));
        }
        else if (type == 3) {
            printf("%lld %lld\n", q.begin()->fr, q.rbegin()->fr);
        }
        else
            assert(false);

    }

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}