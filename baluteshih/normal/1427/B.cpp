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
pii stk[100005];
int top;

int main() {
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n, k, beg = -1, bk, ls = 0, ans = 0;
        cin >> n >> k >> s;
        for (int i = 0; i < n; ++i)
            if (s[i] == 'W') {
                beg = i;
                break;
            }
        if (beg == -1) {
            for (int i = 0; i < k; ++i)
                s[i] = 'W';
        }
        else {
            bk = beg, top = 0;
            for (int i = beg + 1; i < n; ++i)
                if (s[i] == 'W')
                    stk[top++] = pii(i - bk - 1, bk), bk = i;
            sort(stk, stk + top);
            for (int i = 0; i < top; ++i)
                for (int j = 0; j < stk[i].X; ++j)
                    if (k > 0)
                        s[stk[i].Y + j + 1] = 'W', --k;
            for (int i = bk + 1; i < n; ++i)
                if (k > 0)
                    s[i] = 'W', --k;
            for (int i = beg - 1; i >= 0; --i)
                if (k > 0)
                    s[i] = 'W', --k;
        }
        for (int i = 0; i < n; ++i)
            if (s[i] == 'W')
                ans += ls + 1, ls = 1;
            else
                ls = 0;
        cout << ans << "\n";
    }
}