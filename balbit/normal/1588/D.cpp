#include <bits/stdc++.h>
using namespace std;
#undef BALBIT
#define ll long long
#define y1 zck_is_king
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

//const int maxn = 1e5+5;

ll dp[53][(1<<10)];
pair<int, int> frm[53][(1<<10)];
int where[11][53][2]; // first or second
int str[11][1000];

int id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}
char rr(int t) {
    if (t < 26) return (char) ('a' + t);
    return (char) ('A' + (t - 26));
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        memset(where, -1, sizeof where);
        memset(dp, 0, sizeof dp);
        int n; cin>>n;
        int m= 0;
//        int len1 = 0;
        REP(i, 53) REP(j, (1<<10)) {
            frm[i][j] = {-1, -1};
        }
        REP(i,n) {
            string s; cin>>s; //m = SZ(s);
            if (i == 0) m = SZ(s);
            REP(j, SZ(s)){
                str[i][j] = id(s[j]);
                int c = str[i][j];
                if (where[i][c][0] != -1) {
                    where[i][c][1] = j;
                }else{
                    where[i][c][0] = j;
                }
            }
        }
        // do dp order by first element
        int re = 0;
        pii fin={-1,-1};
        REP(st, m) {
            int ele = str[0][st];
            int bit1 = st == where[0][ele][0]? 0 : 1;
            bug(ele, bit1);// gogogo!
            REP(msk, (1<<(n-1))) {
                // first check if this is even viable
                int M = msk*2 + bit1;
                {
                    bool ok = 1;
                    REP(i,n) {
                        if (where[i][ele][(M>>i)&1] == -1) {
                            ok = 0; break;
                        }
                    }
                    if (ok == 0) continue;
                }
                bug(ele, M, "is ok");
                dp[ele][M] = 1; frm[ele][M] = {-1, -1};
                if (re == 0) {
                    re = 1; fin = {ele, M};
                }
                REP(i,n) {
                    if (M & (1<<i)) MX(dp[ele][M], dp[ele][M ^ (1<<i)]);
                }
                REP(e2, 52) {
                    int M2 = 0;
                    bool ok = 1;
                    {
                        REP(i,n) {
                            if (where[i][e2][0] == -1 || (where[i][e2][0] >= where[i][ele][(M>>i)&1])) {
                                ok = 0; break;
                            }
                            if (where[i][e2][1] != -1 && where[i][e2][1] < where[i][ele][(M>>i)&1]) {
                                M2 |= (1<<i);
                            }
                        }
                    }
                    if (ok) {
                        MX(dp[ele][M], dp[e2][M2] + 1);
                        if (dp[e2][M2] + 1 == dp[ele][M]) {
                            frm[ele][M] = {e2, M2};
                        }
                        MX(re, dp[ele][M]);
                        if (dp[ele][M] == re) {
                            fin = {ele,M};
                        }
                        bug(ele, e2, M, M2, dp[ele][M]);
                    }
                }
            }
        }
        cout<<re<<endl;
        string rec;
        while (fin != pii{-1, -1}) {
            rec += rr(fin.f);
            fin = frm[fin.f][fin.s];
        }
        reverse(ALL(rec));
        cout<<rec<<endl;

    }

}