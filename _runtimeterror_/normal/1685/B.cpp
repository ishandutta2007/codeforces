#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    string t;
    int pos = 0;
    t += s[0];
    int n = s.size();
    vector<int> cc, dd;
    int a_cnt = count(all(s), 'A'), b_cnt = count(all(s), 'B');
    if(a + c + d != a_cnt or b + c + d != b_cnt) {
        cout << "NO\n";
        return 0;
    }
    for(int i=1;i<n;++i) {
        if(s[i] == s[i - 1]) {
            if(sz(t) & 1) {
                pos += (sz(t) - 1) / 2;
            }
            else {
                if(t[0] == 'A') {
                    cc.push_back(sz(t) / 2);
                }
                else {
                    dd.push_back(sz(t) / 2);
                }
            }
            t.clear();
            t += s[i];
        }
        else {
            t += s[i];
        }
    }
    if(sz(t) & 1) {
        pos += (sz(t) - 1) / 2;
    }
    else {
        if(t[0] == 'A') {
            cc.push_back(sz(t) / 2);
        }
        else {
            dd.push_back(sz(t) / 2);
        }
    }
    sort(all(cc)), sort(all(dd));
    for(auto &i:cc) {
        if(c >= i) {
            c -= i;
        }
        else {
            pos += i - 1;
        }
    }
    for(auto &i:dd) {
        if(d >= i) {
            d -= i;
        }
        else {
            pos += i - 1;
        }
    }
    if(pos >= c + d) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}