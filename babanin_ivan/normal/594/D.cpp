#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

const li mod = 1000000007;

int n;

li bpow(int x, int y) {
    if (y == 0) {
        return 1;
    }
    li rec = bpow(x, y >> 1);
    rec = (rec * rec) % mod;
    if (y & 1) {
        rec = (rec * x) % mod;
    }
    return rec;
}

struct query {
    int l, r;
    int id;
    query(){}
    query(int l, int r, int id) :l(l), r(r), id(id){}
    bool operator < (const query& oth) const {
        return l < oth.l;
    }
};

vector <int> anses;

const int treesz = 2 * 131072;
int rpq[2 * treesz + 100];

int getprod(int L, int R, int i, int l, int r) {
    if (R <= l || r <= L) {
        return 1;
    }
    if (l <= L && R <= r) {
        return rpq[i];
    }
    int m = (L + R) / 2;
    return (li(getprod(L, m, 2 * i, l, r)) * getprod(m, R, 2 * i + 1, l, r)) % mod;
}

void modify(int j, int x) {
    j += treesz;
    rpq[j] = (li(rpq[j]) * x) % mod;
    while (j != 1) {
        j /= 2;
        rpq[j] = (li(rpq[2 * j]) * rpq[2 * j + 1]) % mod;
    }
}

void solve() {
    for (int i = 0; i <= 2 * treesz; ++i) {
        rpq[i] = 1;
    }

    cin >> n;
    vector <int> a(n);

    vector <pair <int, int> > prs;
    vector <vector <int> > facts(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int x = a[i];
        for (int j = 2; x != 1 && j * j <= x; ++j) {
            if (x % j == 0) {
                prs.push_back(mp(j, i));
                facts[i].push_back(j);
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x != 1) {
            facts[i].push_back(x);
            prs.push_back(mp(x, i));
        }
    }

    map <int, int> librev;

    sort(all(prs));
    for (int i = 0; i < prs.size(); ++i) {
        if (i == 0 || prs[i - 1].first != prs[i].first) {
            int revp = (1 - bpow(prs[i].first, mod - 2) + mod) % mod;
            librev[prs[i].first] = revp;
            modify(prs[i].second, revp);
        }
    }

    vector <li> prefs(n + 1);
    prefs[0] = 1;
    for (int i = 1; i <= n; ++i) {
        prefs[i] = (li(prefs[i - 1]) * a[i - 1] )% mod;
    }

    int q;
    cin >> q;
    vector <query> qs(q);
    anses.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].l >> qs[i].r;
        --qs[i].l;
        qs[i].id = i;
    }
    sort(all(qs));

    int pointer = 0;
    for (int i = 0; i < n; ++i) {
        while (pointer < qs.size() && qs[pointer].l == i) {
            li res1 = getprod(0, treesz, 1, qs[pointer].l, qs[pointer].r);
            li res2 = prefs[qs[pointer].r] * bpow(prefs[qs[pointer].l], mod - 2);
            res2 %= mod;
            anses[qs[pointer].id] = res1 * res2 % mod;
            ++pointer;
        }
        for (int x : facts[i]) {
            int ind = lower_bound(all(prs), mp(x, i)) - prs.begin();
            ++ind;
            if (ind < prs.size() && prs[ind].first == x) {
                modify(prs[ind].second, librev[x]);
            }
        }
    }

    for (int i = 0; i < anses.size(); ++i) {
        cout << anses[i] << "\n";
    }
}