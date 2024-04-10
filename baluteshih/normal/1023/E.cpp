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

pii operator+(const pii &a, const pii &b){return pii(a.X + b.X, a.Y + b.Y);}

vector<pii> vec;
int n;

bool query(pii a, pii b) {
    assert(abs(a.X - b.X) + abs(a.Y - b.Y) >= n - 1);
    cout << "? " << a.X << " " << a.Y << " " << b.X << " " << b.Y << endl;
    string s;
    cin >> s;
    return s == "YES";
}

int main() {
    IOS();
    string ans, bk;
    cin >> n;
    pii nw = pii(1, 1), ed = pii(n, n);
    for (int i = 1; i < n; ++i) {
        vec.pb(nw);
        if (query(nw + pii(0 ,1), ed) == 1)
            nw = nw + pii(0, 1), ans.pb('R');
        else
            nw = nw + pii(1, 0), ans.pb('D');
    }
    nw = ed;
    for (int i = 1; i < n; ++i) {
        if (query(vec.back(), nw + pii(-1, 0)) == 1)
            nw = nw + pii(-1, 0), bk.pb('D');
        else
            nw = nw + pii(0, -1), bk.pb('R');
        vec.pop_back();
    }
    reverse(ALL(bk));
    cout << "! " << ans << bk << endl; 
}