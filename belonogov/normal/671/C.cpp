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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;

struct Event {
    int t, l, val;
    Event(int t, int l, int val): t(t), l(l), val(val) { }
};

struct Seg {
    int l, r, val;
    Seg() { }
    Seg(int l, int r, int val): l(l), r(r), val(val) { }
    bool operator < (const Seg & seg) const {
         return l < seg.l;
    }
    int len() const {
        return r - l;
    }
};

int n;
int a[N];
int mn[N][3];
int mx[N][3];
int lp[N];
vector < int > pr;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
}

void genAll(const vector < pair < int, int > > & data, int i, int pos, int val) {
    if (pos == (int)data.size()) {
        //db2(val, i);
        mn[val][2] = i;
        for (int j = 1; j >= 0; j--) 
            if (mn[val][j] > mn[val][j + 1])
                swap(mn[val][j], mn[val][j + 1]);
        mx[val][2] = i;
        for (int j = 1; j >= 0; j--)
            if (mx[val][j] < mx[val][j + 1])
                swap(mx[val][j], mx[val][j + 1]);

        return;
    }
    for (int j = 0; j <= (int)data[pos].sc; j++) {
        genAll(data, i, pos + 1, val);
        val *= data[pos].fr;
    }
} 

set < Seg > q;
long long sum;

void insert(Seg A) {
    sum += A.len() * 1ll * A.val;
    //cerr << "inesrt: ";
    //db3(A.l, A.r, A.val);
    assert(sum >= 0);
    //db(sum);
    q.insert(A);
}

void erase(set < Seg > :: iterator it) {
    sum -= it->len() * 1ll * it->val;
    //cerr << "erase: ";
    //db3(it->l, it->r, it->val);
    //db(sum);
    assert(sum >= 0);
    q.erase(it);
}

void printSet() {
    cerr << "set " << sum << endl;
    for (auto x: q)
        db3(x.l, x.r, x.val);
}

void solve() {
    int g = 0; 
    for (int i = 0; i < n; i++)
        g = max(g, a[i]);
    for (int i = 1; i <= g; i++)
        for (int j = 0; j < 3; j++) {
            mx[i][j] = -1;
            mn[i][j] = n;
        }
    
    for (int i = 2; i <= g; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= g; j++)
            lp[i * pr[j]] = pr[j];
    }
     
    
    for (int i = 0; i < n; i++) {
        vector < pair < int, int > > tmp;
        int x = a[i];
        int last = -1;
        int cnt = 0;
        for (; x > 1; ) {
            if (lp[x] != last) {
                if (cnt > 0) {
                    tmp.pb(mp(last, cnt));
                }
                last = lp[x];
                cnt = 0;
            }
            cnt++;
            x /= lp[x];
        }
        if (cnt > 0)
            tmp.pb(mp(last, cnt));
        genAll(tmp, i, 0, 1);
    } 

    vector < Event > event;

    for (int i = 1; i <= g; i++) {
        if (mx[i][1] == -1) continue; 
        event.pb(Event(mx[i][1] - 1, 0, i));
        event.pb(Event(n, mn[i][1] + 1, i));
        event.pb(Event(mx[i][0] - 1, mn[i][0] + 1, i));
    }

    sort(event.begin(), event.end(), [](Event a, Event b) { return a.t > b.t; }); 

    //for (auto x: event)
        //db3(x.t, x.l, x.val);

    long long answer = 0;
    sum = 0;
    insert(Seg(0, n, 0));
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        //printSet();
        for (; cur < (int)event.size() && event[cur].t >= i; cur++) {
            auto it = q.upper_bound(Seg(event[cur].l, -1, -1));
            assert(it != q.begin());
            it--;
            if (it->val >= event[cur].val) continue;
            //sum -= it->val * 1ll * it->len();
            int left = it->l;
            int oldVal = it->val;
            auto itNext = it;
            itNext++;
            erase(it);
            if (left < event[cur].l) {
                insert(Seg(left, event[cur].l, oldVal));
            }

            for (; itNext != q.end();) {
                if (itNext->val < event[cur].val) {
                    auto tmpIt = itNext;
                    tmpIt++;
                    erase(itNext);
                    itNext = tmpIt;
                }
                else
                    break;
            }
            int right = (itNext == q.end())? i + 1: itNext->l;
            insert(Seg(event[cur].l, right, event[cur].val));
        }
        Seg tmp = *q.rbegin();
        erase(q.find(tmp));
        assert(tmp.r >= i + 1);
        tmp.r = i + 1;
        insert(tmp);

        answer += sum;
    }
    cout << answer << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
    }

}


int main(){
#ifdef MY_DEBUG
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