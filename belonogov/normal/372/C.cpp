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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;

struct Event {
    int t, pos;
    Event() { }
    Event(int t, int pos): t(t), pos(pos) { }
};

struct Stack {
    vector < pair < int, int > > data; 
    void add(int x) {
        int mn = (data.empty())? x: min(x, data.back().sc);
        data.pb(mp(x, mn));
    }
    int getMin() {
        if (data.empty()) return INF;
        return data.back().sc;
    }
    int pop() {
        int val = data.back().fr;
        data.pop_back();
        return val;
    }
    bool empty() {
        return data.empty();
    }
};

struct Queue {
    Stack s1, s2;
    void add(int x) {
        s1.add(x); 
    }
    int getMin() {
        return min(s1.getMin(), s2.getMin());
    }
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.pop();
                s2.add(x);
            }
        } 
        assert(!s2.empty());
        return s2.pop();
    }
};


int n, m, d;
long long answer;
vector < Event > e;
int dp1[N];
int dp2[N];

void read() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        answer += b;
        a--;
        e.pb(Event(t, a));
    }
}

bool cmpT(Event a, Event b) {
    return a.t < b.t;
}

void solve() {
    sort(e.begin(), e.end(), cmpT);
    for (int j = 0; j < m; j++) {
        int shift;
        if (j == 0) shift = n;
        else if ((e[j].t - e[j - 1].t) * 1ll * d < n)
            shift = (e[j].t  - e[j - 1].t) * 1ll * d;
        else
            shift = n;

        int l = 0;
        int r = 0;
        Queue q;
        //db(shift);
        for (int i = 0; i < n; i++) {
            for (; r < n && r <= i + shift; r++)
                q.add(dp1[r]);
            for (; l < i - shift; l++) {
                int x = q.pop();
                assert(x == dp1[i - shift - 1]);
            }
            dp2[i] = q.getMin();
            //db2(l, r);
        } 
        //db("here");

        for (int i = 0; i < n; i++)
            dp2[i] += abs(i - e[j].pos); 
        //db(j);
        //for (int i = 0; i < n; i++)
            //cerr << dp2[i] << " ";
        //cerr <<  endl;
         
        memcpy(dp1, dp2, sizeof(dp2));
    }
    long long mn = INF;
    for (int i = 0; i < n; i++)
        mn = min(dp1[i] * 1ll, mn);
    //db(mn);
    cout << answer - mn << endl;

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