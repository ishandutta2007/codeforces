#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

#define x first
#define y second

struct Node{
    int v, u, w;
};

int dst(pii a, pii b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector <int> p;

int get(int v) {
    if (p[v] == -1)
        return v;
    return p[v] = get(p[v]);
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> cords(n);
    forn (i, 0, n)
        cin >> cords[i].x >> cords[i].y;
    vector <int> k(n);
    int sum = 0;
    forn (i, 0, n) {
        cin >> k[i];
        sum += k[i];
    }
    vector <int> cost(n);
    forn (i, 0, n)
        cin >> cost[i];
    vector <Node> edges;
    forn (i, 0, n) 
        forn (j, i + 1, n) {
            //cout << i << " " << j << ": " << (cost[i] + cost[j]) * dst(cords[i], cords[j]) << "\n";
            edges.pb({i, j, (cost[i] + cost[j]) * dst(cords[i], cords[j])});
        }
    sort(all(edges), [](Node a, Node b) {return a.w < b.w;});
    p.resize(n);
    forn (i, 0, n)
        p[i] = -1;
    vector <pii> ans;
    for (auto i : edges) {
        if (get(i.v) != get(i.u) && max(k[get(i.v)], k[get(i.u)]) > i.w) {
            if (k[get(i.v)] > k[get(i.u)])
                swap(i.v, i.u);
            sum -= k[get(i.u)] - i.w;
            p[get(i.u)] = get(i.v);
            ans.eb(i.v, i.u);
        }
        /*forn (j, 0, n)
            cout << p[j] << " ";
        cout << "\n";
        cout << sum << "\n";*/
    }
    cout << sum << "\n";
    set <int> stations;
    forn (i, 0, n) {
        stations.insert(get(i));
    }
    cout << stations.size() << "\n";
    for (int i : stations)
        cout << i + 1 << " ";
    cout << "\n";
    cout << ans.size() << "\n";
    for (pii i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
    return 0;
}