#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 4e5 + 10;
const long long INF = 1e18;

struct Res {
    int pos;
    long long val;
    Res() { }
    Res(int pos, long long val): pos(pos), val(val) { }
    bool operator < (const Res & A) const {
        return val < A.val;
    }
    void Epr() {
        cerr << "pos val: " << pos << " " << val << endl;
    }
};

struct Query {
    int l, r, id;
    pair < Res, Res > x, y;
    long long ans;
    Query(): ans(-1) { }
    void Epr() {
        //cerr << "l r: " << l << " " << r << endl; 
        x.fr.Epr();
        x.sc.Epr();
        y.fr.Epr();
        y.sc.Epr();
    }
};

pair < Res, Res > merge(const pair < Res, Res > &  a, const pair < Res, Res > & b) {
    pair < Res, Res > ans = a;
    if (ans.sc < b.sc) {
        ans.sc = b.sc;
        if (ans.fr < ans.sc) 
            swap(ans.fr, ans.sc);
    }
    if (ans.sc < b.fr) {
        ans.sc = b.fr;
        if (ans.fr < ans.sc) 
            swap(ans.fr, ans.sc);
    }
    return ans;
}


struct Tree {
    vector < pair < Res, Res > > mx;
    int sz;
    Tree() { }
    Tree(int n) {
        sz = n;
        mx.resize(sz * 4);
    }
    void add(int v, int ll, int rr, int pos, long long val) {
        if (pos >= rr || pos < ll) return;
        if (rr - ll == 1) {
            mx[v] = mp(Res(pos, val), Res(-1, -INF));
            return;
        }
        add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        mx[v] = merge(mx[v * 2 + 1], mx[v * 2 + 2]);
       
    }

    void add(int pos, long long val) {
        add(0, 0, sz, pos, val);
    }
   
    pair < Res, Res > getMax(int v, int ll, int rr, int l, int r) {
        if (l >= rr || ll >= r) return mp(Res(-1, -INF), Res(-1, -INF));
        if (l <= ll && rr <= r) {
            return mx[v];
        }
        return merge(getMax(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                    getMax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
    } 

    pair < Res, Res > getMax(int l, int r) {
        //cerr << "l r: " << l << " " << r << endl;
        return getMax(0, 0, sz, l, r);
    
    }

};

int n, m;
long long d[N];
long long h[N];
long long pref[N];
Query a[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &d[i]);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &h[i]);
        h[i] *= 2;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        a[i].l = v;
        a[i].r = u;
        //cerr << "l r: " << a[i].l << " " << a[i].r << endl;
        a[i].id = i;
    }
}

bool inSeg(int l, int r, int pos) {
    return l <= pos && pos <= r;
}

long long calcPath(int x, int y, int l, int r) {
    //cerr << "x y l r: " << x << " " << y << " " << l << " " << r << endl;
    if (x == -1 || y == -1) return -1;
    if (x > y) swap(x, y);
    if (x == y) return -1;
    if (l <= r) {
        assert(!inSeg(l, r, x));
        assert(!inSeg(l, r, y));
        bool r1 = x < l;
        bool r2 = y < l;
        //cerr << "r1 r2: " << r1 << " " << r2 << endl;
        if (r1 == r2) {
            //cerr << "this case\n";
            //cerr << pref[y] - pref[x] + h[x] + h[y] << endl;
            return pref[y] - pref[x] + h[x] + h[y];
        }
        else {
            return pref[x] + pref[n] - pref[y] + h[x] + h[y];
        }
    }
    else {
        return pref[y] - pref[x] + h[x] + h[y];
    }
}

void rev(int & a) {
    a = n - 1 - a;
}


void solve() {
    for (int tt = 0; tt < 2; tt++) {
        //cerr << "tt---------------------\n";
        Tree t(n);         
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            t.add(i, h[i] - sum);
            sum += d[i];
        }

        for (int i = 0; i < m; i++) {
            if (a[i].l <= a[i].r) {
                auto r1 = t.getMax(a[i].r + 1, n);
                r1.fr.val += sum;
                r1.sc.val += sum;
                //r1.fr.Epr();
                //r1.sc.Epr();
                auto r2 = t.getMax(0, a[i].l);
                //r2.fr.Epr();
                //r2.sc.Epr();
                auto r3 = merge(r1, r2);
                //r3.fr.Epr();
                //r3.sc.Epr();
                a[i].x = r3;
            }
            else  {
                auto r1 = t.getMax(a[i].r + 1, a[i].l);
                a[i].x = r1;
            }
        } 

        for (int i = 0; i < m; i++) {
            swap(a[i].x, a[i].y);
            swap(a[i].l, a[i].r);
            rev(a[i].l);
            rev(a[i].r);
            rev(a[i].x.fr.pos);
            rev(a[i].x.sc.pos);
            rev(a[i].y.fr.pos);
            rev(a[i].y.sc.pos);
        }
        reverse(h, h + n);
        reverse(d, d + n - 1);
    } 
    //cerr << "query\n";
    pref[0] = 0;
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + d[i];
    //for (int i = 0; i < m; i++)
        //a[i].Epr();

    for (int i = 0; i < m; i++) {
        long long res = 0;
        res = max(res, calcPath(a[i].x.fr.pos, a[i].y.fr.pos, a[i].l, a[i].r));
        res = max(res, calcPath(a[i].x.fr.pos, a[i].y.sc.pos, a[i].l, a[i].r));
        res = max(res, calcPath(a[i].x.sc.pos, a[i].y.fr.pos, a[i].l, a[i].r));
        res = max(res, calcPath(a[i].x.sc.pos, a[i].y.sc.pos, a[i].l, a[i].r));
        a[i].ans = res;
    }
    for (int i = 0; i < m; i++) {
        printf("%lld\n", a[i].ans);
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}