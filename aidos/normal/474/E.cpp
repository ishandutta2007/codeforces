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

#define MAXN (int) (1e5) + 10
using namespace std;


pii tt[4*MAXN];
int n, m;
ll a[MAXN], b[MAXN];
void build(int v = 1, int l = 0, int r = m-1){
    if(l == r) {
        tt[v] =mp(0, -1);
    }
    else {
        build(2*v, l, (l + r) >> 1);
        build(2*v + 1, ((l+r) >> 1) + 1, r);
        tt[v] = max(tt[v << 1] ,tt[(v << 1) | 1]);
    }                                  
}

void add(int k, int l, int pos, int v=1, int tl = 0, int tr = m-1){
    if(tl == tr){
        if(l > tt[v].f){
            tt[v].f = l;
            tt[v].s = pos;
        }
    }   
    else {
        int mid= (tl + tr) >> 1;
        if( k <= mid) add(k, l,  pos, v << 1, tl, mid);
        else add(k, l, pos, (v << 1) | 1, mid+1, tr);
        tt[v] = max(tt[v << 1], tt[(v << 1)|1]);
    }
}


pii val(int tl, int tr, int v = 1, int l = 0, int r = m-1){
    if( tl > tr) return mp(0, -1);
    if(l == tl && tr == r) return tt[v];
    int mid = (l + r) >> 1;
    return max(val(max(tl, mid+1), tr,(v << 1)|1, mid+1, r), val(tl,  min(mid, tr), v << 1, l, mid));
}

map < ll, int > mm;
int c[MAXN], d[MAXN];
pii e[MAXN];
vector < int > aa;
int dd;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> dd;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        a[i] = b[i];
    } 
    sort(a, a + n);
    mm[a[0]] = 0;
    m = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]) continue;
        a[m] = a[i];
        mm[a[m]] = m;
        m++;
    }
    for(int i = 0; i < m; i++){
        int r = i, l = 0;
        int ans = inf;
        while( l <= r){
            int mid = (l + r) >> 1;
            if( dd <= a[i] -a[mid]){
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        c[i] = ans;
        l = i,r = m-1;
        ans = inf;
        while( l <= r){
            int mid = (l + r) >> 1;
            if( dd <= a[mid] - a[i]){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        d[i] = ans;
    }

    build();

    for(int i = n-1; i >= 0; i--){

        e[i] = mp(1, -1);
        int x = mm[b[i]];
        if(c[x] != inf){
            pii z = val(0, c[x]);
            z.f++;
            e[i] = z;
        }
        if( d[x] != inf) {
            pii z = val(d[x], m-1);
            z.f++;
            e[i] = max(e[i], z);
        }
        add(x, e[i].f, i);
    }
    int maxi = 0;
    for(int i = 0; i<n; i++){
        if(e[i].f > e[maxi].f) maxi = i;
    }
    while( maxi!=-1){
        aa.pb(maxi);
        maxi = e[maxi].s;
    }
    cout << aa.size() << endl;
    for(int i = 0; i < aa.size(); i++){
        cout << aa[i]+1 << " ";
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}