#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = 200 + 7;

int to[MAXN][26];
int link[MAXN];
int ch[MAXN];
int pr[MAXN];
ll val[MAXN];
char str[MAXN];
bool leaf[MAXN];
int sz = 1;
vector <int> x;

void add(string s, int x) {
    int v = 0;
    for (char p : s) {
        int c = p - 'a';
        if (!to[v][c]) {
            to[v][c] = sz++;
        }
        ch[to[v][c]] = c;
        pr[to[v][c]] = v;
        v = to[v][c];
    }
    val[v] += x;
}

void links() {
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        x.pb(v);
        q.pop();
        for (int c = 0; c < 26; c++) {
            if (to[v][c]) {
                q.push(to[v][c]);
            }
        }
        if (pr[v] == 0) {
            link[v] = 0;
        } else {
            int cur = link[pr[v]];
            int c = ch[v];
            while (cur != 0 && !to[cur][c]) {
                cur = link[cur];
            }
            if (to[cur][c]) {
                link[v] = to[cur][c];
            } else {
                link[v] = 0;
            }
        }
    }
}

void back() { //VERNITE MOI 2007
    for (auto v : x) {
        val[v] += val[link[v]];
        for (int c = 0; c < 26; c++) {
            to[v][c] = (to[v][c] ? to[v][c] : to[link[v]][c]);
        }
    }
}

string next() {
    scanf(" %s", str);
    //cout << "VODKA " << string(str) << endl;
    return string(str);
}

vector <vector <ll> > mul(const vector <vector <ll> > &a, const vector <vector <ll> > &b) {
    int n = a.size();
    vector <vector <ll> > res = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] != -1 && b[k][j] != -1) {
                    res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
    return res;
}

vector <vector <ll> > pw(const vector <vector <ll> > &a, ll n) {
    if (n == 1) {
        return a;
    } else if (n & 1) {
        return mul(a, pw(a, n - 1));
    } else {
        auto t = pw(a, n >> 1);
        return mul(t, t);
    }
}

int main() {
    int n;
    ll l;
    scanf("%d %lld", &n, &l);
    vector <int> a(n);
    for (auto &c : a) {
        scanf("%d", &c);
    }
    for (auto c : a) {
        add(next(), c); 
    }
    links();
    back();
    vector <vector <ll> > d(sz, vector <ll> (sz, -1));
    for (int i = 0; i < sz; i++) {
        for (int c = 0; c < 26; c++) {
            d[i][to[i][c]] = max(d[i][to[i][c]], val[to[i][c]]);
        }
    }
    /*
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            printf("%lld ", d[i][j]);
        }
        puts("");
    }
    */
    d = pw(d, l);    
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
        ans = max(ans, d[0][i]);
    }
    printf("%lld\n", ans);
}