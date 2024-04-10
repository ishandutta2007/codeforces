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
const int N = 2222;
const long long INF = 1e9 + 19;

struct Var {
    int id;
    bool flag;
    Var(int x) {
        flag = x > 0;
        id = abs(x) - 1;
    }
};


struct Graph {
    vector < vector < int > > e;
    vector < vector < int > > er;
    vector < vector < int > > g;
    vector < char > use;
    vector < int > st;
    vector < int > color;
    vector < bitset < N > > bb;
    vector < bitset < N > > realbb;
    vector < bitset < N > > invbb;
    vector < vector < int > > who;
    vector < int > bad;
    vector < int > answer;
    int n;
    Graph(vector < pair < Var, Var > > eq, int n): n(n) {
        e.resize(n * 2);
        er.resize(n * 2);
        for (auto x: eq) {
            Var v = x.fr;
            Var u = x.sc;
            v.flag ^= 1;
            e[getId(v)].pb(getId(u));
            er[getId(u)].pb(getId(v));
            v.flag ^= 1;
            u.flag ^= 1;
            e[getId(u)].pb(getId(v));
            er[getId(v)].pb(getId(u));
        }
        use.resize(n * 2);
        for (int i = 0; i < n * 2; i++)
            if (!use[i])
                dfs1(i);
        reverse(st.begin(), st.end());
        color.resize(n * 2, -1);
        int cc = 0;
        for (int i = 0; i < n * 2; i++) {
            int v = st[i];
            if (color[v] == -1) {
                who.pb(vector < int >());
                dfs2(v, cc);
                cc++;
            }
        }
        g.resize(cc);
        for (int i = 0; i < n * 2; i++)
            for (auto u: e[i]) {
                if (color[i] != color[u])
                    g[color[i]].pb(color[u]);
            }
        bb.resize(cc);

        use.assign(n * 2, 0);

        for (int i = 0; i < cc; i++)
            if (!use[i])
                dfs3(i);

        realbb.resize(n * 2);
        invbb.resize(n * 2);
        for (int i = 0; i < cc; i++) {
            for (auto v: who[i])
                for (int j = 0; j < cc; j++)
                    if (bb[i][j])
                        for (auto u: who[j]) {
                            realbb[v][u] = 1;
                            int id = (u + n) % (2 * n);
                            invbb[v][id] = 1;
                        }
        }
        bad.resize(n * 2);
        for (int i = 0; i < n * 2; i++)
            for (int j = 0; j < n; j++) {
                if (realbb[i][j] && realbb[i][j + n]) {
                   bad[i] = 1; 
                   break;
                }
            }
        for (int i = 0; i < n; i++) {
            if (color[i] == color[i + n]) {
                answer.clear();
                break;
            }
            if (color[i] < color[i + n])
                answer.pb(1);
            else
                answer.pb(0);
        } 


        //for (int i = 0; i < n * 2; i++) {
            //int par = i + n;
            //if (par >= n * 2) par -= n * 2;
            
            //if (bb[color[i]][color[par]]) {
                //dfs4(i);
            //} 
        //}

    }

    void dfs3(int v) {
        use[v] = 1;
        bb[v][v] = 1;
        for (auto u: g[v]) {
            if (!use[u])
                dfs3(u);
            bb[v] |= bb[u];
        }
    }

    void dfs2(int v, int cc) {
        color[v] = cc;
        who.back().pb(v);
        for (auto u: er[v])
            if (color[u] == -1)
                dfs2(u, cc);
    }

    void dfs1(int v) {
        use[v] = 1;
        for (auto u: e[v])
            if (!use[u])
                dfs1(u);
        st.pb(v);
    }

    int getId(Var v) {
        return v.id + v.flag * n;
    }

};

int n, m1, m2;
vector < pair < Var, Var > > e1;
vector < pair < Var, Var > > e2;

int getId(Var v) {
    return v.id + v.flag * n;
}

void read() {
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 0; i < m1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        e1.pb(mp(Var(v), Var(u)));
    }
    for (int i = 0; i < m2; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        e2.pb(mp(Var(v), Var(u)));
    }
}


void solve() {
    //db2(e1.size(), e2.size());
    //swap(e1, e2);
    for (int tt = 0; tt < 2; tt++) {
        //Graph g1(e1, n);        
        Graph g2(e2, n);
        //cerr << endl;
        //db(tt);
        if (g2.answer.empty()) {
            swap(e1, e2);
            continue;
        }

        //for (auto x: g2.answer)
            //cerr << x << " ";
        //cerr << endl;

        //for (int i = 0; i < n * 2; i++)
            //cerr << g1.bad[i] << " ";
        //cerr << endl;

        //db(e1.size());
        for (int i = 0; i < (int)e1.size(); i++) {
            int A = (getId(e1[i].fr) + n) % (2 * n);
            int B = (getId(e1[i].sc) + n) % (2 * n);
            //db2(A, B);
            if (g2.bad[A] || g2.bad[B]) {
                continue;
            }
            if ((g2.invbb[A] & g2.realbb[B]).any())
                continue;
            if ((g2.invbb[B] & g2.realbb[A]).any())
                continue;

            vector < int > answer = g2.answer;

            for (int i = 0; i < n * 2; i++) {
                if (g2.realbb[A][i]) {
                    int id = i % n;
                    int val = i / n;
                    //db2(id, val);
                    answer[id] = val;
                }
            }

            for (int i = 0; i < n * 2; i++) {
                if (g2.realbb[B][i]) {
                    int id = i % n;
                    int val = i / n;
                    //db2(id, val);
                    answer[id] = val;
                }
            }


            //db(tt);

            for (int i = 0; i < n; i++)
                printf("%d ", answer[i]);
            puts("");
            exit(0);
        }

        swap(e1, e2);
    }
    puts("SIMILAR");
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
        }
    }
    else {
        stress();
    }

    return 0;
}