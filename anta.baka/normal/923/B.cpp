#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//#undef _GLIBCXX_DEBUG //(compiler options)
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
using namespace std;
using ll = long long; using ull = unsigned ll; using ld = long double; using pii = pair<int, int>; using pll = pair<ll, ll>; using vi = vector<int>;
template<typename T> T mind(T &x, const T &y) {if (y < x) {T d = y-x; x = y; return d;} else return 0;} //RETURNS A NON-POSITIVE VALUE
template<typename T> T maxd(T &x, const T &y) {if (y > x) {T d = y-x; x = y; return d;} else return 0;}
const int mod = 1e9+7, mod9 = 1e9+9, infi = 1e9+100; const ll infl = 1e18L+1000, modl = 1e18L+3; const ld infd = INFINITY;

#define x(a) real(a)
#define y(a) imag(a)
using G = ll; using point = complex<G>;
istream& operator>>(istream &is, point &p){G x, y; is >> x >> y; p = {x, y}; return is;}
ostream& operator<<(ostream &os, const point &p){os << p.x() << ' ' << p.y(); return os;}
G dot(const point &a, const point &b) {return (conj(a)*b).x();}
G crs(const point &a, const point &b) {return (conj(a)*b).y();}
G ori(const point &a, const point &b, const point &c) {return crs(b-a, c-b);};
bool cmpyx(const point &a, const point &b) {return a.y()<b.y() || (a.y()==b.y()&&a.x()<b.x());};


signed main()
{
    #ifndef LOCAL
    //ifstream cin("hull.in"); ofstream cout("hull.out");
    #endif // LOCAL
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout << fixed << setprecision(15);
    int n; cin >> n;
    vector<ll> v(n), t(n);
    for(auto &x : v) cin >> x;
    for(auto &x : t) cin >> x;
    vector<ll> s(n+1); partial_sum(all(t), s.begin()+1);
    multiset<pair<ll, ll>> st;
    for(int i = 0; i < n; ++i) {
        ll x = v[i];
        int j = upper_bound(all(s), s[i]+x)-s.begin(); --j;
        //cout << i << ' ' << j << endl;
        maxd(j, i);
        st.insert({j, x-(s[j]-s[i])});
        ll add = 0;
        for(auto it = st.begin(); it != st.end() && it->fst == i; it = st.erase(it)) {
            add += it->snd;
        }
        cout << sz(st)*t[i]+add << ' ';
    }
}