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
#include <sstream>

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
const int N = 333; 
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct Node {
    int pre, cyc;
    Node() { }
    Node(int _pre, int _cyc): pre(_pre), cyc(_cyc) { }
};

int n;
Node a[N];
Node aa[N];
vector<int> e[N];
int p[N];
bool use[N];
bool superUse[N];
int answer[N];
int who[N][N];

int dfs(int v) {
    use[v] = 1;
    for (auto u: e[v]) {
        if (p[u] == -1 || (!use[p[u]] && dfs(p[u]))) {
            p[u] = v;
            return 1;
        }
    }
    return 0;
}


void read() {
    //stringstream g;
    //g << "123";
    //int xx;
    //g >> xx;
    //db(xx);
    //exit(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int x, y;
        //db2(s1, s2);
        if (s1 == "?") {
            x = -1;
        }
        else {
            stringstream ss;
            ss << s1;
            ss >> x;
        }
        if (s2 == "?") {
            y = -1;
        }
        else {
            stringstream ss;
            ss << s2;
            ss >> y;
        }
        //db2(x, y);
        a[i] = Node(x, y);
    }
    for (int i = 0; i < n; i++)
        aa[i] = a[i];
}

bool match(Node cand, Node need) {
    return (cand.pre == -1 || cand.pre == need.pre) && (cand.cyc == -1 || cand.cyc == need.cyc);
}

//void fail() {
    //puts("-1");
//}

bool valid() {
    //cerr << "answer: ";
    //for (int i = 0; i < n; i++)
        //cerr << answer[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //db2(a[i].pre, a[i].cyc);
    for (int i = 0; i < n; i++) {
        assert(match(aa[i], a[i]));
    }
    for (int i = 0; i < n; i++) {
        map<int,int> vis;
        int v = i;
        for (int tmr = 0;;tmr++) {
            if (vis.count(v) == 1) {
                int cyc = tmr - vis[v];
                int pre = vis[v];
                //db2(pre, cyc);
                if (!(cyc == a[i].cyc && pre == a[i].pre))
                    return 0;
                //assert(cyc == a[i].cyc && pre == a[i].pre);
                break;
            }
            vis[v] = tmr;
            v = answer[v];
        }

    }    

    return 1;

}

bool build() {
    memset(who, -1, sizeof(who));
    memset(answer, -1, sizeof(answer));
    //for (int i = 0; i < n; i++)
        //db2(a[i].pre, a[i].cyc);
    for (int len = 1; len <= n; len++) {
        vector<int> tmp;
        for (int i = 0; i < n; i++)
            if (a[i].pre == 0 && a[i].cyc == len) {
                tmp.pb(i);
            }
        if (tmp.size() % len != 0) 
            return 0;
        //assert(tmp.size() % len == 0);
        //db(tmp.size());
        for (int i = 0; i < (int)tmp.size(); i++) {
            answer[tmp[i]] = tmp[i - i % len + (i + 1) % len];
        }
    }
    for (int i = 0; i < n; i++)
        who[a[i].pre][a[i].cyc] = i;

    for (int i = 0; i < n; i++)
        if (a[i].pre != 0) {
            answer[i] = who[a[i].pre - 1][a[i].cyc];
        }
    return valid();
}

