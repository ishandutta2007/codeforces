#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;


struct Tree {
    vector < int > data;
    int sz;
    void init(int n) {
        sz = n;
       data.assign(sz * 4, INF); 
    }
    void minEq(int v, int ll, int rr, int pos, int val) {
        if (ll > pos || rr <= pos) return;
        if (ll + 1 == rr) {
            data[v] = min(data[v], val);
            return;
        }
        minEq(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        minEq(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        data[v] = min(data[v * 2 + 1], data[v * 2 + 2]);
    }
    void minEq(int pos, int val) {
        minEq(0, 0, sz, pos, val); 
    }
    int getMin(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return INF;
        if (l <= ll && rr <= r) 
            return data[v];
        return min(getMin(v * 2 + 1, ll, (ll + rr) / 2, l, r), 
                   getMin(v * 2 + 2, (ll + rr) / 2, rr, l, r));
    }
    int getMin(int l, int r) {
        return getMin(0, 0, sz, l, r);
    }

};

struct event {
    int type, l, r, id; 
    event() { }
    event(int type, int l, int r, int id): type(type), l(l), r(r), id(id) { }
};


int n, m;
int a[N];
int l[N];
int r[N];
vector < event > b;


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l[i], &r[i]); 
    }
}

bool cmp(const event & a, const event & b) {
    return a.r < b.r || (a.r == b.r && a.type < b.type);
}

vector < int > solve() {
    b.clear();
    vector < int > answer(m);
    //for (int i = 0; i < m; i++) {
        //l[i]--;
        //r[i]--;
    //}
    for (int i = 0; i < m; i++) {
        b.pb(event(2, l[i] - 1, r[i] - 1, i));
    } 
    map < int, int > tmp;
    for (int i = 0; i < n; i++) {
        if (tmp.count(a[i]) == 1) {
            b.pb(event(1, tmp[a[i]], i, -1));
        }
        tmp[a[i]] = i;
    }
    sort(b.begin(), b.end(), cmp);
    Tree t;
    t.init(n + 1);
    for (auto x: b) {
        if (x.type == 1) {
            t.minEq(x.l, x.r - x.l);
        }
        else if (x.type == 2) {
            answer[x.id] = t.getMin(x.l, x.r + 1);
            if (answer[x.id] == INF)
                answer[x.id] = -1;
        }
        else
            assert(false);
    }

    return answer;
}


void printAns(vector < int > answer) {
    for (int i = 0; i < m; i++)
        printf("%d\n", answer[i]);
}

void genTest() {
    n = 5e5;
    m = 5e5;
    int T = 2;
    for (int i = 0; i < n; i++)
        a[i] = rand() % T;
    for (int i = 0; i < m; i++) {
        l[i] = rand() % n;
        r[i] = rand() % n;
        if (l[i] > r[i]) swap(l[i], r[i]);
        l[i]++;
        r[i]++;
    }
}

vector < int > stupid() {
    vector < int > answer;
    for (int i = 0; i < m; i++) {
        int res = INF;
        for (int j = l[i] - 1; j < r[i]; j++)
            for (int k = j + 1; k < r[i]; k++)
                if (a[j] == a[k])
                    res = min(res, k - j);
        if (res == INF)
            res = -1;
        answer.pb(res);
    }
    return answer;
}

void printTest() {
    cerr << n << " " << m << endl;
    for (int i = 0; i < n; i++)
        cerr << a[i] << " ";
    cerr << endl;
    for (int j = 0; j < m; j++)
        cerr << l[j] << " " << r[j] << endl;

}

void stress() {
    for (int t = 0; t < 2000; t++) {
        cerr << "test id: " << t << endl;        
        genTest();
        auto r1 = solve();
        cerr << clock() *1.0 / CLOCKS_PER_SEC << endl;
        auto r2 = stupid();
        if (r1 != r2) {
            cerr << "fail\n";
            for (auto x: r1)
                cerr << x << " ";
            cerr << endl;
            for (auto x: r2)
                cerr << x << " ";
            cerr << endl;
            printTest();
            exit(0);
        }
    }


}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            printAns(solve());
            //printAns(stupid());
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}