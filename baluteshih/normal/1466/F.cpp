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

const int MOD = 1e9+7;
int tag[500005];
vector<int> ans;

int finds(int x) {
    if (tag[x] == 0 || tag[x] == -1)
        return x;
    return tag[x] = finds(tag[x]);
}

int main() {
    IOS();
    int n, m;
    int nw = 1;
    cin >> n >> m;
    fill(tag, tag + m + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int k, a, b;
        cin >> k;
        if (k == 1)
            cin >> a, b = 0;
        else 
            cin >> a >> b;
        if (a > b && b != 0) swap(a, b);
        while (~tag[a]) {
            if (tag[a] == 0)
                a = b, b = 0;
            else
                a = finds(a);
            if (a > b && b != 0) swap(a, b);
            if (a == b) a = b = 0;
        }
        if (a != 0)
            nw = nw * 2 % MOD, tag[a] = b, ans.pb(i);
    }
    cout << nw << " " << SZ(ans) << "\n";
    for (int i = 0; i < SZ(ans); ++i)
        cout << ans[i] << " \n"[i + 1 == SZ(ans)];
}