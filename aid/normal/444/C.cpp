#include <iostream>
#include <set>
#include <cmath>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<long long, long long> st[4 * MAXN];
set< pair<int, int> > seg;

void push(int v, int tl, int tm, int tr) {
    if(!st[v].second)
        return;
    st[2 * v].second += st[v].second;
    st[2 * v].first += (long long)(tm - tl) * st[v].second;
    st[2 * v + 1].second += st[v].second;
    st[2 * v + 1].first += (long long)(tr - tm) * st[v].second;
    st[v].second = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
    if(l == tl && r == tr) {
        st[v].second += x;
        st[v].first += (long long)(tr - tl) * x;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tm, tr);
    if(l < tm)
        add(2 * v, tl, tm, l, min(r, tm), x);
    if(r > tm)
        add(2 * v + 1, tm, tr, max(l, tm), r, x);
    st[v].first = st[2 * v].first + st[2 * v + 1].first;
}

long long get(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v].first;
    int tm = (tl + tr) / 2;
    push(v, tl, tm, tr);
    long long res = 0;
    if(l < tm)
        res += get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res += get(2 * v + 1, tm, tr, max(l, tm), r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        seg.insert(make_pair(i, i + 1));
    seg.insert(make_pair(n, 0));
    for(int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if(q == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            set< pair<int, int> >::iterator itl =
                seg.lower_bound(make_pair(l, 0)), itr = itl;
            if(itl->first > l) {
                itl--;
                if(itr->first > r) {
                    add(1, 0, n, l, r, abs(x - itl->second));
                    seg.insert(make_pair(r, itl->second));
                }
                else
                    add(1, 0, n, l, itr->first, abs(x - itl->second));
                itl++;
            }
            itr++;
            while(itr != seg.end() && itr->first <= r) {
                add(1, 0, n, itl->first, itr->first, abs(x - itl->second));
                seg.erase(itl);
                itl = itr;
                itr++;
            }
            if(itl->first < r) {
                add(1, 0, n, itl->first, r, abs(x - itl->second));
                seg.insert(make_pair(r, itl->second));
                seg.erase(itl);
            }
            seg.insert(make_pair(l, x));
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << get(1, 0, n, l, r) << '\n';
        }
    }
    return 0;
}