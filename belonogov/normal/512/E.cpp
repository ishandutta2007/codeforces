#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 1111;
const int INF = 1e9;

int n;
vector < pair < int, int > > res;
vector < pair < int, int > > e;
//queue < pair < int, int > > q;

void read() {
    scanf("%d", &n);
}

bool cmpS(pair < int, int > a, pair < int, int > b) {
    return a.sc < b.sc || (a.sc == b.sc && a.fr > b.fr);
}

void g(int l, int r, bool flag, vector < pair < int, int > > e)  {
    //cerr << "l r: " << l << " " << r << endl;
    //if (l == 2 && r == 5) return;
    //for (auto x: e)
        //cerr << x.fr << " " << x.sc  << endl;
    //cerr << endl;
    if (r - l <= 1) return;
    for (int i = 0; i < (int)e.size(); i++)
        if (e[i].fr == l && e[i].sc == r) {
            int mx = l + 1;
            for (int j = 0; j < (int)e.size(); j++)
                if (e[j].fr == l && e[j].sc != r)
                    mx = max(e[j].sc, mx);
            //cerr << "mx: " << mx << endl;
            if (!flag)
                res.pb(mp(l, r));
            else
                res.pb(mp(0, mx));
            e[i] = mp(0, mx);
        }
    vector < int > tmp;
    for (int i = 0; i < (int)e.size(); i++) {
        if (e[i].fr == 0) {
            tmp.pb(e[i].sc);
        }
    }
    sort(e.begin(), e.end(), cmpS);
    //for (auto x: e)
        //cerr << x.fr << " " << x.sc  << endl;
    //cerr << endl;
    tmp.pb(l);
    tmp.pb(r);
    sort(tmp.begin(), tmp.end());
    int cur = 0;
    for (int i = 0; i < (int)tmp.size() - 1; i++) {
        vector < pair < int, int > > f;
        for (; cur < (int)e.size() && cmpS(e[cur], mp(0, tmp[i + 1])); cur++)
            f.pb(e[cur]);
        g(tmp[i], tmp[i + 1], flag, f);
        cur++;
    }
}

vector < pair < int, int > > f(bool flag) {
    res.clear(); 
    e.resize(n - 3);
    for (int i = 0; i < n - 3; i++) {
        scanf("%d%d", &e[i].fr, &e[i].sc);
        e[i].fr--;
        e[i].sc--;
        if (e[i].fr > e[i].sc)
            swap(e[i].fr, e[i].sc);
    }
    g(1, n - 1, flag, e);   
    auto tmp = res;
    return tmp;
}

void solve() {
    //cerr << "1\n";
    auto r1 = f(0);
    //cerr << "2\n";
    auto r2 = f(1);
    //cerr << "3\n";
    reverse(r2.begin(), r2.end());
    for (auto x: r2)
        r1.pb(x);
    printf("%d\n", (int)r1.size());
    for (auto x: r1)
        printf("%d %d\n", x.fr + 1, x.sc + 1);
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