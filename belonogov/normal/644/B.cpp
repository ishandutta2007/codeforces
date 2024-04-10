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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

struct Event {
    long long t, type, id;
    Event() { }
    Event(long long t, int type, int id): t(t), type(type), id(id) { }
    bool operator < (Event a) const {
        return t < a.t || (t == a.t && type < a.type) || (t == a.t && type == a.type && id < a.id);
    }
};

int n, b;
pair < int, int > c[N];


void read() {
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &c[i].fr, &c[i].sc);
    }
}

long long answer[N];

void solve() {
    set < Event > q;
    for (int i = 0; i < n; i++)
        q.insert(Event(c[i].fr, 1, i));

    queue < int > qq;
    bool status = 0;
    while (!q.empty()) {
        Event e = *q.begin();
        q.erase(q.begin());
        if (e.type == 1) {
            if ((int)qq.size() < b) 
                qq.push(e.id);
            else
                answer[e.id] = -1;
        }
        else 
            status = 0;
        if (status == 0 && !qq.empty()) {
            int id = qq.front();
            qq.pop();
            q.insert(Event(e.t + c[id].sc, 0, id));
            answer[id] = e.t + c[id].sc;
            status = 1;
        }
    }


    for (int i = 0; i < n; i++)
        printf("%lld ", answer[i]);
    puts("");

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
        }
    }
    else {
        stress();
    }

    return 0;
}