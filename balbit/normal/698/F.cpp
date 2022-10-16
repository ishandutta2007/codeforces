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

const int maxn = 1e6+5;

int red[maxn];
bool np[maxn];

int sup[maxn];
int here[maxn];
ll fac[maxn];

int lick[maxn]; // who is this prime locked as?
int rlick[maxn];
int group[maxn]; // which div group is this in?
int bprm[maxn]; // biggest prime

int freeprime[maxn];

signed main(){
    IOS();
    fac[0] = 1;
    for (int i = 1; i<maxn; ++i) {
        red[i] = i; bprm[i] = i;
        fac[i] = fac[i-1] * i % mod;
    }

    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) for (int j = i+i; j<maxn; j+=i) {
            bprm[j] = i;
            while (red[j] % i == 0) {
                red[j] /= i;
            }
            red[j] *= i;
            np[j] = 1;
        }
    }

    int n; cin>>n;

    bug(red[6], red[12], red[24], red[9], red[16], red[48]);

//    REP1(i,n) {
//        if (i == 1 || (!np[i] && i*2 > n)) {
//            red[i] = 1;
//        }
//        bug(i, red[i]);
//    }

    memset(lick, -1, sizeof lick);
    memset(rlick, -1, sizeof rlick);

    auto GA = [&](int x) {
        return x == 1? 1 : n/x;
    };

    REP1(i,n) {
        sup[red[i]]++;
        int x=0;
        cin>>x;

        if (x == 0) continue;
        int I = red[i], X = red[x];
        if ((I / bprm[I] == X / bprm[X]) && GA(bprm[I]) == GA(bprm[X])) {
            if (lick[bprm[I]] != -1 && lick[bprm[I]] != bprm[X]) {
                cout<<0<<endl; return 0;
            }else if (rlick[bprm[X]] != -1 && rlick[bprm[X]] != bprm[I]){
                cout<<0<<endl; return 0;
            }else{
                lick[bprm[I]] = bprm[X];
                rlick[bprm[X]] = bprm[I];
            }
        }else{
            cout<<0<<endl; return 0;
        }
//        if (red[i] != red[x]) { // wrong!
//            cout<<0<<endl; return 0;
//        }
        here[red[x]]++;
    }

    ll re = 1;

    REP1(i,n) {
        if (!np[i] && lick[i] == -1) {
            bug(i, "free!", GA(i));
            ++freeprime[GA(i)];
        }
    }

    REP1(i,n) {
        if (i != red[i]) continue;
        if (sup[i]) {
            bug(i, sup[i], here[i]);
        }
        re *= fac[(sup[i] - here[i])];
        re %= mod;
    }

    REP1(i,n) {
        re *= fac[freeprime[i]];
        re %= mod;
    }

    cout<<re<<endl;

}