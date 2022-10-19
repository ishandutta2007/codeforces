#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

struct node {
    map <char, int> nxt;
    int suf = -1, ssuf = -1, pr = -1;
    char c;
    int term = 0;
};

vector <node> all;

inline int add(const string& s) {
    int now = 0;
    for (char c : s) {
        if (all[now].nxt.count(c)) {
            now = all[now].nxt[c];
        } else {
            int nxt = (int)all.size();
            all.emplace_back();
            all[nxt].c = c;
            all[nxt].pr = now;
            all[now].nxt[c] = nxt;
            now = nxt;
        }
    }
    all[now].term++;
    return now;
}

int get_suf(int v);

int get_nxt(int v, char c) {
    if (all[v].nxt.count(c)) return all[v].nxt[c];
    if (v == 0) all[v].nxt[c] = 0;
    else all[v].nxt[c] = get_nxt(get_suf(v), c);
    return all[v].nxt[c];
}

int get_suf(int v) {
    if (all[v].suf != -1) return all[v].suf;
    if (v == 0 || all[v].pr == 0) all[v].suf = 0;
    else all[v].suf = get_nxt(get_suf(all[v].pr), all[v].c);
    return all[v].suf;
}

int get_ssuf(int v) {
    if (all[v].ssuf != -1) return all[v].ssuf;
    if (v == 0 || all[v].pr == 0) all[v].ssuf = 0;
    else if (all[get_suf(v)].term) all[v].ssuf = get_suf(v);
    else all[v].ssuf = get_ssuf(get_suf(v));
    return all[v].ssuf;
}

int main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    all.emplace_back();
    vector <int> ind(n), cha(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ind[i] = add(s);
    }
    multiset <int> val[(int)all.size()];
    for (int i = 0; i < (int)all.size(); ++i) {
        for (int j = 0; j < all[i].term; ++j) {
            val[i].insert(0);
        }
    }
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x; --i;
            val[ind[i]].erase(val[ind[i]].find(cha[i]));
            cha[i] = x;
            val[ind[i]].insert(x);
        } else {
            int mx = -1, r = 0;
            cin >> s;
            for (char c : s) {
                r = get_nxt(r, c);
                int tmp = r;
                while (tmp > 0) {
                    if (all[tmp].term) {
                        mx = max(mx, *val[tmp].rbegin());
                    }
                    tmp = get_ssuf(tmp);
                }
            }
            cout << mx << "\n";
        }
    }
}