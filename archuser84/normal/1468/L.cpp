#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

typedef uint64_t u64;
typedef __uint128_t u128;
const int N = 1'010;
int n, k;

bool miler_rabin(u128 b, u64 p)
{
    int k = __builtin_ctzll(p-1);
    u128 t = b; b = 1;
    Loop(i,k,64)
    {
        if((p-1)&(1llu<<i)) b = (b*t)%p;
        t = (t*t)%p;
    }
    bool z = 0;
    if(b == 1) z = 1;
    Loop(_,0,k)
    {
        if(b == p-1) z = 1;
        b = (b*b)%p;
    }
    if(b != 1) return 0;
    if(!z) return 0;
    return 1;
}

bool isPrime(u64 p)
{
    if(p < 2) return 0;
    for(int d : {2, 3, 5, 7, 11}) if(p%d == 0) return p == d;
    Loop(_,0,10) if(!miler_rabin(rand()%(p-2)+2, p)) return 0;
    return 1;
}

u64 root(u64 x, int n)
{
    u64 l = 1, r = x;
    while(l < r)
    {
        u64 m = (l+r+1)/2;
        u128 p = 1;
        Loop(_,0,n){
            p = p*m;
            if(p > x) break;
        }
        if(p > x) r = m-1;
        else      l = m;
    }
    return l;
}

u64 isPowPrime(u64 p)
{
    for(int n = 1;; ++n)
    {
        u64 x = root(p, n);
        if(x == 1) return 0;
        u64 y=1; Loop(_,0,n) y=y*x;
        if(y == p && isPrime(x)) return x;
    }
}

u64 a[N];
unordered_set<u64> ps;
unordered_map<u64, vector<u64>> mvs;
vector<vector<u64>> vs;


int main()
{
    srand(time(0));
    //FAST;
    cin >> n >> k;
    Loop(i,0,n)
    {
        cin >> a[i];
        u64 p = isPowPrime(a[i]);
        if(p){
            mvs[p].push_back(a[i]);
            a[i] = 0;
        }
    }
    if(k <= 1) Kill(0);
    u64 zzz = 0;
    vector<u64> ans;
    for(auto& m : mvs){if(m.S.size() > 1) vs.push_back(m.S), ps.insert(m.F);}
    sort(all(vs), [](vector<u64>& a, vector<u64>& b){return a.size() > b.size();});
    for(auto& v : vs)
    {
        ans.push_back(v.back()); v.pop_back();
        ans.push_back(v.back()); v.pop_back();
        if(v.size() && !zzz) zzz = v.back();
    }
    if(k <= ans.size())
    {
        if((k&1) && !zzz){
            Loop(i,0,n)
            {
                if(!a[i]) continue;
                vector<u64> ds;
                u64 x = a[i];
                for(u64 p : ps) if(x%p == 0){ ds.push_back(p); while(x%p == 0) x /= p; }
                if(x != 1) continue;
                if(ds.size() > k/2) continue;
                cout << a[i] << ' ';
                for(auto d : ds) {for(auto x : mvs[d]) cout << x << ' '; mvs[d].clear();}
                k = k - 2*ds.size() - 1;
                if(!k) return 0;
                for(auto& m : mvs)
                {
                    if(m.S.size() < 2) continue;
                    for(auto x : m.S) cout << x << ' ';
                    k -= 2;
                    if(!k) return 0;
                }
            }
            Kill(0);
        }
        if(k&1) cout << zzz << ' ', k--;
        Loop(i,0,k) cout << ans[i] << ' ';
        return 0;
    }
    for(auto& v : vs)
    {
        while(v.size())
            ans.push_back(v.back()),
            v.pop_back();
    }
    Loop(i,0,n)
    {
        if(!a[i]) continue;
        u64 x = a[i];
        for(u64 p : ps) while(x%p == 0) x /= p;
        if(x == 1) ans.push_back(a[i]);
    }
    if(ans.size() < k) Kill(0);
    Loop(i,0,k) cout << ans[i] << ' ';
}