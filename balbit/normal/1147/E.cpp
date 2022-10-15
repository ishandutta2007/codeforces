#include <bits/stdc++.h>
#undef BALBIT
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

vector<int> col;

vector<int> ask(vector<pii> p) {
    if (SZ(p) == 0) return {};
    vector<int> re;
    cout<<"Q "<<SZ(p)<<' ';
    for (pii s : p) cout<<s.f+1<<' '<<s.s+1<<' ';
    cout<<endl<<flush;
    #ifndef BALBIT
    string gt;
    cin>>gt;
    REP(i,SZ(p)) re .pb( gt[i] - '0' );
    #else
    {
        REP(i,SZ(p)) {
            re.pb(col[p[i].f] == col[p[i].s]);
        }
    }
    #endif
    return re;
}

int ansfrom[maxn];


vector<int> gogo(int n) {
    // step 1: build unique diff chain in <= 3 steps
    vector<int> sn(n); // same as next
    {
        vector<pii> a0,a1,aaa;
        REP(i,n-1) {
            if (i % 2 == 0) a0.pb({i, i+1});
            else a1.pb({i, i+1});
        }
        aaa.pb({n-1, 0});
        {
            vector<int> t = ask(a0);
            REP(i, SZ(t)) sn[i*2] = t[i];
        }
        {
            vector<int> t = ask(a1);
            REP(i, SZ(t)) sn[i*2+1] = t[i];
        }
        {
            vector<int> t = ask(aaa);
            bug(aaa[0].f, aaa[0].s, t[0]);
            sn[n-1] = t[0];
        }
    }

    vector<int> ids;
    REP(i,n) {
        if (!sn[i]) {
            ids.pb(i);
        }
    }
    if (SZ(ids) == 0) {
        return vector<int> (n, 0);
    }
    int lst = ids[0];
    REP(j,n) {
        int i = (ids[0]-j+n)%n;
        if (!sn[i]) {
            lst = i;
        }
        ansfrom[i] = lst;
        bug(i, ansfrom[i]);
    }

//    REP(i,n) {bug(i, sn[i]);}

    // test skipping 1 step
    vector<int> df2(SZ(ids));
    {
        vector<pii> a0, a1;
        vector<int> who0, who1;
        REP(i,SZ(ids)) {
            if (i >= 2) {
                if ((i / 2) % 2 == 0) {
                    a0.pb({ids[i-2],ids[i]});
                    who0.pb(i);
                }else{
                    a1.pb({ids[i-2],ids[i]});
                    who1.pb(i);
                }
            }
        }
        {
            vector<int> t = ask(a0);
            REP(i, SZ(t)) {
                df2[who0[i]] = t[i];
            }
        }
        {
            vector<int> t = ask(a1);
            REP(i, SZ(t)) {
                df2[who1[i]] = t[i];
            }
        }
    }
    vector<int> re(SZ(ids));
    re[0] = 0; re[1] = 1;
    vector<int> retar(n);
    REP(i, SZ(ids)) {
        if (i >= 2) {
            if (df2[i]) {
                re[i] = re[i-2];
            }else{
                re[i] = 1^2^re[i-1]^re[i-2];
            }
        }
        retar[ids[i]] = re[i];
    }
    REP(i,n) {
        retar[i] = retar[ansfrom[i]];
    }
    return retar;
}

signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        #ifdef BALBIT
        col.resize(n); REP(i,n) cin>>col[i];
        #endif // BALBIT
        // deal with base case n=1

        if (n == 1){
            cout<<"A 1 0 0\n1\n\n\n"<<flush;
            continue;
        }

        vector<int> yay = gogo(n);
//        cout<<"A ";
//        for (int x : yay) {
//            cout<<x<<' ';
//        }
//        cout<<endl;
        array<vector<int>, 3> A;
        REP(i, n) A[yay[i]].pb(i+1);
        cout<<"A "<<SZ(A[0])<<' '<<SZ(A[1])<<' '<<SZ(A[2])<<endl;
        REP(j,3) {
            for (int x : A[j]) cout<<x<<' ';
            cout<<endl;
        }
        cout<<flush;
    }

}