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

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}



template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(char c) {
    string t = "'" + string(1,c) + "'";
    return t;
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for(size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}


template<typename T>
void debug_out(const char* name, T&& x) { 
    cerr << "[" << name << "] : " << to_string(x) << endl; 
}
template <typename H, typename... T>
void debug_out(const char* names, H&& arg1, T&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr << "[";
    cerr.write(names, comma - names) << "] : " << to_string(arg1) <<"\n";
    debug_out(comma+1, args...);
}
#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

int _runtimeTerror_()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,char>> c(n);
    vector<pll> l,r;
    vector<ll> ans(n,-1);
    for(int i=0;i<n;++i)
        cin>>c[i].F;
    for(int j=0;j<n;++j)
        cin>>c[j].S;
    for(int i=0;i<n;++i)
    {
        if(c[i].F & 1)
            l.push_back({c[i].F,i});
        else
            r.push_back({c[i].F,i});
    }
    auto solve = [&](vector<pll> a)
    {
        sort(all(a));
        debug(a);
        vector<pll> st;
        if(a.empty())
            return ;
        st.push_back(a[0]);
        for(int i=1;i<sz(a);++i)
        {
            auto [d,id] = a[i];
            if(c[id].S == 'R')
            {
                st.push_back(a[i]);
                continue;
            }
            if(!st.empty())
            {
                auto f = st.back();
                ll val = 0;
                if(c[f.S].S == 'L')
                {
                    val += f.F;
                    a[i].F -= (f.F - 0);
                    f.F = 0;
                }
                val += abs(f.F - a[i].F)/2;
                ans[a[i].S] = ans[f.S] = val;
                st.pop_back();
            }
            else
            {
                st.push_back(a[i]);
                continue;
            }
            debug(i,st);
        }
        debug(st.size());
        while(st.size() >= 2)
        {
            auto b = st.back();
            st.pop_back();
            auto f = st.back();
            st.pop_back();
            assert(c[b.S].S == 'R');
            ll val = 0;
            val += m - b.F;
            b.F = m;
            if(c[f.S].S == 'L')
                val += f.F,f.F = 0;
            val += abs(f.F - b.F);
            ans[b.S] = ans[f.S] = val/2;
        }
    };
    solve(l),solve(r);
    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}