#include<bits/stdc++.h>
using namespace std ;
// 
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
#define debug(...) 2401
#endif

struct TRIE {
    vector<array<int, 2>> next;
    vector<long long> cnt;
    static const int B = 60;
    int root, cur;

    TRIE() {
        next.push_back({-1, -1});
        cnt.push_back(0);
        root = 0;
        cur = 1;
    }
    void insert(long long x) {
        int tmp = root;
        ++cnt[tmp];
        for(int i=B;i>=0;--i) {
            int t = (x >> i) & 1;
            if(next[tmp][t] == -1) {
                next[tmp][t] = cur++;
                next.push_back({-1, -1});
                cnt.push_back(0);
            }
            tmp = next[tmp][t];
            ++cnt[tmp];
        }
    }
    void erase(long long x) {
        int tmp = root;
        --cnt[tmp];
        for(int i=B;i>=0;--i) {
            tmp = next[tmp][(x >> i) & 1];
            --cnt[tmp];
        }
    }
    long long q_max(long long x) {
        int tmp = root;
        long long ans = 0;
        if(cnt[tmp] == 0) {
            return -1;
        }
        for(int i=B;i>=0;--i) {
            int t = (x >> i) & 1;
            if(next[tmp][1 - t] != -1 && cnt[next[tmp][1 - t]] > 0) {
                tmp = next[tmp][1 - t];
                ans += 1LL << i;
            }
            else {
                tmp = next[tmp][t];
            }
        }
        return ans;
    }
    void clear() {
        next.clear();
        cnt.clear();
        root = 0;
        next.push_back({-1, -1});
        cnt.push_back(0);
        cur = 1;
    }
};
// change msb accordingly


int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    TRIE tr;
    if(k == 0) {
        cout << n << "\n";
        for(int i=1;i<=n;++i) {
            cout << i << " ";
        }
        return 0;
    }
    int msb = 0;
    for(int i=0;i<30;++i) {
        if(k & (1 << i)) {
            msb = i;
        }
    }
    int mask = ((1 << 30) - 1) ^ ((1 << (msb + 1)) - 1);
    map<int,vector<int>> mp;
    map<int,int> id;
    for(int i=1;i<=n;++i) {
        mp[mask & a[i]].push_back(i);
        id[a[i]] = i;
    }
    vector<int> ans;
    for(auto &[m, v]:mp) {
        if(sz(v) <= 1) {
            ans.push_back(v[0]);
            continue;
        }
        tr.clear();
        int f = -1, g = -1;
        for(auto &j:v) {
            tr.insert(a[j]);
            int u = tr.q_max(a[j]);
            if(u >= k) {
                f = j, g = id[u^a[j]];
                break;
            }
        }
        if(f != -1) {
            ans.push_back(f), ans.push_back(g);
        }
        else {
            ans.push_back(v[0]);
        }
    }
    if(sz(ans) < 2) {
        cout << "-1\n";
        return 0;
    }

    cout << sz(ans) << "\n";
    for(auto i:ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
// 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}