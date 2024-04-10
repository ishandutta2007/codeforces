#include <bits/stdc++.h>

using namespace std;

#define A 0
#define P 1
#define mp make_pair
#define f first
#define s second
#define M 100100

struct event {
    int type;
    int id;
    int l, r;
    int k;

    bool operator < (const event &to) const {
        if (l != to.l)
            return l < to.l;
        if (type != to.type)
            return type < to.type;
        return id < to.id;
    }


};

vector<event> e;
int n, m;
int ans[M];
set<pair<pair<int, int>, int>> s;

void read() {
    cin >> n;
    for (int i = 0, l, r; i < n; ++i) {
        cin >> l >> r;
        event x;

        x.type = P;
        x.id = i;
        x.l = l;
        x.r = r;

        e.push_back(x);
    }

    cin >> m;
    for (int i = 0, l, r, k; i < m; ++i) {
        cin >> l >> r >> k;
        event x;

        x.type = A;
        x.id = i;
        x.l = l;
        x.r = r;
        x.k = k;

        e.push_back(x);
    }

    sort(e.begin(), e.end());
}

void add(int r, int k, int id) {
    s.insert(mp(mp(r, k), id));
    //cerr << "ADD " << id << "\n";
}

bool get(int r, int id) {
    //cerr << "GET " << id << "\n";
    auto it = s.lower_bound(mp(mp(r, -1), -1));
    if (it == s.end())
        return false;

    auto x = *it;
    s.erase(it);
    ans[id] = x.s;
    x.f.s--;
    if (x.f.s > 0)
        s.insert(x);

    return true;
}

void kill() {
    bool pos = true;
    for (auto &x : e) {
        if (x.type == A) {
            add(x.r, x.k, x.id);
        }

        if (x.type == P) {
            pos &= get(x.r, x.id);
        }

        if (!pos)
            break;
    }

    if (!pos) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    read();

    kill();

    return 0;
}