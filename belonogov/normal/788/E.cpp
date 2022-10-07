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

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

void ff(ll& A, ll B) {
    A = (A + B % MOD + MOD) % MOD;
}

struct SegTree {
    vector<ll> data;
    vector<ll> upd;
    vector<int> cntBlock;
    int nn;
    void init(int n) {
        nn = n;
        data.resize(n * 4);
        upd.resize(n * 4);
        cntBlock.resize(n * 4);
    }
    void push(int v, int tl, int tr) {
        if (upd[v] != 0) {
            ff(upd[v * 2 + 1], upd[v]);
            ff(upd[v * 2 + 2], upd[v]);
            ff(data[v * 2 + 1], upd[v] * ((tl + tr) / 2 - tl - cntBlock[v * 2 + 1]));
            ff(data[v * 2 + 2], upd[v] * (tr - (tl + tr) / 2 - cntBlock[v * 2 + 2]));
            upd[v] = 0;
        }
    }
    void add(int l, int r, int val) {
        add(0, 0, nn, l, r, val);
    }

    void add(int p, int val) {
        add(0, 0, nn, p, p + 1, val); 
    }

    void block(int pos, int val) {
        block(0, 0, nn, pos, val);
    }

    void block(int v, int tl, int tr, int pos, int val) {
        if (tl + 1 == tr) {
            cntBlock[v] += val;
            assert(data[v] == 0);
            assert(0 <= cntBlock[v] && cntBlock[v] <= (tr - tl));
            return;
        }
        push(v, tl, tr);
        if (pos < (tl + tr) / 2)
            block(v * 2 + 1, tl, (tl + tr) / 2, pos, val);
        else 
            block(v * 2 + 2, (tl + tr) / 2, tr, pos, val);
        cntBlock[v] = cntBlock[v * 2 + 1] + cntBlock[v * 2 + 2];
        assert(0 <= cntBlock[v] && cntBlock[v] <= (tr - tl));
    }

    void add(int v, int tl, int tr, int l, int r, ll val) {
        if (r <= tl || tr <= l) return ;
        if (l <= tl && tr <= r) {
            ff(data[v], val * ((tr - tl) - cntBlock[v]));
            ff(upd[v], val);
            return;
        }
        push(v, tl, tr);
        add(v * 2 + 1, tl, (tl + tr) / 2, l, r, val);
        add(v * 2 + 2, (tl + tr) / 2, tr, l, r, val);
        data[v] = (data[v * 2 + 1] + data[v * 2 + 2]) % MOD;
    }

    ll getSum(int l, int r) {
        return getSum(0, 0, nn, l, r);
    }

    ll getSum(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return 0;
        if (l <= tl && tr <= r) {
            return data[v];
        }
        push(v, tl, tr);
        return (getSum(v * 2 + 1, tl, (tl + tr) / 2, l, r) +
               getSum(v * 2 + 2, (tl + tr) / 2, tr, l, r)) % MOD;

    }
};



vector<int> a;
vector<pair<int,int>> query;

void read() {
    int n;
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    query.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &query[i].F, &query[i].S);
        query[i].S--;
    }
}

