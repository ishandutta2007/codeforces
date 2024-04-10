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
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7 ;


void GG(){cout<<"NO\n"; exit(0);}

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

struct rect{
    int x1, x2, y1, y2, i; // i is id
};

struct seg{
    int l,r,i;
    bool operator < (seg &o) {
        return r < o.r;
    }
};

struct segtree{
    vector<pii> mn;
    vector<int> tg, cnt; // cnt is the sum of stuff here
    deque<seg> S;
    vector<int> rp;

    void push(int o, int l, int r) {
        if (tg[o]) {
            mn[o].f += tg[o];
            if (l != r) {
                tg[o*2] += tg[o];
                tg[o*2+1] += tg[o];
            }
            tg[o] = 0;
        }
    }

    void MO(int L, int R, int o, int l, int r, int v) {
        push(o,l,r);
        if (l > R || r < L) return;

        if (l >= L && r <= R) {
            tg[o] += v;
            push(o,l,r);
            return;
        }
        int mid = (l+r)/2;
        MO(L,R,o*2,l,mid,v); MO(L,R,o*2+1,mid+1,r,v);
        mn[o] = min(mn[o*2], mn[o*2+1]);
    }

    void MOpt(int p, int o, int l, int r, int v) {
        if (l > p || r < p) return;
        cnt[o] += v;
        if (l == r) {
            return;
        }
        int mid = (l+r)/2;
        MOpt(p,o*2,l,mid,v); MOpt(p,o*2+1,mid+1,r,v);
    }

    ll getcnt(int L, int R, int o, int l, int r) {
        if (l > R || r < L) return 0;
        push(o,l,r);
        if (l >= L && r <= R) {
            return cnt[o];
        }
        int mid = (l+r)/2;
        return getcnt(L,R,o*2,l,mid) + getcnt(L,R,o*2+1,mid+1,r);
    }

    void segbuild(int o,int l,int r) {
        if (l == r) {
            mn[o] = {0,l};
            return;
        }
        int mid = (l+r)/2;
        segbuild(o*2,l,mid); segbuild(o*2+1,mid+1,r);
        mn[o] = min(mn[o*2], mn[o*2+1]);
    }

    ll tot = 0;

    vector<int> have;

    bool upd(seg s, int dir) {
        if ((have[s.i]+dir > 1) || (have[s.i]+dir < 0)) return 0;
        have[s.i]+=dir;
        tot += dir;

        int l = upper_bound(ALL(rp), s.l) - rp.begin();
        int r = lower_bound(ALL(rp), s.r) - rp.begin() - 1;
//        bug(l,r);
        MO(l,r,1,0,SZ(rp)-1,dir);
        assert(rp[r+1] == s.r);
        MOpt(r+1,1,0,SZ(rp)-1,dir);
        return 1;
    }

    void build(){
        tot = 0;
        sort(ALL(S));
        for (seg &s : S) {
            rp.pb(s.r);
        }
        SORT_UNIQUE(rp);
        mn.resize(SZ(rp) * 4 + 4);
        tg.resize(SZ(rp) * 4 + 4);
        cnt.resize(SZ(rp) * 4 + 4);
        have.resize(SZ(S));

        segbuild(1,0,SZ(rp)-1);

        for (seg &s : S) {
            upd(s,1);
        }
    }

    vector<int> tryrem(){
        pii P = mn[1];
        if (P.f != 0) {
            GG();
        }
        if (P.s == SZ(rp)-1) return {};
        bug(P.f, P.s, SZ(rp)-1);
        vector<int> ret;

        int gl = getcnt(0, P.s, 1,0,SZ(rp)-1);
        if (gl == 0) {
            MO(P.s, P.s, 1,0,SZ(rp)-1, 1);
            return tryrem();
        }
        if (tot-gl == 0) {
            return {};
        }

        ll BAR = rp[P.s];
        bug(BAR);


        if (gl <= tot - gl) {
            // remove stuff from left
            while (S.front().r <= BAR) {
                if (upd(S.front(), -1)){
                    ret.pb(S.front().i);
                }
                S.pop_front();
            }
            MO(0,P.s,1,0,SZ(rp)-1,1);
        }else{
            while (S.back().r > BAR) {
                if (upd(S.back(), -1)){
                    ret.pb(S.back().i);
                }
                S.pop_back();
            }
            MO(P.s+1,SZ(rp)-1,1,0,SZ(rp)-1,1);
        }

        return ret;
    }
};

void solve(vector<rect> V) {
    if (SZ(V) <= 3) {
        return;
    }
    REP(i, SZ(V)) {
        V[i].i = i;
    }
    array<segtree, 2> A;
    for (rect &r : V) {
        A[0].S.pb({r.x1, r.x2, r.i});
        A[1].S.pb({r.y1, r.y2, r.i});
    }
    A[0].build();
    A[1].build();

    int left = SZ(V);
    while (left > 3) {
        vector<int> gt = A[0].tryrem();
        if (SZ(gt)) {
            bug(SZ(gt));
            for (int i : gt) {
                assert(A[1].upd({V[i].y1, V[i].y2, i}, -1));
                --left;
            }
        }else{
            gt = A[1].tryrem();
            bug(SZ(gt));
            if (!SZ(gt)) GG();
            for (int i : gt) {
                assert(A[0].upd({V[i].x1, V[i].x2, i}, -1));
                --left;
            }
        }
        if (SZ(gt) > 3) {
            vector<rect> gogo;
            for (int i : gt) {
                gogo.pb(V[i]);
            }
            solve(gogo);
        }
    }

}

signed main(){
    IOS();

    int n; cin>>n;
    vector<rect> go;
    REP(i,n) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        go.pb({x1,x2,y1,y2,i});
    }

    solve(go);

    cout<<"YES"<<endl;

}
/*
8
0 0 1 2
0 2 1 3
1 0 2 1
1 1 2 3

2 0 3 2
2 2 3 3
3 0 4 1
3 1 4 3

10 10 12 11
11 12 13 13
12 10 13 12
10 11 11 13
*/