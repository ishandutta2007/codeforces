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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;

struct split {
    int x, t, id;
    split() { }
    split(int x, int t, int id): x(x), t(t), id(id) { }
};


int w, h, n;
vector < pair < int, int > > a;
vector < pair < int, int > > b;

void read() {
    scanf("%d%d%d ", &w, &h, &n);
    for (int i = 0; i < n; i++) {
        char ch;
        int x;
        scanf(" %c %d", &ch, &x);
        assert(ch == 'H' || ch == 'V');
        if (ch == 'H') {
            a.pb(mp(x, i));
            //b.pb(mp(-1, i));
        }
        else {
            //a.pb(mp(-1, i));
            b.pb(mp(x, i));
        }
    }

}
vector < int > p;
vector < int > len;

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    if (v != u) {
        p[v] = u;
        len[u] += len[v];
    }
}



vector < int > f(vector < pair < int, int > > a, int h) { 
    a.pb(mp(h, INF));
    sort(a.begin(), a.end());    

    p.resize(a.size());
    len.resize(a.size());
    for (int i = 0; i < (int)p.size(); i++)
        p[i] = i;
    //cerr << "1.0\n";
    int last = 0;
    vector < pair < int, int > > e; /// time v;
    int mx = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        len[i] = a[i].fr - last;
        last = a[i].fr;
        mx = max(mx, len[i]);
        if (a[i].sc < INF)
            e.pb(mp(a[i].sc, i)); // i i + 1
    }
    //cerr << "mx: " << mx << endl;
    int mx0 = mx;
    sort(e.begin(), e.end(), greater < pair < int, int > > ());
    vector < int > res(n);
    //cerr << res.size() << endl;
    //cerr << "len:   ";
    //for (int i = 0; i < (int)len.size(); i++)
        //cerr << len[i] << " ";
    //cerr << endl;


    for (int i = 0; i < (int)e.size(); i++) {
        int v = e[i].sc;
        int u = e[i].sc + 1;
        merge(v, u);
        v = getId(v);
        mx = max(mx, len[v]);
        //cerr << "e[i].fr mx: " << e[i].fr << " " << mx << endl;
        res[e[i].fr] = mx;
    }
    res.pb(mx0);
    for (int i = (int)res.size() - 1; i >= 0; i--) {
        mx0 = max(mx0, res[i]);
        res[i] = mx0; 
    }
    //reverse(res.begin(), res.end());
    return res;
}

void solve() {
    auto r1 = f(a, h);
    auto r2 = f(b, w); 
    assert((int)r1.size() == n + 1);
    assert((int)r2.size() == n + 1);
    //for (int i = 1; i <= n; i++)
        //cerr << r1[i] << " ";
    //cerr << endl;
    //for (int i = 1; i <= n; i++)
        //cerr << r2[i] << " ";
    //cerr << endl;
    for (int i = 1; i <= n; i++)
        cout << r1[i] * 1ll * r2[i] << "\n";
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}