#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const ll base = 1000;
const ll gl_base = base;
const ll dig = 3;

const double PI = acos(-1.00);

struct comx {
    double a, b;

    bool operator=(double x) {
        a = x; b = 0;
    }

    comx operator+(comx who) {
        return {a + who.a, b + who.b};
    }

    comx operator-(comx who) {
        return {a - who.a, b - who.b};
    }

    comx operator*(comx who) {
        return {a * who.a - b * who.b, a * who.b + b * who.a};
    }

    comx operator/(double x) {
        return {a / x, b / x};
    }
};

vector<comx> aux;

void rev(int l, int r, comx* data) {
    if (l == r) return;

    int i, p = l;
    for (i = l; i <= r; i++) aux[i] = data[i];
    for (i = l; i <= r; i += 2) data[p++] = aux[i];
    for (i = l + 1; i <= r; i += 2) data[p++] = aux[i];

    int mid = (l + r) >> 1;
    rev(l, mid, data);
    rev(mid + 1, r, data);
}

void fft(int dim, comx* data, double sgn) {
    int i, j, len;
    comx w, r, u, v;

    aux.resize(dim + 11);
    rev(0, dim - 1, data);

    for (len = 1; 2 * len <= dim; len <<= 1) {
        r = {cos(PI / len), sin(sgn * PI / len)};

        for (i = 0; i < dim; i += 2 * len) {
            w = 1;

            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = u + w * v;
                data[i + len + j] = u - w * v;
                w = w * r;
            }
        }
    }

    if (sgn < 0.00) {
        for (i = 0; i < dim; i++)
            data[i] = data[i] / dim;
    }
}

vector<comx> A, B;

void poly_mult(vector<ll>& s1, vector<ll>& s2, vector<ll>& dest) {
    int sz = 1;
    int i, j;

    if (min(s1.size(), s2.size()) <= 3) {
        for (i = 0; i < s1.size(); i++)
            for (j = 0; j < s2.size(); j++)
                dest[i + j] += s1[i] * s2[j];
        return;
    }

    while (sz < dest.size()) sz <<= 1;
    A.reserve(sz);
    B.reserve(sz);
    A.clear(); B.clear();
    

    for (auto e : s1) A.pb({1.00 * e, 0.00});
    for (auto e : s2) B.pb({1.00 * e, 0.00});
    while (A.size() < sz) A.pb({0.00, 0.00});
    while (B.size() < sz) B.pb({0.00, 0.00});

    fft(sz, &A[0], 1.00);
    fft(sz, &B[0], 1.00);

    for (i = 0; i < sz; i++) A[i] = A[i] * B[i];
    fft(sz, &A[0], -1.00);

    for (i = 0; i < dest.size(); i++)
        dest[i] = llround(A[i].a);
}

struct bigint {
    vector<ll> data;

    void init(ll nr) {
        data = {nr};
    }

    bigint(ll x) {
        init(x);
    }

    bigint() {
        init(0);
    }
    
    void print() {
        for (int i = data.size() - 1; i >= 0; i--)
            cerr << data[i] << ", ";
    }

    void read() {
        static string s;
        static ll i, j, aux;

        cin >> s;
        reverse(s.begin(), s.end());
        while (s.size() % dig != 0) s.pb('0');

        data.clear();
        for (i = 0; i < s.size(); i += dig) {
            aux = 0;
            for (j = dig - 1; j >= 0; j--)
                aux = (aux * 10) + (s[i + j] - '0');
            data.pb(aux);
        }
    }

    bigint operator*(bigint& who) {
        static ll i, j;
        bigint ans;
        ans.data.resize(data.size() + who.data.size());
        poly_mult(data, who.data, ans.data);

        for (i = 0; i + 1 < ans.data.size(); i++) {
            ans.data[i + 1] += ans.data[i] / base;
            ans.data[i] %= base;
        }

        while (ans.data.size() > 1) {
            if (ans.data.back() != 0) break;
            ans.data.pop_back();
        }
        
/*        cerr << "Multip\n";
        print(); cerr << "\n";
        who.print(); cerr << "\n";
        ans.print(); cerr << "\n\n";
*/

        return ans;
    }

