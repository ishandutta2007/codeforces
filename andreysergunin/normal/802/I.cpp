#include <bits/stdc++.h>
#include <thread>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct node
{
    int len;
    int link;
    map<char, int> to;
    int cnt;
    node() : len(0), link(-1), cnt(0) {}
};

vector<node> t;
int last;

void add(char c)
{
    int curr = sz(t);
    t.pb(node());
    ++t[curr].cnt;
    t[curr].len = t[last].len + 1;
    int p = last;
    while (p != -1 && !t[p].to.count(c)) {
        t[p].to[c] = curr;
        p = t[p].link;
    }
    if (p == -1) {
        t[curr].link = 0;
        last = curr;
        return;
    }
    int q = t[p].to[c];
    if (t[q].len == t[p].len + 1) {
        t[curr].link = q;
        last = curr;
        return;
    }
    int clone = sz(t);
    t.pb(node());
    t[clone].link = t[q].link;
    t[clone].len = t[p].len + 1;
    t[clone].to = t[q].to;
    while (true) {
        if (p != -1 && t[p].to.count(c) && t[p].to[c] == q) {
            t[p].to[c] = clone;
            p = t[p].link;
        } else {
            break;
        }
    }
    t[q].link = t[curr].link = clone;
    last = curr;
}

/*void dfs(int v)
{
    for (auto it : t[v].to) {
        dfs(it.second);
    }
    if (v) {
        t[t[v].link].cnt += t[v].cnt;
    }
}*/

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        t.clear();
        last = 0;
        t.pb(node());
        string s;
        cin >> s;
        for (int i = 0; i < sz(s); ++i) {
            add(s[i]);
        }
        //dfs(0);
        vector<int> ord;
        for (int v = 1; v < sz(t); ++v) {
            ord.pb(v);
        }
        sort(all(ord), [&](int a, int b) { return t[a].len > t[b].len; });
        for (int v : ord) {
            t[t[v].link].cnt += t[v].cnt;
        }
        ll ans = 0;
        for (int v = 1; v < sz(t); ++v) {
            int a = t[t[v].link].len + 1;
            int b = t[v].len;
            //cout << v << " " << a << " " << b << " " << t[v].cnt << "\n";
            ans += ll(t[v].cnt) * ll(t[v].cnt) * ll(b - a + 1);
        }
        cout << ans << "\n";
    }

}