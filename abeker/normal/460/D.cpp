#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll l, r;
int K;

void load() {
    cin >> l >> r >> K;
}

vector <ll> curr, best;

ll eval(const vector <ll> &V) {
    ll res = 0;
    for (int i = 0; i < V.size(); i++)
        res ^= V[i];
    return res;
}

void brute(ll pos = l) {
    if (curr.size() > K) return;
    if (pos > r) {
        if (!curr.empty() && eval(curr) < eval(best))
            best = curr;
        return;
    }
    brute(pos + 1);
    curr.push_back(pos);
    brute(pos + 1); 
    curr.pop_back();
}

void put(ll x) {
    best.clear();
    l += l % 2;
    for (ll i = 0; i < x; i++) 
        best.push_back(l + i);
}

int get(ll x) {
    for (int i = 40; i >= 0; i--) 
        if ((x >> i) & 1) return i;
    return -1;
}

void solve() {
    best.push_back((ll)1e12);
    if (r < 10) { brute(); return; }
    if (K == 1) { best.clear(); best.push_back(l); return; }
    if (K == 2) {
        if (r - l == 1) brute();
        else put(2);
        return;
    }
    if (K > 3) {
        if (r - l == 3) brute();
        else put(4);
        return;
    }
    best.clear();
    int pl = get(l);
    int pr = get(r);
    if (pr == pl) { put(2); return; }
    if (pr - pl > 1) {
        ll a = 1ll << pr - 1, b = 1ll << pr - 1, c = (1ll << pr - 1) - 1;
        for (ll i = (ll)pr - 2; i >= 0; i--) 
            if (i & 1) a |= (1ll << i);
            else b |= (1ll << i);
        best.push_back(a);
        best.push_back(b);
        best.push_back(c); 
        return;
    }
    if (!((r >> pr - 1) & 1)) { put(2); return; }
    best.push_back(l);
    best.push_back(r);
    best.push_back(l ^ r);
}

void output() {
    cout << eval(best) << endl << best.size() << endl;
    for (int i = 0; i < best.size(); i++)
        cout << best[i] << ' ';
    cout << endl;
}

int main() {
    load();
    solve();
    output();
    return 0;
}