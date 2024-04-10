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
const ll mod = 998244353 ;


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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e2+5;

int a[maxn];
int org[maxn];
int hero[maxn];
int id[maxn];int n,m;

vector<int> ord;

bool gol(int st){
    int lst = -1;
    for (int i = st; i>=0; --i) {
        if (id[i] == -1) continue;
        lst = id[i];
        int myh = hero[i];
        bool alive = 1;
        for (int j = i; j<=st; ++j) {
            myh += a[j];
            a[j] = 0;
            if (myh < 0) {
                alive = 0;
                for (int k = j; k>=i; --k) {
                    a[k] = org[k];
                }
                break;
            }
        }
        if (alive)
            ord.pb(id[i]);
    }
    if (lst == -1 || (!ord.empty() && ord.back() == lst)) {
        return 1;
    }
    else{
        return 0;
    }
}


bool gor(int st){
    int lst = -1;
    for (int i = st; i<n; ++i) {
        if (id[i] == -1) continue;
        lst = id[i];
        int myh = hero[i];
        bool alive = 1;
        for (int j = i; j>=st; --j) {
            myh += a[j];
            a[j] = 0;
            if (myh < 0) {
                alive = 0;
                for (int k = j; k<=i; ++k) {
                    a[k] = org[k];
                }
                break;
            }
        }
        if (alive)
            ord.pb(id[i]);
    }
    if (lst == -1 || (!ord.empty() && ord.back() == lst)) {
        return 1;
    }
    else{
        return 0;
    }
}

bool done[maxn];

signed main(){
    IOS();
    cin>>n>>m;
    memset(id, -1, sizeof id);
    for (int i = 0; i<m; ++i) {
        int s,h; cin>>s>>h; --s;
        hero[s] = h;
        id[s] = i+1;
    }
    for (int i = 0; i<n; ++i) {
        cin>>org[i];
    }

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            a[j] = org[j];
        }
        if (gol(i) && gor(i)) {
            bug(i, "is ok gol gor");
            cout<<i+1<<endl;
            for (int x : ord) if (!done[x]) {cout<<x<<' ', done[x] = 1;}
            for (int i = 1; i<=m; ++i) {
                if (!done[i]) cout<<i<<' ';
            }
            cout<<endl;
            return 0;
        }
        ord.clear();

        for (int j = 0; j<n; ++j) {
            a[j] = org[j];
        }
        if (gor(i) && gol(i)) {
            bug(i, "is ok gor gol");
            cout<<i+1<<endl;
            for (int x : ord) if (!done[x]) {cout<<x<<' ', done[x] = 1;}
            for (int i = 1; i<=m; ++i) {
                if (!done[i]) cout<<i<<' ';
            }
            cout<<endl;
            return 0;
        }
        ord.clear();

    }

    cout<<-1<<endl;

}