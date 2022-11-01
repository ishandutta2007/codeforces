#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

void root(int node) {
    cout << "! " << node << endl;
}

vector<int> edges[201];

vector<int> make_query(int node) {
    if (!edges[node].empty()) {
        return edges[node];
    }
    cout << "? " << node << endl;
    int k;
    cin >> k;

    if (k == 0) {
        exit(0);
    } else {
        vector<int> ret(k);
        for (int& p: ret) {
            cin >> p;
        }
        if (k == 2) {
            root(node);
            return {-1};
        }
        edges[node] = ret;
        return ret;
    }
}

int main() {
    #ifdef LOCAL_RUN
    //freopen("task.in", "r", stdin);
    //freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int h;
        cin >> h;
        if (h == 0) {
            exit(0);
        }
        for (int i = 1; i < (1 << h); ++i) {
            edges[i].clear();
        }
        
        vector<int> chain;
        vector<int> l = make_query(1);
        if (l[0] < 0) {
            continue;
        }
        int r = 1, pos;
        if (SZ(l) > 1) {
            chain = {l[0], 1, l[1]};
            while (true) {
                l = make_query(chain.back());
                if (l[0] == -1) {
                    goto NEXT_TEST;
                }
                if (SZ(l) == 1) {
                    break;
                }
                int x;
                if (SZ(chain) > 1 && l[0] == chain[SZ(chain) - 2]) {
                    x = l[1];
                } else {
                    x = l[0];
                }
                chain.push_back(x);
                reverse(chain.begin(), chain.end());
            }
        } else {
            chain = {l[0], 1};
            r = l[0];
        }
        reverse(chain.begin(), chain.end());

        pos = find(chain.begin(), chain.end(), r) - chain.begin();
        while (true) {
            if (pos == 4) {
                l = make_query(chain[pos]);
                if (l[0] == -1) {
                    goto NEXT_TEST;
                }
                vector<int> nxt;
                for (int p: l) {
                    vector<int> r = make_query(p);
                    if (r[0] == -1) {
                        goto NEXT_TEST;
                    }
                    for (int x: r) {
                        if (x != chain[pos]) {
                            nxt.push_back(x);
                        }
                    }
                }
                for (int i = 0; i < SZ(nxt); ++i) {
                    if (edges[nxt[i]].empty()) {
                        swap(nxt[i], nxt.back());
                        break;
                    }
                }
                int w = nxt.back(); nxt.pop_back();
                for (int p: nxt) {
                    l = make_query(p);
                    if (l[0] == -1) {
                        goto NEXT_TEST;
                    }
                }
                root(w);
                goto NEXT_TEST;
            } else if (pos == 5) {
                l = make_query(chain[pos]);
                if (l[0] == -1) {
                    goto NEXT_TEST;
                }
                for (int i = 0; i < SZ(l); ++i) {
                    if (edges[l[i]].empty()) {
                        swap(l[i], l.back());
                        break;
                    }
                }
                int w = l.back();
                l.pop_back();
                for (int p: l) {
                    vector<int> r = make_query(p);
                    if (r[0] == -1) {
                        goto NEXT_TEST;
                    }
                }
                root(w);
                goto NEXT_TEST;
            } else {
                l = make_query(chain.back());
                if (l[0] == -1) {
                    goto NEXT_TEST;
                }
                if (SZ(l) == 1) {
                    int len = SZ(chain) - pos - 1;
                    pos += (len - pos) / 2;
                    l = make_query(chain[pos]);
                    int o = l[0] ^ l[1] ^ l[2] ^ chain[pos - 1] ^ chain[pos + 1];
                    chain.resize(pos + 1);
                    chain.push_back(o);
                    pos++;
                } else {
                    int o = l[0] == chain[SZ(chain) - 2] ? l[1]: l[0];
                    chain.push_back(o);
                }
            }
        }

        NEXT_TEST:;
    }
}