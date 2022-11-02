#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int t[800100];
vector < int > g[200100], gg[200200];

int n;
pair < string, int > p[200100];
int pos[200100];
bool used[200100];
void build(int v,int l, int r){
    if( l == r){
        t[v] = r;
    }
    else {
        int mid = ( l + r) >> 1;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid+1, r);
        t[v] = t[v*2];
    }
}
void upd(int v, int l, int r, int pos){
    if( l==r){
        t[v] = -1;
    }
    else {
        int mid = (l + r) >> 1;
        if( mid >= pos) upd(v * 2, l, mid, pos);
        else upd( v * 2 + 1, mid+1, r, pos);
        t[v] = max(t[v*2], t[v*2 +1]);
    }
}
int get(int v, int l, int r, int tl, int tr){
    if( tl > tr) return -1;
    if( l == tl && tr == r) return t[v];
    int mid = ( l + r) >> 1;
    return max(get(v * 2, l, mid, tl, min(tr, mid)), get(v *2 + 1, mid+1, r, max(tl, mid+1), tr));
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    
    cin >> n;

    for(int i = 0; i < n + n; i++){
        cin >> p[i].f;
        p[i].s=i;
    }
    sort(p, p + n + n);
    build(1, 0, n + n - 1);
    vector < pii > gt, ans;
    for(int i = 0;i < n+n; i++){
        if(p[i].s < n) {
            upd(1, 0, n + n - 1, i);
        }
        for(int j = 0; j <= p[i].f.size(); j++){
            g[i].pb(i);
            if(p[i].s < n) gt.pb( mp (-j, i) );
        }
        g[i][0]=0;
        if( i ){
            int t = 0;
            while( t < p[i-1].f.size() && t < p[i].f.size() && p[i-1].f[t] == p[i].f[t]){
                t++;
                g[i][t] = g[i-1][t];
            }
        }
    }
    
    for(int i = n+n-1;i >= 0; i--){
        pos[p[i].s] = i;
        for(int j = 0; j <= p[i].f.size(); j++)
            gg[i].pb(i);
        gg[i][0]=n + n - 1;
        if( i < n + n - 1){
            int t = 0;
            while( t < p[i+1].f.size() && t < p[i].f.size() && p[i+1].f[t] == p[i].f[t]){
                t++;
                gg[i][t] = gg[i+1][t];
            }
        }
    }
    sort(gt.begin(), gt.end());
    ll answer = 0;
    for(int i = 0; i < gt.size(); i++){
        int pp = gt[i].s;
        int c = -gt[i].f;
        if(used[pp]) continue;
        int gx = get(1, 0, n + n - 1, g[pp][c], gg[pp][c]);
        if( gx == -1) continue;
        answer += c;
        used[pp] = 1;
        upd(1,0,n+n-1, gx);
        ans.pb(mp(p[pp].s + 1,p[gx].s - n + 1));
    }
    cout << answer << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].f << " "<< ans[i].s << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}