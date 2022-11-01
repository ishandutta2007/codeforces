#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 2e5 + 10;
const int M = (1 << 20) + 1;
const ll INF = 1e9 + 1;

pii gas[N];
ll dp[N];
int x[N], p[N];

struct Event {
    int x;
    int cost;
    int num;
    int typ;
};

bool cmp(const Event& a, const Event& b) {
    if (a.x != b.x)
        return a.x < b.x;
    if (a.typ != b.typ)
        return a.typ > b.typ;
    return a.cost < b.cost;
}

void solve() {
    int d, n, m;
    cin >> d >> n >> m;

    vector<Event> events = {{0, 0, -1, 0}, {n, 0, -1, 1}};
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> p[i];
        events.pb({x[i], p[i], i, 0});
        events.pb({x[i] + n, p[i], i, 1});
    }

    sort(events.begin(), events.end(), cmp);

    set<pair<int, int> > s;

    vector<pair<ll, ll> > sl;

    for (int i = 0; i < events.size(); i++) {
        if (events[i].typ == 0) {
            s.insert({events[i].cost, events[i].num});
        }
        if (events[i].typ == 1) {
            s.erase({events[i].cost, events[i].num});
        }
        if (!s.size())
            sl.pb({INF, events[i].x});
        else
            sl.pb({s.begin()->first, events[i].x});
        if (events[i].x >= d) {
            sl.back().second = d;
            break;
        }
    }

    if (sl.back().second != d) {
        cout << -1;
        return;
    }

//    for (int i = 0; i < sl.size(); i++)
//        cout << sl[i].first << " " << sl[i].second << endl;
//    cout << endl;

    ll ans = 0;
    for (int i = 0; i + 1 < sl.size(); i++) {
        ans += (sl[i + 1].second - sl[i].second) * sl[i].first;
        if (sl[i].first == INF && (sl[i + 1].second - sl[i].second)) {
            cout << -1;
            return;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);

    solve();

}