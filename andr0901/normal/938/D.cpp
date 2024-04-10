#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int n;

void dijkstra(vector <vector <pair <int, ll>>>& gr, vector <ll>& dist) {
    set <pair <ll, int>> s; // {dist, v}
    forn (i, 0, n) {
        s.insert({dist[i], i});
    }
    while (!s.empty()) {
        pair <ll, int> v = *s.begin();
        s.erase(s.begin());
        for (pair <int, ll> e : gr[v.sc]) {
            if (dist[e.fs] > dist[v.sc] + e.sc) {
                s.erase({dist[e.fs], e.fs});
                dist[e.fs] = dist[v.sc] + e.sc;
                s.insert({dist[e.fs], e.fs});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> n >> m;
    vector <vector <pair <int, ll>>> gr(n); // {to, weight}
    while (m --> 0) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        t1--, t2--, t3 *= 2;
        gr[t1].push_back({t2, t3});
        gr[t2].push_back({t1, t3});
    }
    vector <ll> dist(n);
    forn (i, 0, n)
        cin >> dist[i];
    dijkstra(gr, dist);
    forn (i, 0, n)
        cout << dist[i] << " ";
    return 0;
}