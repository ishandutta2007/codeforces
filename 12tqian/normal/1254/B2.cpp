#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++) 
#define f0r(i, a) f1r(i, 0, a)
#define F0R(i, a) f0r(i, a)
#define trav(t, a) for (auto& t : a)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;


namespace factorBasic {
    template<class T> vector<pair<T,int>> factor(T x) { 
        vector<pair<T,int>> pri;
        for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.pb({i,t});
        }
        if (x > 1) pri.pb({x,1});
        return pri;
    }
    /* Note:
     * number of operations needed s.t.
     *                phi(phi(...phi(n)...))=1
     * is O(log n).
     * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
     */
    ll phi(ll x) {
        trav(a,factor(x)) x -= x/a.f;
        return x;
    }
    template<class T> void tour(vector<pair<T,int>>& v, 
        vector<T>& V, int ind, T cur) {
            if (ind == sz(v)) V.pb(cur);
            else {
                T mul = 1;
                F0R(i,v[ind].s+1) {
                    tour(v,V,ind+1,cur*mul);
                    mul *= v[ind].f;
                }
            }
        }
    template<class T> vector<T> getDivi(T x) {
        auto v = factor(x);
        vector<T> V; tour(v,V,0,(T)1); sort(all(V));
        return V;
    }
}
int main() {
    using namespace factorBasic;
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi a(n);
    f0r(i, n) cin >> a[i];
    ll sum = 0; f0r(i, n) sum += a[i];
    if (sum == 1) {
        cout << -1 << '\n';
        return 0;
    }
    auto f = factor(sum);
    vl pr;
    for (auto x : f) pr.eb(x.f);
    vl pre(n);
    f0r(i, n) {
        pre[i] = (i?pre[i-1]:0) + a[i];
    }
    auto get = [&](int l, int r) -> ll {
        return pre[r]-(l?pre[l-1]:0);
    };
    vl b(n);
    ll ans = 1e18;
    vl bef(n);
    vl aft(n);
    for (ll p : pr) {
        ll res = 0;
        f0r(i, n) {
            res += min(pre[i]%p, p-(pre[i]%p));
        }
        ans = min(ans, res);
    }   
    cout << ans << '\n';
    return 0;
}