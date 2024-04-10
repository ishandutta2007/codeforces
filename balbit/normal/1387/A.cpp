#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()

#define pb push_back

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y){cerr<<x<<", "; _do(y...);}
#else
#define endl '\n'
#define bug(...)
#endif // BALBIT


#define IOS() ios::sync_with_stdio(0), cin.tie(0)

void GG(){cout<<"NO"<<endl; exit(0);}

const int maxn = 2e5+5;

struct pt{
    ll m,b;
    pt operator - (pt & oth) {
        return {m-oth.m, b-oth.b};
    }
    bool operator != (pt & oth) {
        return m!=oth.m || b != oth.b;
    }
};

pt state[maxn]; // {m,b} : a[i] = m*x+b

vector<pii> g[maxn];
bool seen[maxn];
const double MAGIC = -12123.14159;
double xval = MAGIC;
vector<int> here;
//pt state[maxn];

void dfs(int v) {
    seen[v] = 1;
    here.pb(v);
    for (pii p: g[v]) {
        int u = p.f;
        if (seen[u]) {
            pt tu = pt{0, p.s} - state[v];
            if (tu != state[u]) {
                if (tu.m == state[u].m) GG();
                double nv = -(state[u].b - tu.b) / (double)(state[u].m - tu.m);
                bug(nv);
                if (xval != MAGIC && nv != xval) GG();
                xval = nv;
            }
        }else{
            state[u] = pt{0,p.s} - state[v];
            dfs(u);
        }
    }
}

double gt(double x) {
    double re = 0;
    for (int y : here) {
        re += abs(state[y].m * x + state[y].b);
    }
    return re;
}

double rev[maxn];

signed main(){
    IOS();
    bug(1,2);

    int n,m; cin>>n>>m;
    for (int i = 0; i<m; ++i) {
        int a,b,c; cin>>a>>b>>c; --a; --b;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    for (int i = 0; i<n; ++i) {
        if (!seen[i]) {
            xval = MAGIC;
            here.clear();
            state[i] = {1,0};
            dfs(i);
            if (xval == MAGIC) {
                double l = -200010, r = 200010;
                for (int j = 0; j<200; ++j) {
                    double m1 = l + (r-l) / 3.0;
                    double m2 = r - (r-l) / 3.0;
                    double g1 = gt(m1), g2 = gt(m2);
                    if (g1 > g2) {
                        l = m1;
                    }else{
                        r = m2;
                    }
                }
                bug(l,r);
                xval = l;
            }
            for (int y : here) {
                rev[y] = state[y].m * xval + state[y].b;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<fixed<<setprecision(8);
    for (int i  = 0; i<n; ++i) cout<<rev[i]<<' ';
    for (int i = 0; i<n; ++i) bug(state[i].m, state[i].b);
}