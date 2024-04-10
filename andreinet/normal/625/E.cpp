#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
#define WRITE(x) (cerr << #x << ": " << (x) << endl)
using namespace std;

typedef long long i64;
const int NMAX = 100005;
const int64_t INF = 1LL << 62;

struct Time {
    int64_t rounds;
    int turn;
    Time() {}
    Time(int64_t _rounds, int _turn):
        rounds(_rounds), turn(_turn) {}

    bool operator< (const Time& other) const {
        return rounds < other.rounds ||
               (rounds == other.rounds && turn < other.turn);
    }
    bool operator== (const Time& other) const {
        return rounds == other.rounds && turn == other.turn;
    }
};

int speeds[NMAX];
int initp[NMAX];
int positions[NMAX];
Time lastUpdated[NMAX];
Time eraseTime[NMAX];

bool inside(int x, int left, int right) {
    if (left <= right) {
        return left <= x && x <= right;
    } else {
        return left <= x || x <= right;
    }
}

int getDist(int p1, int p2, int m) {
    if (p1 <= p2) {
        return p2 - p1;
    } else {
        return m - p1 + p2;
    }
}

int64_t getMoves(int n, int i, Time time) {
    if (time.rounds < 0) return 0;
    return (time.rounds + (time.turn >= i));
}

void updatePos(int n, int m, int i, Time time) {
    Time l = lastUpdated[i];
    positions[i] = (positions[i] + (int64_t) speeds[i] *
                   ((getMoves(n, i, time) - getMoves(n, i, l)) % m)) % m;
    lastUpdated[i] = time;
}

Time getTime(Time time, int n, int m, int ind1, int ind2) {
    updatePos(n, m, ind1, time);
    updatePos(n, m, ind2, time);

    int p1 = positions[ind1];
    int p2 = positions[ind2];

    int64_t t;
    int turn = (time.turn + 1) % n;
    if (turn == 0) time.rounds++;
    int d = getDist(p1, p2, m);

    if (((turn <= ind1 && ind1 < ind2) ||
         (turn > ind2 && ind1 < ind2) ||
         (turn > ind2 && turn <= ind1 && ind1 > ind2))) {
        if (inside(p2, p1, (p1 + speeds[ind1]) % m) || speeds[ind1] == m) {
            t = time.rounds;
        } else if (speeds[ind1] > speeds[ind2]) {
            t = time.rounds + 
                ((d - 1 - speeds[ind1]) /
                (speeds[ind1] - speeds[ind2])) + 1;
        } else {
            t = INF;
        }
    } else if (speeds[ind1] > speeds[ind2]) {
        t = time.rounds + ((d - 1) / (speeds[ind1] - speeds[ind2]));
    } else {
        t = INF;
    }
    if (turn > ind1 && t != INF) ++t;
    return {t, ind1};
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    multiset<pair<int, int>> S;
    multiset<pair<Time, int>> times;

    for (int i = 0; i < n; ++i) {
        int pos, speed;
        cin >> pos >> speed;
        pos--;
        S.insert(make_pair(pos, i));
        speeds[i] = speed;
        lastUpdated[i] = {-1, n - 1};
        positions[i] = pos;
        initp[i] = pos;
    }

    Time time = {-1, n - 1};
    for (auto it = S.begin(); it != S.end(); ++it) {
        auto it1 = it;
        ++it1;
        if (it1 == S.end()) {
            it1 = S.begin();
        }
        int ind1 = it->second, ind2 = it1->second;
        int p1 = it->first, p2 = it1->first;
        Time t = getTime(time, n, m, ind1, ind2);
        times.insert(make_pair(t, ind1));
        eraseTime[ind1] = t;
    }

    while (SZ(S) > 1 && times.begin()->first.rounds < INF) {
        int ind = times.begin()->second;
        Time t = times.begin()->first;
        times.erase(times.begin());

        auto it = S.lower_bound(make_pair(initp[ind], ind));
        int cnt = 0;
        vector<multiset<pair<int, int>>::iterator> erases;
        while (true) {
            ++it;
            if (it == S.end()) {
                it = S.begin();
            }
            if (getTime(time, n, m, ind, it->second) == t) {
                ++cnt;
                erases.push_back(it);
            } else {
                break;
            }
        }
        for (auto it: erases) {
            times.erase(times.find(make_pair(eraseTime[it->second], it->second)));
            S.erase(it);
        }
        
        it = S.lower_bound(make_pair(initp[ind], ind));
        ++it;
        if (it == S.end()) {
            it = S.begin();
            if (it->second == ind) break;
        }

        updatePos(n, m, ind, t);
        //cerr << positions[ind] << endl;

        speeds[ind] -= cnt;
        if (speeds[ind] < 0) speeds[ind] = 0;
        time = t;

        t = getTime(time, n, m, ind, it->second);
        times.insert(make_pair(t, ind));
        eraseTime[ind] = t;

        it = S.lower_bound(make_pair(initp[ind], ind));
        if (it == S.begin()) it = S.end();
        --it;

        if (it->second != ind) {
            times.erase(times.find(make_pair(eraseTime[it->second], it->second)));
            t = getTime(time, n, m, it->second, ind);
            times.insert(make_pair(t, it->second));
            eraseTime[it->second] = t;
        }
    }

    cout << SZ(S) << '\n';
    for (auto it: S) {
        cout << it.second + 1 << ' ';
    }

    cout << '\n';
}