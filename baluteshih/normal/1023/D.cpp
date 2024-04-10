#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif
 
vector<int> pl[200005], stk;
set<int> s;
int arr[200005], lft[200005], vis[200005];
 
int main()
{
    IOS();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (arr[i])
            pl[arr[i]].pb(i);
        else
            s.insert(i);
    }
    if (!s.empty() && pl[q].empty())
        arr[*s.begin()] = q, s.erase(s.begin());
    for (int i = q; i > 0; --i)
        if (SZ(pl[i]) >= 2)
            for (auto p = s.lower_bound(pl[i][0]); p != s.end() && *p <= pl[i].back(); p = s.erase(p))
                arr[*p] = i;
    if (!arr[1])
        arr[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (!arr[i])
            arr[i] = 1;
    for (int i = 1; i <= n; ++i) {
        while (!stk.empty() && arr[stk.back()] > arr[i])
            stk.pop_back();
        if (!stk.empty() && vis[arr[i]] && arr[stk.back()] != arr[i])
            return cout << "NO\n", 0;
        stk.pb(i), vis[arr[i]] = 1;
    }
    if (!vis[q])
        return cout << "NO\n", 0;
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << arr[i] << " \n"[i == n];
}