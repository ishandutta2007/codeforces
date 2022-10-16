#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N, M;

struct Event {
    int x;
    int t;
    bool type; // 0 = insert, 1 = erase

    Event(int _x = 0, int _t = 0, bool _type = 0):
        x(_x), t(_t), type(_type) {}

    friend bool operator<(const Event &a, const Event &b) {
        return make_pair(a.x, a.t) < make_pair(b.x, b.t);
    }
};

vector <Event> events;

pair <int, int> q[NMAX];
int ans[NMAX];
int anss[NMAX];

typedef long long int lint;
lint marsVal[NMAX];
lint marsNr[NMAX];

int maxAtMost(int val) {
    int st = 1, dr = N;
    int ans = 0;
    while (st <= dr) {
        const int mid = (st + dr) / 2;
        if (q[mid].first <= val) {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }
    return ans;
}

void addVal(int l, int r, lint v) {
    l = max(l, 1);
    r = min(r, N);
    if (l <= r) {
        marsVal[l] += v;
        marsVal[r + 1] -= v;
    }
}

void addNr(int l, int r) {
    l = max(l, 1);
    r = min(r, N);
    if (l <= r) {
        ++ marsNr[l];
        -- marsNr[r + 1];
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    while (M --) {
        int l, r, t;
        cin >> l >> r >> t;
        events.push_back(Event(l, t, 0));
        events.push_back(Event(r, t, 1));
    }
    sort(events.begin(), events.end());

    for (int i = 1; i <= N; ++ i) {
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(q + 1, q + N + 1);

    multiset <int> Set;
    for (int i = 0; i < events.size(); ++ i) {
        const bool &type = events[i].type;
        const int &x = events[i].x;
        const int &t = events[i].t;

        if (type == 0)
            Set.insert(t);
        else
            Set.erase(Set.find(t));

        if (i + 1 == events.size() || events[i + 1].x > events[i].x) {
            if (!Set.empty()) {
                int T = *Set.begin();
                int l = x;
                int r = events[i + 1].x;

                int i1 = maxAtMost(T - r - 1);
                int i2 = maxAtMost(T - l - 1);

                addVal(i1 + 1, i2, 1LL * r - T);
                addNr(i1 + 1, i2);
                addVal(i2 + 1, N, r - l);
            }
        }
    }

    for (int i = 1; i <= N; ++ i) {
        marsVal[i] += marsVal[i - 1];
        marsNr[i] += marsNr[i - 1];
        ans[i] = marsVal[i] + 1LL * q[i].first * marsNr[i];
        anss[q[i].second] = ans[i];
    }

    for (int i = 1; i <= N; ++ i)
        cout << anss[i] << '\n';
    return 0;
}