    bool operator<(const bigint& who) {
        if (data.size() > who.data.size()) return false;
        if (data.size() < who.data.size()) return true;

        for (int i = data.size() - 1; i >= 0; i--) {
            if (data[i] < who.data[i])
                return true;
            if (data[i] > who.data[i])
                return false;
        }

        return false;
    }
};

void brute() {
    vector<int> data;
    int i;

    data = {0, 1, 2, 3};
    for (i = 4; i <= 50; i++) {
        data.pb(max(data[i - 2] * 2, data[i - 3] * 3));
        cerr << i << ' ' << data[i] << ' ';
        if (data[i] == 3 * data[i - 3]) cerr << "P3";
        cerr << '\n';
    }

}

bigint n;
vector<bigint> pows;
ll ans;

bigint init_bigint;
ll init_ans;

void check(ll base) {
    bigint act, aux;
    ll loc_ans = base + init_ans;
    ll i;
    
    act = ((bigint)base) * init_bigint;
    for (i = min((int)pows.size() - 1, 2); i >= 0; i--) {
        if (act.data.size() + pows[i].data.size() - 1 > n.data.size()) continue;
        
        aux = act * pows[i];
        if (aux < n) {
            act = aux;
            loc_ans += 3LL * (1LL << i);
        }
    }

    loc_ans += 3LL;
    ans = min(ans, loc_ans);
}


void get_ini(ll base) {
    bigint act, aux;
    ll i;
    
    act = base;
    
    ll act_dim = 1;
    vector<ll> who = {};
    for (i = pows.size() - 1; i >= 0; i--) {
        if (act_dim + pows[i].data.size() < n.data.size()) {
            act_dim += pows[i].data.size();
            who.pb(i);
            init_ans += 3LL * (1LL << i);
        }
    }
    reverse(who.begin(), who.end());
    for (auto e : who) {
        act = act * pows[e];
    }
    
    for (i = pows.size() - 1; i >= 0; i--) {
        if (act.data.size() + pows[i].data.size() - 1 > n.data.size()) continue;
        if (act.data.size() + pows[i].data.size() < n.data.size()) {
            act = act * pows[i];
            init_ans += 3LL * (1LL << i);
            continue;
        }

        aux = act * pows[i];

        if (aux < n) {
            act = aux;
            init_ans += 3LL * (1LL << i);
        }
    }

    for (int i = act.data.size() - 1; i > 0; i--) {
        act.data[i - 1] += (act.data[i] % base) * gl_base;
        act.data[i] /= base;
    }
    act.data[0] /= base;

    while (act.data.back() == 0) act.data.pop_back();
    init_bigint = act;
}

int main()
{
    //freopen("test.in","r",stdin);

    //brute();
    n.read();
   
    if (n.data.size() == 1) {
        if (n.data[0] <= 4) {
            printf("%lld", n.data[0]);
            return 0;
        }
    }

    pows = {3};

    while (!(n < pows.back())) {
        if (pows.back().data.size() * 2 - 1 > n.data.size()) break;
        pows.pb(pows.back() * pows.back());
        if (n < pows.back()) {
            pows.pop_back();
            break;
        }
        cerr << ' ' << pows.size() << ' ' << pows.back().data.size() << '\n';
    }

    cerr << "DONE\n";

    time_t t1 = clock();
    get_ini(4);
    time_t t2 = clock();
    cerr << (1.00 * t2 - t1) / CLOCKS_PER_SEC << " s\n";

    cerr << init_ans << '\n';
    
    t1 = clock();

    ans = 1LL << 60;
    check(2);
    check(3);
    check(4);

    t2 = clock();
    cerr << (1.00 * t2 - t1) / CLOCKS_PER_SEC << " s\n";

    printf("%lld", ans);

    return 0;
}