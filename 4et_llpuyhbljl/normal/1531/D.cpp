//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
//#pragma comment(linker, "/STACK:36777216")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
#define pb push_back
#define eb emplace_back
#define F first
#define S second

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;
ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-7, pi = acosl(-1);
const ll maxN = 100010, maxT = 1000000, A = 263;
void panic() {
    cout << "-1\n";
    exit(0);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
int n;
string a[maxN];
set<int>id_l, id_un;
set<pair<int, int>>seg;
void add(int l, int r) {
    if (l > r)return;
    auto it = seg.lower_bound({ l,INF });
    int l1, r1, l2, r2;
    if (it == seg.end())l2 = r2 = INF;
    else tie(l2, r2) = *it;
    if (it == seg.begin())l1 = r1 = -INF;
    else tie(l1, r1) = *(--it);
    if (l1 <= l && r <= r1)return;
    if (l <= r1 + 1 && r1 <= r) {
        seg.erase(it);
        l = l1;
    }
    if (l <= l2 && l2 - 1 <= r) {
        seg.erase({ l2,r2 });
        r = max(r2, r);
    }
    seg.insert({ l,r });
}
void del(int l, int r) {
    if (l > r)return;
    auto it = seg.lower_bound({ l,INF });
    --it;
    int l1, r1;
    tie(l1, r1) = *it;
    seg.erase(it);
    if (l1 < l)seg.insert({ l1,l - 1 });
    if (r < r1)seg.insert({ r + 1,r1 });
}
string ans() {
    return a[(*seg.rbegin()).first - 1];
}
void solve() {
    cin >> n;
    //vector<string>a(n + 2);
    a[0] = "blue";
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        a[i + 1] = t;
        int vll = -INF;
        if (t[0] == 'l') {
            id_l.insert(i + 1);
        }
        if (t[0] == 'u') {
            id_un.insert(i + 1);
        }
    }
    a[n + 1] = "unlock";
    id_un.insert(n + 1);
    for (auto l : id_l) {
        int r = *id_un.lower_bound(l);
        add(l, r);
        //add(l, l);
    }
    for (auto x : id_un)add(x, x);
    cout << ans() << "\n";
    int q;
    cin >> q;
    while (q--) {
        int id;
        cin >> id;
        if (a[id][0] == 'l') {
            auto it1 = id_un.lower_bound(id);
            auto it = id_l.upper_bound(id);
            int r = *it1 - 1;
            bool f = 1;
            if (it != id_l.end()) {
                r = min(r, (*it) - 1);
            }
            --it;
            if (it != id_l.begin()) {
                if (it1 == id_un.begin()) {
                    f = 0;
                }
                else {
                    --it;
                    --it1;
                    if (*it > *it1)f = 0;
                    ++it;
                    ++it1;
                }
            }
            if (f) del(id, r);
            id_l.erase(it);
        }
        if (a[id][0] == 'u') {
            auto it = id_l.lower_bound(id);
            id_un.erase(id);
            if (it != id_l.begin()) {
                --it;
                auto tmp = id_un.lower_bound(*it);
                if (*tmp > id) {
                    add(id, *tmp);
                }
                else {
                    del(id, id);
                }
            }
            else del(id, id);
        }
        cin >> a[id];
        if (a[id][0] == 'l') {
            add(id, *id_un.lower_bound(id));
            id_l.insert(id);
        }
        if (a[id][0] == 'u') {
            auto it = id_l.lower_bound(id);
            if (it != id_l.begin()) {
                --it;
                auto tmp = id_un.lower_bound(*it);
                if (*tmp > id) {
                    int r = *tmp - 1;
                    ++it;
                    if (it != id_l.end()) {
                        r = min(r, *it - 1);
                    }
                    del(id + 1, r);
                }
                else {
                    add(id, id);
                }
            }
            else {
                add(id, id);
            }
            id_un.insert(id);
        }
        cout << ans() << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);
    // srand(time(0));
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}