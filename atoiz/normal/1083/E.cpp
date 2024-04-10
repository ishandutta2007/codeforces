#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>
 
const int MAXN = 1000007;
 
using namespace std;
using ll = long long;
 
const ll INF = 1e17;
 
struct CHT
{
    using pll = pair<ll, ll>;
    #define a first
    #define b second
 
    vector<pll> vec;
    int ptr = 0;
 
    ll val(int i, ll x) { return vec[i].a * x + vec[i].b; }
    bool bad(pll p0, pll p1, pll p2) { return 1.0 * (p1.a - p0.a) * (p2.b - p0.b) - 1.0 * (p2.a - p0.a) * (p1.b - p0.b) >= 1e-7; } // overflow?
    void add(ll a, ll b)
    {
        for (pll p(a, b); (int) vec.size() > 1 && bad(p, vec[(int) vec.size() - 1], vec[(int) vec.size() - 2]); vec.pop_back());
        vec.emplace_back(a, b);
        ptr = min(ptr, (int) vec.size() - 1);
    }
 
    ll get(ll x)
    {
        assert(!vec.empty());
        for (; ptr + 1 < (int) vec.size() && val(ptr, x) <= val(ptr + 1, x); ++ptr);
        return val(ptr, x);
    }
} cht;
 
int N;
tuple<ll, ll, ll> rects[MAXN];
ll F[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        ll x, y, a;
        cin >> x >> y >> a;
        rects[i] = make_tuple(x, y, a);
    }
    sort(rects, rects + N);
    cht.add(0, 0);
    for (int i = 0; i < N; ++i) {
        F[i] = cht.get(get<1>(rects[i])) + get<0>(rects[i]) * get<1>(rects[i]) - get<2>(rects[i]);
        cht.add(-get<0>(rects[i]), F[i]);
        // cout << F[i] << ' ';
    }
    // cout << endl;
    cout << *max_element(F, F + N) << endl;
}