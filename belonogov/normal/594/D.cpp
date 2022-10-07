#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
const long long N = 1e6 + 10;
const long long INF = 1e9 + 19;
const long long MOD = 1e9 + 7;

struct Event{
    int type, x, y, id;
    long long val;
    Event() { }
    Event(int type, int x, int y, int id, long long val): type(type), x(x), y(y), id(id), val(val) { }
};

long long rev(int a, int m) {
    long long b = m - 2;
    long long res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = (res * a) % m;  
        }
        a = (a * 1ll * a) % m;
    }
    return res; 
}

struct Fenwick {
    vector < long long > data;
    long long n;
    Fenwick(long long n): n(n) { 
        data.assign(n + 1, 1);
    }
    void add(long long val, long long pos) {
        for (; pos < n ; pos |= (pos + 1))
            data[pos + 1] = (data[pos + 1] * val) % MOD;
    }

    long long get(long long r) {
        long long res = 1;
        for (; r > 0; r &= (r - 1))
            res = (res * data[r]) % MOD;
        return res;
    }

    long long get(long long l, long long r) {
        auto f1 = get(r);
        auto f2 = get(l);
        return f1 * rev(f2, MOD) % MOD;
    }
};

int n, m;
int a[N];
pair < int, int > q[N];


void read() {
    scanf("%d", &n);
    for (long long i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (long long i = 0; i < m; i++) {
        scanf("%d%d", &q[i].fr, &q[i].sc); q[i].fr--;
    }
}

bool cmpX(Event a, Event b) {
    return a.x < b.x || (a.x == b.x && a.type < b.type);
}

void solve() {
    Fenwick fen1(n);
    for (long long i = 0; i < n; i++)
        fen1.add(a[i], i); 
    
    vector < vector < int > > primes(N);
    for (long long i = 2; i < N; i++) {
        if (primes[i].empty()) 
            for (int j = i; j < N; j += i)
                primes[j].pb(i);
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max((int)a[i], mx);
    vector < int > last(mx + 1, -1);
    vector < Event > data;
    for (long long i = 0; i < n; i++) {
        for (auto p: primes[a[i]]) {
            long long pp = rev(p, MOD);
            data.pb(Event(1, i, last[p] + 1, -1, ((p - 1) * 1ll * pp) % MOD));
            last[p] = i;
        }
    }
    for (long long i = 0; i < m; i++) {
        data.pb(Event(0, q[i].fr, q[i].fr + 1, i, -1)); 
        data.pb(Event(-1, q[i].sc, q[i].fr + 1, i, -1)); 
    }

    sort(data.begin(), data.end(), cmpX);
    Fenwick fen2(n);

    vector < long long > answer(m);
    for (long long i = 0; i < m; i++)
        answer[i] = fen1.get(q[i].fr, q[i].sc);

    for (auto x: data) {
        if (x.type == 1) {
            fen2.add(x.val, x.y);
        }
        else if (x.type == 0) {
            long long r = fen2.get(x.y);
            answer[x.id] = (answer[x.id] * rev(r, MOD)) % MOD;
        }
        else if (x.type == -1) {
            long long r = fen2.get(x.y);
            answer[x.id] = (answer[x.id] * r) % MOD;
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", (int)answer[i]);
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    read();
    solve();
    return 0;
}