vector<ll> solve() {
    vector<pair<int,int>> tmp; 
    vector<int> xx;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        xx.pb(a[i]);
    }
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(xx), a[i]) - xx.begin(); 
    }
    vector<vector<int>> where(xx.size());
    vector<SegTree> sumL(xx.size());
    vector<SegTree> sumR(xx.size());
    vector<SegTree> cntL(xx.size());
    vector<SegTree> cntR(xx.size());
    vector<vector<int>> valL(xx.size());
    vector<vector<int>> valR(xx.size());

    for (int i = 0; i < n; i++) {
        tmp.pb({a[i], i});
        where[a[i]].pb(i);
    }
    sort(all(tmp));

    SegTree help;
    help.init(n);
    ll answer = 0;
    for (int i = 0; i < (int)tmp.size(); ) {
        int j = i;
        int val = tmp[j].F;
        for (; i < (int)tmp.size() && tmp[j].F == tmp[i].F; i++);

        for (int t = j; t < i; t++)
            help.add(0, 0, n, tmp[t].S, tmp[t].S + 1, 1);

        int len = i - j;

        sumL[val].init(len);
        sumR[val].init(len);
        cntL[val].init(len);
        cntR[val].init(len);
        valL[val].resize(len);
        valR[val].resize(len);

        //cntL[val].resize(len);
        //cntR[val].resize(len);
        for (int t = j; t < i; t++)  {
            int zz = help.getSum(0, tmp[t].S);
            valL[val][t - j] = zz;
            cntL[val].add(t - j, zz);
            sumL[val].add(t - j, cntL[val].getSum(0, t - j));
        }
        //cerr << endl;
        for (int t = i - 1; t >= j; t--) {
            int zz = help.getSum(tmp[t].S + 1, n);
            cntR[val].add(t - j, zz);
            valR[val][t - j] = zz;
            sumR[val].add(t - j, cntR[val].getSum(t - j + 1, n));
        }
        //cerr << endl;
        //cerr << "sl2: ";

        for (int t = j; t < i; t++) {
            //cerr << sumL[val].getSum(t - j, t - j + 1) << " ";
            ff(answer, cntL[val].getSum(0, t - j) * cntR[val].getSum(t - j + 1, len));
        }
        //cerr << endl;
    }


    //int m;
    //scanf("%d", &m);
    vector<ll> res;
    for (auto x: query) {
        int type, pos; 
        //scanf("%d%d", &type, &pos); pos--;
        type = x.F;
        pos = x.S;
        int val = a[pos];
        int t = lower_bound(all(where[val]), pos) - where[val].begin();
        int len = where[val].size();
        int sign = (type == 1)? -1: 1;

        ff(answer, sign * cntL[val].getSum(0, t) * cntR[val].getSum(t + 1, len));

        if (type == 2) {
            sumR[val].block(t, sign * -1);
            sumL[val].block(t, sign * -1);
        }


        //db(answer);
        //db2("1", answer);


        sumL[val].add(t, sign * cntL[val].getSum(0, t));
        sumR[val].add(t, sign * cntR[val].getSum(t + 1, len));

        cntL[val].add(t, sign * valL[val][t]);
        cntR[val].add(t, sign * valR[val][t]);

        sumL[val].add(t + 1, len, sign * valL[val][t]);
        sumR[val].add(0, t, sign * valR[val][t]);

        if (type == 1) {
            sumR[val].block(t, sign * -1);
            sumL[val].block(t, sign * -1);
        }


        ff(answer, sign * sumR[val].getSum(t + 1, len) * valL[val][t]);
        //db(sumR[val].getSum(0, 1));
        //db(sumR[val].getSum(1, 2));
        //db(sumR[val].getSum(2, 3));
        //db2(sumR[val].getSum(t + 1, len),  valL[val][t]);
        
        //db2("2", answer);
        ff(answer, sign * sumL[val].getSum(0, t) * valR[val][t]);
        //db2("3", answer);

        //db(sumL[val].getSum(0, 1));
        //db(sumL[val].getSum(1, 2));
        //db(sumL[val].getSum(2, 3));
        //db(t);
        //db2(sumL[val].getSum(0, t), valR[val][t]);
        //db(answer);

        res.pb(answer);
    }

    return res;
}

void genTest() {
    int n = rand() % 10 + 1;
    int m = rand() % 5 + 1;
    a.clear();
    for (int i = 0; i < n; i++) {
        a.pb(rand() % 5);
    }
    vector<int> used(n, 0);
    query.clear();
    for (int i = 0; i < m; i++) {
        int pos = rand() % n;
        int type = (used[pos] == 0)? 1: 2;
        query.pb({type, pos});
        used[pos] ^= 1;
    }
}

vector<ll> slow() {
    vector<ll> res;
    int n = a.size();
    vector<int> use(n, 1);
    for (auto x: query) {
        ll answer = 0;        
        use[x.S] ^= 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    for (int l = k + 1; l < n; l++)
                        for (int t = l + 1; t < n; t++) 
                            if (a[j] == a[k] && a[k] == a[l] && a[i] <= a[j] && a[t] <= a[j] && use[j] && use[k] && use[l])
                                answer++;
        res.pb(answer);
    }
    return res;
}

void printTest() {
    cout << a.size() << endl;
    for (auto x: a)
        cout << x << " ";
    cout << endl;
    cout << query.size() << endl;
    for (auto x: query)
        cout << x.F << " " << x.S + 1 << endl;

}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        printTest();
        auto r1 = solve();
        auto r2 = slow();
        assert(r1 == r2);
    }

}
void printAns(vector<ll> res) {
    for (auto x: res)
        printf("%lld\n", x);
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        read();
        printAns(solve());
        //cerr << endl;
        //printAns(slow());
    }
    else {
        stress();
    }
        
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}