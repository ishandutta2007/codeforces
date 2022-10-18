#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define link aldada

struct eertree {
    static constexpr int maxn = 1e6 + 42, sigma = 26, logn = 21;
    int len[maxn], link[maxn][sigma], tlink[maxn];
    int to[maxn][sigma];
    int up[maxn][logn];
    char s[maxn];
    int in[maxn], out[maxn];
    vector<int> rlink[maxn];
    int sz, last, n;
    int total;

    vector<int> states;

    void Init() {
        fill(link[0], link[0] + sigma, 1);
        rlink[1].push_back(0);
        len[1] = -1;
        s[n++] = -1;
        sz = 2;
    }

    void Push(char c) {
        s[n++] = c -= 'a';
        if(s[n - 1] != s[n - len[last] - 2]) {
            last = link[last][c];
        }
        if(!to[last][c])
        {
            int u = to[link[last][c]][c];
            memcpy(link[sz], link[u], sizeof(link[sz]));
            link[sz][s[n - len[u] - 1]] = u;
            tlink[sz] = u;
            rlink[u].push_back(sz);
            len[sz] = len[last] + 2;
            up[sz][0] = u;
            for(int i = 1; i < logn; i++) {
                up[sz][i] = up[up[sz][i - 1]][i - 1];
            }
            to[last][c] = sz++;
        }
        last = to[last][c];
    }

    int tim = 0;

    void dfs(int v) {
        in[v] = tim++;
        for(auto u: rlink[v]) {
            dfs(u);
        }
        out[in[v]] = tim;
    }

    int sum[maxn];

    int upd(int x, int c) {
        x++;
        int check = 0;
        for(int y = out[x - 1]; y > 0; y -= y & -y) {
            check += sum[y];
        }
        for(int y = x - 1; y > 0; y -= y & -y) {
            check -= sum[y];
        }
        for(; x < maxn; x += x & -x) {
            sum[x] += c;
        }
        return check + c == 0 ? -1 : check + c == 1 && check == 0 ? 1 : 0;
    }

    int la(int v, int k) {
        for(int i = logn - 1; i >= 0; i--) {
            if(len[up[v][i]] > k) {
                v = up[v][i];
            }
        }
        return len[v] > k ? up[v][0] : v;
    }
} me;

int dist_brute(string s) {
    unordered_set<string> pals;
    for(size_t i = 0; i < s.size(); i++) {
        for(size_t j = 1; i + j <= s.size(); j++) {
            auto t = s.substr(i, j);
            if(t == string(t.rbegin(), t.rend())) {
                pals.insert(t);
            }
        }
    }
    return pals.size();
}

bool RAND = false;

void solve() {
    me.Init();
    string S;
    int N;
    N = 10;
    if(!RAND) {
        cin >> N;
    } else {
        cout << N << "\n";
    }
    string tp[N];
    char c[N];
    vector<int> max_sf;
    int ln = 0;
    for(int i = 0; i < N; i++) {
        if(!RAND) {
            cin >> tp[i];
        } else {
            tp[i] = ln == 0 ? "push" : rand() % 2 ? "push" : "pop";
            cout << tp[i] << " ";
        }
        if(tp[i] == "push") {
            if(!RAND) {
                cin >> c[i];
            } else {
                c[i] = rand() % 3 + 'a';
                cout << c[i] << "\n";
            }
            //c[i] -= 'a';
            me.Push(c[i]);
            S += c[i];
            max_sf.push_back(me.last);
            ln++;
        } else {
            ln--;
            if(RAND) {
                cout << "\n";
            }
        }
    }
    cout.flush();
    me.dfs(1);
    vector<int> max_pr;
    ranges::reverse(S);
    me.last = 0;
    me.n = 1;
    for(auto c: S) {
        me.Push(c);
        max_pr.push_back(me.last);
    }
    ranges::reverse(max_pr);
    ranges::reverse(S);
    int L = 0, R = 0;
    me.last = 0;
    me.n = 1;
    int cur = 0;
    int head_L = 0, head_R = 0;
    for(int i = 0; i < N; i++) {
        if(tp[i] == "push") {
            me.last = head_R;
            me.Push(c[i]);
            head_R = me.last;
            R++;
            while(me.len[head_R] > R - L) {
                head_R = me.tlink[head_R];
            }
            assert(me.len[head_R] <= R - L);
            if(me.len[head_R] == R - L) {
                head_L = head_R;
            }
            cur += me.upd(me.in[head_R], +1);
        } else {
            cur += me.upd(me.in[head_L], -1);
            if(me.len[head_R] == R - L) {
                head_R = me.tlink[head_R];
            }
            L++;
            head_L = me.la(max_pr[L], R - L);
            assert(head_L || R == L);
        }
        if(RAND) {
            string T = S.substr(L, R - L);
            int check = dist_brute(T);
            cout << T << ' ' << cur << ' ' << check << endl;
            assert(cur == check);
        }
        cout << cur << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    RAND = false;
    //t = 10000;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}