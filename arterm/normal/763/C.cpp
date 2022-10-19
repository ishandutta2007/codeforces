#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
typedef long double ld;
typedef long long ll;
typedef long long i64;

const int M = 100100;
const int B = 4017;
const int ITER = 30;

int mod;

int add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int sub(int x, int y) {
    return add(x, mod - y);
}

int mul(ll x, ll y) {
    return x * y % mod;
}

int bin(int x, int to) {
    int y = 1;
    while (to) {
        if (to & 1)
            y = mul(x, y);
        x = mul(x, x);
        to >>= 1;
    }
    return y;
}

int inv(int x) {
    return bin(x, mod - 2);
}

int n, a[M];
set<int> rem;
bool chan = false;
mt19937 rd;

int rnd() {
    return rd();
}

void read() {
    cin >> mod;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void ans(int x, int d) {
    assert(0 <= x && x < mod);
    assert(0 <= d && d < mod);
    cout << x << " " << d << endl;
    exit(0);
}

void no() {
    cout << -1 << endl;
    exit(0);
}


void shorten() {
    int sz = rem.size();
    int k = rnd() % sz;
    auto it = rem.begin();
    for (int i = 0; i < k; ++i)
        it++;
    int x = *it;

    set<int> nx;
    for (int y : rem) {
        int z = sub(mul(2, x), y);
        if (rem.find(z) == rem.end())
            nx.insert(y);
    }

    if (nx.size() >= 3)
        rem = nx;
}

void change() {
    set<int> all;
    for (int i = 0; i < mod; ++i)
        all.insert(i);
    for (int i = 0; i < n; ++i)
        all.erase(a[i]);

    n = 0;
    for (int x : all)
        a[n++] = x;

    chan = true;
}

int solve() {
    if (n == 1)
        return 1;
    if (n == 2)
        return sub(a[1], a[0]);

    rem = set<int>(a, a + n);
    for (int k = 0; k < ITER; ++k)
        shorten();

    
    vector<int> cur(rem.begin(), rem.end());
    int n = cur.size();
    if (rem.size() > B)
        no();
    assert(n <= B);
    assert(n >= 3);

    int sum = 0;
    for (int x : cur)
        sum = add(x, sum);


    for (int x : cur) {
        int bon = sum;
        bon = sub(bon, mul(n, x));
        bon = mul(bon, inv((n * (n - 1) / 2) % mod));

        int d = bon;
        if (d == 0)
            continue;

        bool good = true;
        for (int i = 0; i < n; ++i)
            good &= (rem.find(add(x, mul(i, d))) != rem.end());
        if (good)
            return d;
    }

    no();
    return -1;
}

void kill() {
    if (mod == 2) {
        ans(a[0], 1);
    }

    if (n == mod)
        ans(0, 1);

    //if (n == 1)
        //ans(a[0], 1);
    
    //if (n == 2)
        //ans(a[0], sub(a[1], a[0]));

    if (n > mod - n) {
        change();
    }

    int d = solve();

    if (chan)
        change();

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum = add(sum, a[i]);

    sum = sub(sum, mul((1ll * n * (n - 1) / 2) % mod, d));
    sum = mul(sum, inv(n));
    int x = sum;

    rem = set<int>(a, a + n);
    for (int i = 0; i < n; ++i)
        if (!rem.count(add(x, mul(i, d))))
            no();

    ans(x, d);
}

int main() {
#ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);

    read();
    kill();
}