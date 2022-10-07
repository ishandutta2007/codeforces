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
#include <random>

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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int M = 1000;

int n;
vector<int> a;
vector<pair<int,int>> q;

void read() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int m;
    scanf("%d", &m);
    q.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &q[i].F, &q[i].S); 
        q[i].F--;
    }
}

int mem[N];
int preCalc[M][M];
int preMn[M][M];
int preMx[M][M];

vector<int> solve() {
    //int SZ = max(1, (int)sqrt(n / 3));
    int SZ = sqrt(n);
    assert(SZ < M);
    vector<int> b = a;
    sort(all(b));
    vector<pair<int,int>> tmp;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < (int)b.size() && b[j] == b[i]; i++);
        tmp.pb(mp(b[j], i - j));
    }
    vector<pair<int,int>> seg;
    //for (auto x: tmp)
        //db2(x.F, x.S);
    for (int i = 0; i < (int)tmp.size(); ) {
        int j = i;
        int sum = 0;
        for (; i < (int)tmp.size() && sum + tmp[i].S <= SZ; i++) {
            sum += tmp[i].S;
        }
        if (j == i) {
            i++;
        }
        //db2(j, i);
        seg.pb(mp(tmp[j].F, tmp[i - 1].F + 1));
    }

    vector<int> res(q.size(), INF);
    vector<int> prev(q.size(), -INF); 
    //db(seg.size());
    for (auto s: seg) {
        //cerr << endl;
        int l = s.F;
        int r = s.S;
        //db2(l, r);
        //db2(res[0], prev[0]);
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            mem[i] = pos.size(); 
            if (l <= a[i] && a[i] < r) {
                pos.pb(a[i]);
            }
        }
        mem[n] = pos.size(); 

        if (r - l > 1) {
            assert((int)pos.size() <= SZ);
            for (int i = 0; i <= (int)pos.size(); i++) {
                //set<int> g;
                //int val = INF;
                int mn = INF;
                int mx = -INF;
                //preCalc[i][i] = INF;
                preMn[i][i] = INF * 2;
                preMx[i][i] = -INF;
                for (int j = i + 1; j <= (int)pos.size(); j++) {
                    int x = pos[j - 1];
                    mn = min(mn, x);
                    mx = max(mx, x);
                    preMn[i][j] = mn;
                    preMx[i][j] = mx;
                }
            } 
            vector<int> upd(pos.size(), INF);
            for (int i = pos.size() - 1; i >= 0; i--) {
                for (int j = i + 1; j < (int)pos.size(); j++) {
                    upd[j] = min(upd[j], abs(pos[j] - pos[i]));
                } 
                int val = INF;
                preCalc[i][i] = INF;
                for (int j = i; j < (int)pos.size(); j++) {
                    val = min(upd[j], val);
                    preCalc[i][j + 1] = val;
                }
            } 
            preCalc[pos.size()][pos.size()] = INF;
        }

        
        for (int i = 0; i < (int)q.size(); i++) {
            int ql = mem[q[i].F];
            int qr = mem[q[i].S];
            //db2(ql, qr);
            //db(res[0]);
            if (r - l == 1) {
                if (qr - ql >= 1) {
                    res[i] = min(res[i], abs(prev[i] - l));
                    prev[i] = l;  
                }
                if (qr - ql >= 2) {
                    res[i] = 0;
                }
            }
            else {
                //db2("!!", res[0]);
                res[i] = min(res[i], preCalc[ql][qr]);
                //db2("!!", res[0]);
                res[i] = min(res[i], abs(prev[i] - preMn[ql][qr]));
                prev[i] = max(prev[i], preMx[ql][qr]);
                //db2("!!", res[0]);
            }
        }

    }

    //db("ret");
    //db(res.size());

    return res;
}

void printAns(vector<int> res) {
    for (auto x: res)
        printf("%d\n", x);
}

vector<int> stupid() {
    vector<int> res;
    for (auto x: q) {
        int l = x.F;
        int r = x.S;
        int mn = INF;
        for (int i = l; i < r; i++)
            for (int j = i + 1; j < r; j++) {
                mn = min(mn, abs(a[j] - a[i]));
            }
        res.pb(mn);
    }
    return res;
}

mt19937 h;

int rnd() {
    return abs((int)h() % ((int)1e9));
}

void genTest() {
    n = rnd() % 30 + 2;
    //n = 4;
    //n = ;
    n = 1e5;
    int Bound = 1e9;
    //int T = 1e7;
    //Bound = 10;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd() % Bound;
        //a[i] = a[i];
        //- a[i] % T;
    }
    int m = rnd() % 5 + 1;
    m = 3e5;
    //m = 1;
    q.resize(m);
    for (int i = 0; i < m; i++) {
        int l = rnd() % n;
        int r = rnd() % n;
        if (l > r) swap(l, r);
        if (l == r) {
            if (r + 1 < n)
                r++;
            else
                l--;
        }
        r++;
        assert(0 <= l && r <= n && r - l >= 2);
        q[i] = mp(l, r);
    }
}

void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << q.size() << endl;
    for (auto x: q)
        cout << x.F + 1 << " " << x.S << endl;
}

void stress() {
    if (1) {
        //genTest(1e5, 3e5);
        genTest();
        auto r = solve();
        cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }
    else {
        for (int tt = 0; ; tt++) {
            db(tt);
            genTest();
            printTest();
            auto r1 = solve();
            auto r2 = stupid();

            for (auto x: r1)
                cerr << x << " ";
            cerr << endl;
            for (auto x: r2)
                cerr << x << " ";
            cerr << endl;
            assert(r1 == r2);
        }
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