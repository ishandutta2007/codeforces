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

string s;
const int INF = 1e9;
int dp[100005][4];

int main() {
    IOS();
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        if (SZ(s) == 1) {
            cout << "0\n";
            continue;
        }
        int a = 0, b = 0, ans = 0;
        for (int i = 1; i < SZ(s); ++i) {
            if ((s[i] == s[i - 1] && !b) || (i >= 2 && s[i] == s[i - 2] && !a))
                a = b, b = 1, ++ans;
            else
                a = b, b = 0;
        }
        cout << ans << "\n";
    }
}