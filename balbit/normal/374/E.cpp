#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 2005;

struct line{
    int x1,y1,x2,y2;
    void ori(){
        assert(x1 == x2 || y1 == y2);
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1,y2);
    }
    void prt() {
        bug(x1,y1,x2,y2);
    }
};
void L(int &x1,int &y1) {
    int ox = x1;
    x1 = x1 - y1;
    y1 = ox + y1;
}
vector<pair<int, int> > blu, red;

int n,m;
vector<int> hv;

bool seen[4000000+5];
int buf = 2e6+1;

int leq(int x){
    return upper_bound(ALL(hv),x)-hv.begin();
}

bool ok(int t) {
    vector<line> Hor, Ver;
    for (pii x : blu) {
        int x1 = x.f-t, y1 = x.s+t, x2 = x.f+t, y2 = x.s-t;
        L(x1,y1); L(x2,y2);
        Hor.pb({x1,y1,x2,y2});
        Hor.back().ori();
    }
    vector<line> hor, ver;
    sort(ALL(Hor),[&](line a,line b){return a.y1!=b.y1?a.y1<b.y1:a.x1<b.x1;});
    for (int i = 0; i<n; i++) {
        if (i && Hor[i].y1 == hor.back().y1 && Hor[i].x1<=hor.back().x2) {
            hor.back().x2 = Hor[i].x2;
        }else{
            hor.pb(Hor[i]);
        }
    }

    for (pii x : red) {
        int x1 = x.f+t, y1 = x.s+t, x2 = x.f-t, y2 = x.s-t;
        L(x1,y1); L(x2,y2);
        Ver.pb({x1,y1,x2,y2});
        Ver.back().ori();
    }

    sort(ALL(Ver),[&](line a,line b){return a.x1!=b.x1?a.x1<b.x1:a.y1<b.y1;});
    for (int i = 0; i<m; i++) {
        if (i && Ver[i].x1 == ver.back().x1 && Ver[i].y1<=ver.back().y2) {
            ver.back().y2 = Ver[i].y2;
        }else{
            ver.pb(Ver[i]);
        }
    }

    sort(ALL(hor),[&](line a,line b){return a.y1<b.y1;});
    sort(ALL(ver),[&](line a,line b){return a.y1<b.y1;});


    for (int i = 1; i<n; i++) {
        for (int x : hv) seen[x+buf]=0;
        hv.clear();
        bug("NEW",i);
        hor[i].prt();
        int j = 0;
        for (int it = 0; hor[it].y1 != hor[i].y1; it++) {
            bug(it);
            hor[it].prt();
            while (j<m && ver[j].y1 <=hor[it].y1) {
                if (ver[j].y2>=hor[i].y1 && ver[j].x1 >= hor[i].x1 && ver[j].x1<=hor[i].x2) {
                    if (!seen[ver[j].x1+buf])
                        hv.pb(ver[j].x1), seen[ver[j].x1+buf]=1;
                    ver[j].prt();
                    bug("Added",ver[j].x1);

                    #ifdef BALBIT
                    assert(ver[j].x1==ver[j].x2);
                    #endif // BALBIT
                }
                j++;
            }
            sort(ALL(hv));
            if (leq(hor[it].x2)-leq(hor[it].x1-1) > 1) {
                return 1;
            }
        }
    }

    return 0;
}

signed main(){
    IOS();

    cin>>n>>m;
    for (int i = 0; i<n; i++) {
        int x,y; cin>>x>>y; blu.pb({x,y});
    }
    for (int i = 0; i<m; i++) {
        int x,y; cin>>x>>y; red.pb({x,y});
    }
//    bug(ok(2));
//    return 0;
    int l = 1, r = 2e6+2;
    while (l!=r) {
        int mid = (l+r)/2;
        if (ok (mid)) {
            r=mid;
        }else{
            l = mid+1;
        }
    }
    if (l == 2e6+2) {
        cout<<"Poor Sereja!"<<endl; return 0;
    }
    cout<<l<<endl;
}