vector<int> solve() {
//int n;
//Node a[N];
//Node aa[N];
//vector<int> e[N];
//int p[N];
//bool use[N];
//bool superUse[N];
//int answer[N];
//int who[N][N];


    int pp = 0;
    for (int i = 0; i < n; i++)
        pp = max(pp, a[i].pre);

    bool cool = 0;
    for (int whoMax = 1; whoMax <= n; whoMax++) {
        //db(whoMax);
        for (int i = 0; i < n; i++)
            a[i] = aa[i];
        for (int i = 0; i < n; i++)
            e[i].clear();
        memset(superUse, 0, sizeof(superUse));


        bool allQCyc = 1;
        for (int i = 0; i < n; i++) {
            allQCyc &= a[i].cyc == -1;
        }
        if (allQCyc) {
            a[0].cyc = 1;
        }
        vector<Node> need; 
        vector<int> mxPre(n + 1);
        //for (int i = 0; i < n; i++)
            //db2(a[i].pre, a[i].cyc);

        for (int len = 1; len <= n; len++) {
            vector<int> cnt(n);
            int mx = -1;
            for (int i = 0; i < n; i++)
                if (a[i].cyc == len) {
                    if (a[i].pre != -1)
                        cnt[a[i].pre]++;
                    else
                        mx = 0;
                }
            for (int i = 0; i < n; i++)
                if (cnt[i] > 0)
                    mx = i;
            if (len == whoMax)
                mx = pp;
            mxPre[len] = mx;
            //db(mx);
            if (mx != -1) {
                for (int i = 1; i <= mx; i++)
                    if (cnt[i] == 0)
                        need.pb(Node(i, len));
                int needZero;
                if (cnt[0] == 0)
                    needZero = len;
                else {
                    needZero = (len - cnt[0] % len) % len;
                }
                //db2(len, needZero);
                for (int i = 0; i < needZero; i++)
                    need.pb(Node(0, len));
            }
        }
        //db(need.size());
        //for (auto x: need)
            //db2(x.pre, x.cyc);
        if ((int)need.size() > n) {
            //return vector<int>();
            continue;
        }

        for (int i = 0; i < n; i++) {
            if ((a[i].pre == -1) != (a[i].cyc == -1)) {
                for (int j = 0; j < (int)need.size(); j++)
                    if (match(a[i], need[j])) {
                        e[i].pb(j);
                    }
            }
        }  
        for (int i = 0; i < (int)need.size(); i++)
            p[i] = -1;

        vector<int> perm;
        for (int i = 0; i < n; i++)
            if ((a[i].pre == -1) != (a[i].cyc == -1)) 
                perm.pb(i);

        //sort(all(perm), [](int id1, int id2) {
                    //int r1 = a[id1].cyc == -1;
                    //int r2 = a[id2].cyc == -1;
                    //return r1 > r2;
                //});
        

        //for (auto id: perm) {
        for (int i = 0; i < n; i++) {
            memset(use, 0, sizeof(use));
            superUse[i] = dfs(i);
            //superUse[id] = dfs(id);
        }


        bool fail = 0;
        for (int i = 0; i < (int)need.size(); i++) {
            if (p[i] == -1) {
                bool good = 0;
                for (int j = 0; j < n; j++)
                    if (a[j].pre == -1 && a[j].cyc == -1 && superUse[j] == 0) {
                        superUse[j] = 1;
                        p[i] = j;
                        good = 1;
                        break;
                    }
                if (!good) {
                    fail = 1;
                    break;
                }
            }
            assert(match(a[p[i]], need[i]));
            a[p[i]] = need[i];
        }
        if (fail)
            continue;

        //for (int i = 0; i < n; i++)
            //db2(a[i].pre, a[i].cyc);

        for (int i = 0; i < n; i++) {
            if (!superUse[i] && a[i].cyc == -1  && a[i].pre == 0) {
                a[i].cyc = 1;
            }
        }


        for (int i = 0; i < n; i++) {
            if (!superUse[i] && a[i].pre == -1 && a[i].cyc != -1) {
                int len = a[i].cyc;
                //answer[i] = who[len][mxPre[len]];
                superUse[i] = 1;
                mxPre[len]++;                     
                //who[len][mxPre[len]] = i;
                a[i].pre = mxPre[len];
            }
        }
        int longestPre = -1;
        for (int len = 1; len <= n; len++) {
            if (mxPre[len] >= 0 && (longestPre == -1 || mxPre[len] > mxPre[longestPre])) {
                longestPre = len;
            }
        }
        //for (int i = 0; i < n; i++)
            //db2(a[i].pre, a[i].cyc);

        assert(longestPre != -1);
        for (int i = mxPre[longestPre] + 1; i <= n; i++) {
            int whoCan = -1; 
            for (int j = 0; j < n; j++) {
                if (superUse[j] == 0 && a[j].pre == i && a[j].cyc == -1) {
                    whoCan = j;
                    break;
                }
            }
            if (whoCan != -1) {
                superUse[whoCan] = 1;
                //who[longestPre][i] = whoCan;
                a[whoCan].cyc = longestPre;
            }
            else {
                bool ok = 0;
                for (int j = 0; j < n; j++) {
                    if (superUse[j] == 0 && a[j].pre == -1 && a[j].cyc == -1) {
                        superUse[j] = 1;
                        //who[longestPre][i] = j;
                        a[j] = Node(i, longestPre);
                        ok = 1;
                        break;
                    }
                }  
                if (!ok)
                    break;
            }
            mxPre[longestPre]++;
        }
        //db(mxPre[longestPre]);
        //for (int i = 0; i < n; i++)
            //db2(a[i].pre, a[i].cyc);

        for (int i = 0; i < n; i++) {
            if (a[i].cyc == -1 && a[i].pre > mxPre[longestPre]) {
                assert(false);
                return vector<int>();
            }
        }
        for (int i = 0; i < n; i++) 
            if (a[i].cyc == -1) {
                a[i].cyc = longestPre;
            }

        if (build()) {
            cool = 1;
            break;
        }
    }
    //db("her");
    if (cool) {
        vector<int> tmp;
        //db(n);
        for (int i = 0; i < n; i++)
            tmp.pb(answer[i]);
        //db(tmp.size());
        return tmp;
    }
    return vector<int>(); 
}

