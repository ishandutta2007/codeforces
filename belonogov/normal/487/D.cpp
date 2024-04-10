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
const int M = 11;
const int INF = 1e9 + 19;

int n, m, q;
char s[N][M];
pair < int, int > go[N * 4][M];

void read() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void calc(int v, int pos) {
    //db2(v, pos);
    for (int i = 0; i < m; i++)
        go[v][i] = mp(INF, INF);
    for (int i = 0; i < m; i++) {
        if (s[pos][i] == '^')
            go[v][i] = mp(pos - 1, i);
    }  
    for (int i = 0; i < m - 1; i++) {
        if (s[pos][i] == '>' && s[pos][i + 1] == '<') {
            go[v][i] = mp(-2, -2); 
            go[v][i + 1] = mp(-2, -2); 
        }
    }
    if (s[pos][0] == '<')
        go[v][0] = mp(pos, -1);
    if (s[pos][m - 1] == '>')
        go[v][m - 1] = mp(pos, m); 

    for (int i = 1; i < m; i++) 
        if (s[pos][i] == '<' && go[v][i - 1] != mp(INF, INF))
            go[v][i] = go[v][i - 1];
    for (int i = m - 2; i >= 0; i--) {
        if (s[pos][i] == '>' && go[v][i + 1] != mp(INF, INF))
            go[v][i] = go[v][i + 1];
    }
    for (int i = 0; i < m; i++)
        assert(go[v][i] != mp(INF, INF));
}

void merge(int v, int ll, int rr) {
    int mid = (ll + rr) / 2; 
    int chL = v * 2 + 1;
    int chR = v * 2 + 2;
    for (int i = 0; i < m; i++) {
        if (go[chR][i].fr == mid - 1) {
            go[v][i] = go[chL][go[chR][i].sc];
        } 
        else
            go[v][i] = go[chR][i];
    }
}

void build(int v, int ll, int rr, int l, int r) {
    if (ll >= r || l >= rr) return;
    if (ll + 1 == rr) {
        calc(v, ll);
        return;
    } 
    build(v * 2 + 1, ll, (ll + rr) / 2, l, r);
    build(v * 2 + 2, (ll + rr) / 2, rr, l, r);
    merge(v, ll, rr);
}

pair < int, int > get(int v, int ll, int rr, int r, int col) {
    assert(ll < r);
    if (rr <= r) {
        return go[v][col];
    } 
    int mid = (ll + rr) / 2;
    if (mid < r) {
        auto res = get(v * 2 + 2, (ll + rr) / 2, rr, r, col); 
        if (res.fr == mid - 1)
            return get(v * 2 + 1, ll, (ll + rr) / 2, r, res.sc);
        return res;
    }
    return get(v * 2 + 1, ll, (ll + rr) / 2, r, col);
}

void solve() {
    build(0, 0, n, 0, n);
    //for (int i = 0; i < 3; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << "(" << go[i][j].fr << ", " << go[i][j].sc << ") ";

    for (int i = 0; i < q; i++) {
        char type;
        int x, y;
        scanf(" %c %d %d", &type, &x, &y);
        assert(type == 'A' || type == 'C');
        if (type == 'C') {
            char ch;
            scanf(" %c", &ch);
            assert(ch == '^' || ch == '<' || ch == '>');
            s[x - 1][y - 1] = ch;
            build(0, 0, n, x - 1, x);
        }
        if (type == 'A') {
            auto r = get(0, 0, n, x, y - 1);
            printf("%d %d\n", r.fr + 1, r.sc + 1);
        }
    }
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
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