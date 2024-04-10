#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300000;

struct node {
    int an;
    ll ad;
    ll pval;
    ll sval;
    int plen;
    int slen;
    int len;
    bool pinc;
    bool sinc;
    int pan;
    int san;
};

inline node merge(node a, node b) {
    node r;
    r.len = a.len + b.len;
    r.ad = 0;
    r.pval = a.pval;
    r.sval = b.sval;
    r.plen = a.plen;
    r.slen = b.slen;
    r.pinc = a.pinc;
    r.sinc = b.sinc;
    if(a.len == 1 && a.sval > b.pval) {
        a.pinc = a.sinc = r.pinc = false;
    }
    if(b.len == 1 && a.sval > b.pval) {
        b.pinc = b.sinc = r.sinc = false;
    }
    if(a.plen == a.len) {
        if(a.pinc) {
            if(a.sval < b.pval) {
                if(b.pinc) {
                    r.plen += b.plen;
                } else {
                    r.plen++;
                }
            }
        } else {
            if(a.sval > b.pval) {
                if(b.pinc) {
                    r.plen++;
                } else {
                    r.plen += b.plen;
                }
            }
        }
    }
    if(b.slen == b.len) {
        if(b.sinc) {
            if(a.sval < b.pval) {
                if(a.sinc) {
                    r.slen += a.slen;
                } else {
                    r.slen++;
                }
            }
        } else {
            if(a.sval > b.pval) {
                if(a.sinc) {
                    r.slen++;
                } else {
                    r.slen += a.slen;
                }
            }
        }
    }
    r.an = max(a.an, b.an);
    // TODO
    if(a.sval < b.pval) {
        if(a.sinc) {
            r.an = max(r.an, a.slen + b.pan);
        } else {
            r.an = max(r.an, 1 + b.pan);
        }
    } else if(a.sval > b.pval) {
        if(b.pinc) {
            r.an = max(r.an, a.san + 1);
        } else {
            r.an = max(r.an, a.san + b.plen);
        }
    }
    // TODO
    r.pan = a.pan;
    r.san = b.san;
    if(a.pan == a.len) {
        if(a.sinc) {
            if(a.sval < b.pval) {
                r.pan += b.pan;
            } else if(a.sval > b.pval) {
                if(b.pinc) {
                    r.pan++;
                } else {
                    r.pan += b.plen;
                }
            }
        } else {
            if(a.sval > b.pval) {
                if(b.pinc) {
                    r.pan++;
                } else {
                    r.pan += b.plen;
                }
            }
        }
    }
    if(b.san == b.len) {
        if(!b.pinc) {
            if(a.sval > b.pval) {
                r.san += a.san;
            } else if(a.sval < b.pval) {
                if(a.sinc) {
                    r.san += a.slen;
                } else {
                    r.san++;
                }
            }
        } else {
            if(a.sval < b.pval) {
                if(a.sinc) {
                    r.san += a.slen;
                } else {
                    r.san++;
                }
            }
        }
    }
    return r;
}

int a[MAXN];
node rmq[4 * MAXN];

inline void create_rmq(int v, int lf, int rg) {
    if(lf == rg) {
        rmq[v].an = rmq[v].len = 1;
        rmq[v].ad = 0;
        rmq[v].pinc = rmq[v].sinc = true;
        rmq[v].plen = rmq[v].slen = 1;
        rmq[v].pval = rmq[v].sval = a[lf];
        rmq[v].pan = rmq[v].san = 1;
        return;
    }
    int md = (lf + rg) >> 1;
    create_rmq(v * 2 + 1, lf, md);
    create_rmq(v * 2 + 2, md + 1, rg);
    rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void modify_rmq(int v, int lf, int rg, int l, int r, int val) {
    if(r < lf || rg < l) {
        return;
    }
    if(l <= lf && rg <= r) {
        rmq[v].ad += val;
        rmq[v].pval += val;
        rmq[v].sval += val;
        return;
    }
    if(rmq[v].ad) {
        rmq[v * 2 + 1].ad += rmq[v].ad;
        rmq[v * 2 + 1].pval += rmq[v].ad;
        rmq[v * 2 + 1].sval += rmq[v].ad;
        rmq[v * 2 + 2].ad += rmq[v].ad;
        rmq[v * 2 + 2].pval += rmq[v].ad;
        rmq[v * 2 + 2].sval += rmq[v].ad;
        rmq[v].ad = 0;
    }
    int md = (lf + rg) >> 1;
    modify_rmq(v * 2 + 1, lf, md, l, r, val);
    modify_rmq(v * 2 + 2, md + 1, rg, l, r, val);
    rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void print_rmq(int v, int lf, int rg) {
    if(lf < rg) {
        if(rmq[v].ad) {
            rmq[v * 2 + 1].ad += rmq[v].ad;
            rmq[v * 2 + 1].pval += rmq[v].ad;
            rmq[v * 2 + 1].sval += rmq[v].ad;
            rmq[v * 2 + 2].ad += rmq[v].ad;
            rmq[v * 2 + 2].pval += rmq[v].ad;
            rmq[v * 2 + 2].sval += rmq[v].ad;
            rmq[v].ad = 0;
        }
        int md = (lf + rg) >> 1;
        print_rmq(v * 2 + 1, lf, md);
        print_rmq(v * 2 + 2, md + 1, rg);
    }
    cout << lf << ' ' << rg << "\n";
    cout << rmq[v].an << ' ' << rmq[v].ad << ' ' << rmq[v].pval << ' ' << rmq[v].sval << ' ' << rmq[v].plen
     << ' ' << rmq[v].slen << ' ' << rmq[v].len << ' ' << rmq[v].pinc << ' ' << rmq[v].sinc << ' ' << rmq[v].pan
      << ' ' << rmq[v].san << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    create_rmq(0, 0, n - 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        --l; --r;
        modify_rmq(0, 0, n - 1, l, r, d);
        cout << rmq[0].an << "\n";
    }
    //print_rmq(0, 0, n - 1);
}