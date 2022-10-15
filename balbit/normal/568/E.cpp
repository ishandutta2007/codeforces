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

int a[maxn];
pair<int, pii> bar[maxn], ifbar[maxn]; // steps, {number of times i follow the way, end up where}
// bar is the stuff already here, ifbar is the stuff to be updated

vector<int> alla;
//int b[maxn];
vector<int> b;

int far[maxn];
int from[maxn];
int theway[maxn]; // number of times I follow the way

pii seg[maxn*2];
void modify(int p, pii value) {  // set value at position p
    for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p] , seg[p^1]);
}

pii query(int l, int r) {  // sum on interval [l, r)
    pii res = {0,-1};
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, seg[l++]);
        if (r&1) res = max(res, seg[--r]);
    }
    return res;
}


signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n) {
        cin>>a[i];
        if (a[i] != -1) alla.pb(a[i]);
    }
    SORT_UNIQUE(alla);

    int m; cin>>m;

    vector<int> garb;

    REP(i,m) {
        int x;
        cin>>x; b.pb(x); garb.pb(x);
    }
    SORT_UNIQUE(b);
    m = SZ(b);

    fill(bar, bar+maxn, make_pair(0,pii{0,-1}));
    fill(seg, seg+maxn, make_pair(0,-1));
    fill(ifbar, ifbar+maxn, make_pair(1,pii{0,-1}));

//    vector<pii> bst (n+1, {inf, -1});

//    int lastcool = -1;

    pii ept = {-1, -1};

    REP(i,n) {
        far[i] = 1; from[i] = -1;
        if (a[i] == -1) {
            // yoink!!!!
            REP(j,m) {
                bar[j] = ifbar[j];
                if (j) MX(bar[j], bar[j-1]);
            }
            REP(j,m) {
                ifbar[j+1] = max(ifbar[j+1], make_pair(bar[j].f+1, pii{bar[j].s.f+1, bar[j].s.s}));
            }



            MX(ept, make_pair(bar[m-1].f, i));
        }else{
            int a_at = lower_bound(ALL(alla), a[i]) - alla.begin();
            {
                pii ya = query(0, a_at);
                if (ya.f+1 > far[i]) {
                    far[i] = ya.f+1;
                    from[i] = ya.s;
                }

            }
//            int at = lower_bound(ALL(bst), pii{a[i], -1}) - bst.begin();
//            bst[at] = {a[i], i};
//            if (at > 0) {
//                far[i] = at+1;
//                from[i] = bst[at-1].s;
//            }

            // now work with the special one
            int at = lower_bound(ALL(b), a[i]) - b.begin();
            if (--at >= 0) {
                // try this one
                if (bar[at].f+1 > far[i]) {
                    far[i] = bar[at].f+1;
                    from[i] = bar[at].s.s;
                    theway[i] = bar[at].s.f + 1;
                }
            }



            // now update the special case
            while (at+ 1 < SZ(b) && b[at+1] <= a[i]) ++at;
            ++at;
            if (at < SZ(b)) {
                // update!!
                ifbar[at] = max(ifbar[at], {far[i]+1, {0, i}});
            }

            modify(a_at, make_pair(far[i], i));

            MX(ept, make_pair(far[i], i));
        }

    }

    bug(ept.f, ept.s);

    int nar = b.back();
    int at = ept.s;

    map<int, int> took;

    while (at != -1) {
        bool wasneg = 0;
        if (a[at] != -1) {
            nar = a[at];
        }else{
            a[at] = nar;
            wasneg = 1;
            took[a[at]]++;
        }
        int nway, fin;
        if (wasneg) {
            nway = bar[m-1].s.f; fin = bar[m-1].s.s;
            bug(nway, fin);
        }else{
            nway = theway[at], fin = from[at];
        }
        bug(nar, nway, fin);
        REP(j,nway) {
            do{
                --at;
            }while (a[at] != -1);
            a[at] = *prev(lower_bound(ALL(b), nar));
            bug(at, a[at]);
            took[a[at]]++;
            nar = a[at];
        }
        at = fin;
//        nar = a[at];
    }

    REP(i,n) {
        if (a[i] == -1) {
            while (1) {
                int x = garb.back(); garb.pop_back();
                if (took[x]) {
                    --took[x];
                }else{
                    a[i] = x; break;
                }
            }
        }
        cout<<a[i]<<' ';
    }



}

/*
5
-1 -1 -1 -1 -1
7
1 1 1 2 2 2 3
*/