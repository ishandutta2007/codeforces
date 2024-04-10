#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
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

const int maxn = 1e5+5;

int dst[30][30][2][2];

int re = iinf;

void dfs(int a, int b, int c, int d, int D) {
//    bug(a,b,c,d,D);
    if ( a > 29 || b > 29) return;
    if (dst[a][b][c][d] <= D) {
        return;
    }
    dst[a][b][c][d] = D;

    if (a == 0) {
        if (b == 0) {
            MN(re, D);
            return;
        }
        if (!d && b <= 2) {
            MN(re, D);
            return;
        }
    }

    if (a && b) {
        dfs(a-1,b-1,1,d,D+1);
    }
    if (a >= 2) {
        dfs(a-2,b+1,c,d,D+1);
    }
    if (b>=1) {
        dfs(a+2,b-1,c,d,D+1);
    }
    if (d) {
        dfs(a+1,b,1,0,D+1);
    }
    if (c && a && d==0) {
        dfs(a-1,b,0,1,D+1);
    }
}

vector<int> get(int n){
    vector<int> a(n);
    REP(i,n) {
        cin>>a[i]; --a[i];
    }
    vector<int> seen(n);
    vector<int> ret;
    REP(i,n) {
        int c = 0;
        for (int j = i; !seen[j]; j = a[j]) {
            ++c; seen[j] = 1;
        }
        if (c) {
            ret.pb(c);
            bug(c);
        }
    }
    return ret;
}

signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> w = get(n);

        int par = 0;
        int a=0,b=0,c=0,d=0;
        int base = 0;
        for( int x : w) {
            if (x % 3 == 1 && x >= 4 && d == 0) {
                d = 1; x-=4;
                if (x==0) continue;
                base++;
            }
            if (x % 3 == 0) {
                base += (x-1)/3; c = 1;
            }else if (x % 3 == 2) {
                base += x/3; b++;
            }else{
                base += x/3; a++;
            }
        }


        bug(a,b,c,d);
        while (min(a,b) > 10) {
            a --; b--; base++;
        }

        int RE = iinf;

        while (1) {
            int A = a, B = b;
            int C = c;
            int bb = base;
            while (A > 13) {
                A-=3; bb+=2; C = 1;
            }
            while (B>13) {
                B-=3; bb+=3; C = 1;
            }
            memset(dst, 0x3f, sizeof dst);
            re = iinf;

            dfs(A,B,C,d,0);

            MN(RE, bb + re);
            bug(A,B,bb,re,RE);


            if (min(a,b) == 0) break;
            a--; b--; base++;
        }


        {
            ll r = 1;
            if (n % 3 == 1) {
                r = 4; n -= 4;
            }else if (n % 3 == 2) {
                r = 2; n -= 2;
            }
            r *= mpow(3, n/3);
            r %= mod;
            cout<<r<<' ';
        }


        cout<<RE<<endl;
    }


}