void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        if (aa[i].pre == -1)
            cout << "?";
        else
            cout << aa[i].pre;
        cout << " ";
        if (aa[i].cyc == -1)
            cout << "?";
        else
            cout << aa[i].cyc;
        cout << endl;
    }
}

void genTest() {
    n = rand() % 6 + 1;
    for (int i = 0; i < n; i++) {
        int pre = rand() % (n + 1) - 1; 
        int cyc = rand() % (n + 1) - 1;
        if (cyc == 0)
            cyc++;
        aa[i] = a[i] = Node(pre, cyc);
    }
}

struct A {
    int l, r;
    int id, type;
};


vector<A> forRec;
vector<int> hh;
int val[N * 2];



bool valid2() {
    //cerr << "answer: ";
    //for (int i = 0; i < n; i++)
        //cerr << answer[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //db2(a[i].pre, a[i].cyc);
    for (int i = 0; i < n; i++)
        if (answer[i] == -1)
            return 0;
    for (int i = 0; i < n; i++) {
        assert(match(aa[i], a[i]));
    }
    for (int i = 0; i < n; i++) {
        map<int,int> vis;
        int v = i;
        for (int tmr = 0;;tmr++) {
            //db(tmr);
            if (vis.count(v) == 1) {
                int cyc = tmr - vis[v];
                int pre = vis[v];
                //db2(pre, cyc);
                if (!(cyc == a[i].cyc && pre == a[i].pre))
                    return 0;
                break;
            }
            vis[v] = tmr;
            v = answer[v];
        }

    }    
    return 1;
}



bool build2() {
    memset(who, -1, sizeof(who));
    memset(answer, -1, sizeof(answer));
    //for (int i = 0; i < n; i++)
        //db2(a[i].pre, a[i].cyc);
    for (int len = 1; len <= n; len++) {
        vector<int> tmp;
        for (int i = 0; i < n; i++)
            if (a[i].pre == 0 && a[i].cyc == len) {
                tmp.pb(i);
            }
        if (tmp.size() % len != 0) return 0;
        assert(tmp.size() % len == 0);
        //db(tmp.size());
        for (int i = 0; i < (int)tmp.size(); i++) {
            answer[tmp[i]] = tmp[i - i % len + (i + 1) % len];
        }
    }
    for (int i = 0; i < n; i++)
        who[a[i].pre][a[i].cyc] = i;

    for (int i = 0; i < n; i++)
        if (a[i].pre != 0) {
            answer[i] = who[a[i].pre - 1][a[i].cyc];
        }
    //db("ttU");
    return valid2();
}



void rec(int pos) {
    if (!hh.empty()) return;
    //db(pos);
    if (pos == (int)forRec.size()) {
        for (int i = 0; i < n; i++)
            a[i] = aa[i];        

        for (int i = 0; i < (int)forRec.size(); i++) {
            //db(forRec[i].id);
            if (forRec[i].type == 0)
                a[forRec[i].id].pre = val[i];
            else
                a[forRec[i].id].cyc = val[i];
        }
        //db("!!");
        if (build2()) {
            hh.clear();
            //db("in");
            for (int i = 0; i < n; i++)
                hh.pb(answer[i]);
        }
        //db("??");
        return;
    }

    for (int i = forRec[pos].l; i <= forRec[pos].r; i++) {
        val[pos] = i;
        rec(pos + 1);
    }
}

vector<int> stupid() {
    forRec.clear();
    for (int i = 0; i < n; i++) {
        if (aa[i].pre == -1) {
            forRec.pb({0, n - 1, i, 0});
        }
        if (aa[i].cyc == -1) {
            forRec.pb({1, n, i, 1});
        }
    }
    hh.clear();
    //db("AA");
    rec(0);
    //db("BB");
    return hh;
}

void stress() {
    for (int tt = 1334; ; tt++) {
        srand(tt);
        db(tt);
        genTest();
        //printTest();
        auto r1 = solve();
        auto r2 = stupid();
        db2(r1.size(), r2.size());
        if (r1.empty() != r2.empty()) {
            printTest(); 
        }
        assert(r1.size() == r2.size());

    }
}


void printAns(vector<int> A) {
    if (A.empty()) {
        puts("-1");
    }
    else {
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i] + 1);
        }
        puts("");
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