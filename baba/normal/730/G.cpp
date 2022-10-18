// Willpower alone isn't enough in battle 
// You know that, *
// Defeating ** will require far more..
// ~ Armin Arlert, SnK

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;

typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl '\n'
II ans[5000];
int main()
{
    fast_io;
    int n;
    cin >> n;
    set<II> s;
    s.insert({1,int(1.5e9)});
    for(int i=0;i<n;i++) {
        int si, di;
        cin >> si >> di;
        auto it = s.upper_bound({si,0});
        if(it!=s.begin()) {
            it--;
            if(it->F <= si && it->S >= si + di - 1)
            {
                ans[i].F = si;
                ans[i].S = si + di - 1;
                int ff = it->F;
                int ss = it->S;
                s.erase(it);
                int fe = si - 1;
                //trace(ff,ss,fe);
                if(fe - ff >= 0)
                    s.insert({ff,fe});
                if(ss - si + di  >= 0)
                    s.insert({si + di, ss});
                continue;
            }
        }
        for(auto el:s) {
            if(el.S - el.F + 1 >= di)
            {
                int be = el.F;
                int en = el.S;
                s.erase(el);
                if(en - be + 1 > di)
                    s.insert({be + di, en});
                ans[i].F = be;
                ans[i].S = be + di - 1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << ans[i].F << " " << ans[i].S << endl;
    return 0;
}