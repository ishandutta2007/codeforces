#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9;

struct Event {
    long long  t, id, r;
    Event(long long t, int id, long long r): t(t), id(id), r(r) { }
};

int n, m;
long long a[N];
long long b[N];
int answer[N];
vector < Event > d;
set < pair < long long , int > > q;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        //cin >> a[i] >> b[i];
        scanf("%lld%lld", &a[i], &b[i]);

    for (int i = 0; i < m; i++) {
        long long x;
        //cin >> x;
        scanf("%lld", &x);
        d.pb(Event(x, i, -1)); 
    }
}

bool cmp(const Event & a, const Event & b) {
    if (a.t != b.t) return a.t < b.t;
    return a.r > b.r;
}

void solve() {
    for (int i = 0; i < n - 1; i++) {
        long long mn = a[i + 1] - b[i];
        long long mx = b[i + 1] - a[i];
        d.pb(Event(mn, i, mx)); 
        //db2(mn, mx);
    }
    sort(d.begin(), d.end(), cmp);
    bool flag = 1;
    for (auto x: d) {
        if (x.r >= 0) {
            q.insert(mp(x.r, x.id)); 
        }
        else {
            if (q.empty()) continue;

            auto y = *(q.begin());
            if (y.fr < x.t) flag = 0;
            q.erase(q.begin());
            answer[y.sc] = x.id;
        }
    }
    flag &= q.empty();
    if (!flag)
        cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; i++)
            cout << answer[i] + 1 << " ";
        cout << "\n";
    }

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}