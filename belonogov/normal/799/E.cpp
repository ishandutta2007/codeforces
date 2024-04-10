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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

int nx(int i, int n) { return (i == n - 1)? 0: i + 1; }
int pr(int i, int n) { return (i == 0)? n - 1: i - 1; }

typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
const ll INF18 = 1.01e18;
typedef vector<int> vi;

int n, m, k;
vector<pair<int,int>> c;

void read() {
    scanf("%d%d%d", &n, &m, &k);
    c.clear();
    c.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i].F);
    for (int tt = 1; tt <= 2; tt++) {
        int F;
        scanf("%d", &F);
        for (int i = 0; i < F; i++) {
            int id;
            scanf("%d", &id); id--;
            c[id].S ^= tt;
        }
    }
}

ll solve() {
 
    sort(all(c));
    vector<ll> b[2][2];
    vector<ll> pref[2][2];
    for (auto A: c) {
        b[A.S & 1][(A.S >> 1) & 1].pb(A.F);
    }
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            pref[x][y].pb(0);
            for (auto A: b[x][y]) {
                pref[x][y].pb(pref[x][y].back() + A);
            }
        }
    }
    
    ll answer = INF18;
    multiset<ll> q;

    vector<ll> trash;
    trash.insert(trash.end(), all(b[0][0]));

    if ((int)b[0][1].size() > k) trash.insert(trash.end(), b[0][1].begin() + k, b[0][1].end());
    if ((int)b[1][0].size() > k) trash.insert(trash.end(), b[1][0].begin() + k, b[1][0].end());


    sort(all(trash));
    ll sumQ = 0;
    auto addQ = [&] (ll x) {
        q.insert(x);
        sumQ += x;
    };


    for (int i = 0; i < sz(trash); i++) {
        addQ(trash[i]);
    }

    //db2(sumQ, q.size());

    multiset<ll> help;
    for (int cntGood = 0; cntGood <= m && cntGood <= sz(b[1][1]); cntGood++) {
        int rem = max(0, k - cntGood);
        
        int needSizeQ = m - cntGood - min(rem, sz(b[0][1])) - min(rem, sz(b[1][0]));
        if (cntGood != 0) {
            //sumQ += b[1][1][cntGood - 1];
            int oldRem = max(0, k - (cntGood - 1));
            //db2(oldRem, rem);
            if (oldRem > rem) {
                if (rem < sz(b[0][1])) {
                    //db("here");
                    addQ(b[0][1][rem]);
                }

                if (rem < sz(b[1][0]))  {
                    //db("here");
                    addQ(b[1][0][rem]);
                }
            }
        }
        //db2(needSizeQ, q.size());

        for (; sz(q) > needSizeQ && !q.empty(); ) {
            //db("rem");
            ll top = *q.rbegin();
            q.erase(q.find(top));
            sumQ -= top;
            help.insert(top);
        }

        //db2(q.size(), needSizeQ);
        //assert(sz(q) == needSizeQ);
        if (sz(q) > 0) {
            for (; !help.empty() && *help.begin() < *q.rbegin(); ) {
                ll top = *q.rbegin();
                q.erase(q.find(top));
                sumQ -= top;
                ll g = *help.begin();
                help.erase(help.begin());
                addQ(g);
            }
        }

        //db(needSizeQ);
        //db(rem);
        //db(q.size());
        //db3((rem <= sz(b[0][1])), (rem <= sz(b[1][0])), ((ll)q.size() == m - cntGood - rem * 2));
        //db3(m, cntGood, rem);

        //cerr << endl;
        if (rem <= sz(b[0][1]) && rem <= sz(b[1][0]) && (ll)q.size() == m - cntGood - rem * 2) {
            //db("Ttu");
            //db3(cntGood, rem, sumQ);
            //db3(pref[0][1][rem], pref[1][0][rem], pref[1][1][cntGood]);
            answer = min(answer, pref[0][1][rem] + pref[1][0][rem] + pref[1][1][cntGood] + sumQ);
        }
    }


    if (answer == INF18) {
        answer = -1;
    }
    return answer;
}


void genTest() {
    n = rand() % 10 + 1;
    m = rand() % n + 1;
    k = rand() % n + 1;
    int T = 1e9;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        c[i].F = rand() % T + 1;
        c[i].S = rand() % 4;
    }
}

void printTest() {
    cout << n << " " << m << " " << k << endl;
    for (int i = 0; i < n; i++)
        cout << c[i].F << " ";
    cout << endl;
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < n; i++) {
        if (c[i].S % 2 == 1)
            x.pb(i);
        if (c[i].S / 2 == 1)
            y.pb(i);
    }
    cout << x.size() << endl;
    for (auto A: x) cout << A + 1 << " ";
    cout << endl;
    cout << y.size() << endl;
    for (auto A: y) cout << A + 1 << " ";
    cout << endl;

}


ll slow() {
    ll answer = INF18;
    for (int mask = 0; mask < pw(n); mask++) {
        vector<int> who;
        for (int i = 0; i < n; i++)
            if (mask & pw(i))
                who.pb(i);
        if (m != sz(who)) continue;
        ll sum = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto x: who) {
            sum += c[x].F;
            if (c[x].S % 2 == 1) cnt1++;
            if (c[x].S / 2 == 1) cnt2++;
        }
        if (cnt1 >= k && cnt2 >= k)
            answer = min(answer, sum);
    }
    if (answer == INF18)
        answer = -1;
    return answer;

}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        read();
        //cout << slow() << endl;
        cout << solve() << endl;
    }
    else {
        for (int tt = 0; ; tt++) {
            db(tt);
            genTest();
            printTest();
            auto r1 = slow(); 
            auto r2 = solve();            
            //db2(r1,  r2);
            assert(r1 == r2);
        }
    }


#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}