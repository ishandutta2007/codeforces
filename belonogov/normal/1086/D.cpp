#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

struct Tree {
    struct State {
        int c[3][3];
        bool flag2;
        bool flag0;
        State() {
            memset(c, 0, sizeof(c));
            flag2 = 0;
            flag0 = 0;
        }
    };
    vector<State> st;
    void init(int n) {
        st.resize(n*4);
    }

    void set(int v, int tl, int tr, int pos, int val) {
        if (tl + 1 == tr) {
            assert(pos == tl);
            st[v] = State();
            if (val == 1) st[v].c[0][0] = 1;
            if (val == 0) st[v].flag0 = 1;
            if (val == 2) st[v].flag2 = 1;
            return;
        }
        if (pos < (tl + tr) / 2) {
            set(v * 2 + 1, tl, (tl + tr) / 2, pos, val);
        }
        else {
            set(v * 2 + 2, (tl + tr) / 2, tr, pos, val);
        }

        st[v] = State();
        auto L = st[v * 2 + 1];
        auto R = st[v * 2 + 2];
        st[v].flag0 = L.flag0 || R.flag0;
        st[v].flag2 = L.flag2 || R.flag2;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nj = j;
                if (R.flag0) nj = max(nj, 2);
                if (R.flag2) nj = max(nj, 1);

                st[v].c[i][nj] += L.c[i][j];


                int ni = i;
                if (L.flag0) ni = max(ni, 2);
                if (L.flag2) ni = max(ni, 1);

                st[v].c[ni][j] += R.c[i][j];
            }
        }

    }
    int get_total() {
        int answer = 0;
        for (int i = 0; i < 3; i += 2) {
            for (int j = 0; j < 3; j += 2) {
                answer += st[0].c[i][j];
            }
        }
        return answer;
    }

};

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, qq;
    scanf("%d%d", &n, &qq);
    string s;
    cin >> s;
    vector<int> a(n);
    map<char,int> q;
    q['R'] = 0;
    q['P'] = 1;
    q['S'] = 2;

    vector<pair<int,int>> query;
    for (int i = 0; i < n; i++) {
        query.pb({i, q[s[i]]});
    }
    for (int i = 0; i < qq; i++) {
        int pos;
        char ch;
        scanf("%d %c", &pos, &ch); pos--;
        query.pb({pos, q[ch]});
    }

    Tree tree[3];
    for (int i = 0; i < 3; i++) {
        tree[i].init(n);
    }

    for (int i = 0; i < sz(query); i++) {
        for (int j = 0; j < 3; j++) {
            int val = (query[i].S + 1 - j + 3) % 3;
            tree[j].set(0, 0, n, query[i].F, val);
        }
        if (i >= n - 1) {
            int answer = 0;
            for (int j = 0; j < 3; j++) {
                answer += tree[j].get_total();
            }
            printf("%d\n", answer);
        }
    }

    return 0;
}