#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define err(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int N = 1 << 20;

int t[2 * N];
int a[N];

int get(int l, int r) {
    int ans = 0;
    l += N;
    r += N;
    while (l <= r) {
        if (l & 1) ans = max(ans, t[l]);
        if (!(r & 1)) ans = max(ans, t[r]);
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return ans;
}

void add(map<int, int> *m, int &total, int x) {
    total = (total + x) % mod;
    int cnt = 1;
    vector<pair<int, int>> v;
    for (auto it : *m) {
        if (it.first > x) break;
        v.push_back(it);
        total = (total + (x - it.first) * (ll)it.second) % mod;
        cnt += it.second;
    }
    for (auto it : v) {
        (*m).erase(it.first);
    }
    (*m)[x] = cnt;
}


        


int r[N];
map<int, int> *m[N];


int main()
{
    #ifdef amit
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n, k;

    if (1) {
        scanf("%d%d", &n, &k);
        forn(i, n) scanf("%d", &a[i]);
    } else {
        mt19937 rnd;
        n = 1000000;
        k = 1000;
        forn(i, n) a[i] = rnd() % (int)1e9;
    }
    
    forn(i, n) t[i + N] = a[i];
    for (int i = N - 1; i > 0; i--) t[i] = max(t[2 * i], t[2 * i + 1]);

    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i + k <= n) {
            r[i] = r[i + k - 1];
            m[i] = m[i + k - 1];
            add(m[i], r[i], get(i, i + k - 1));
        } else {
            m[i] = new map<int, int>();
        }
        total = (total + r[i]) % mod;
    }
    printf("%d\n", total);


    return 0;
}