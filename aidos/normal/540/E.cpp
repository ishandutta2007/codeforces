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
const int maxn = (int) 2e5 + 10;

using namespace std;

int a[maxn];
int l[maxn], r[maxn];
ll sum[maxn];
int p[maxn];
map < int, int > m;
int n;
int k;
int t[maxn << 2];

int get(int v, int l, int r, int tl, int tr){
    if(tl > tr) return 0;
    if(l == tl && tr == r) return t[v];
    int mid = (l + r) >> 1;
    return get(v  * 2, l, mid, tl, min(tr, mid))+get(v * 2 + 1, mid+1, r, max(mid+1, tl), tr);
}
void upd(int v, int l, int r, int pos){
    if(l == r){
        t[v] = 1;
    }   
    else {
        int mid = (l+r) >> 1;
        if(mid >= pos) upd(v*2, l, mid, pos);
        else upd(v * 2+1, mid+1, r, pos);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%d %d", &l[i], &r[i]);
        a[k++] = l[i];
        a[k++] = r[i];
    }
    
    sort(a, a + k);
    k=unique(a, a + k) - a;
    
    for(int i = 1; i < k; i++){
        sum[i] = sum[i-1] + a[i] - a[i-1] - 1;
    }
    for(int i = 0; i < k; i++){
        m[a[i]] = i;
        a[i] = i;
        p[i] = i;
    }
    
    for(int i = 0; i < n; i++){
        int lid = m[l[i]];
        int rid = m[r[i]];
        swap(p[lid], p[rid]);
        swap(a[p[lid]], a[p[rid]]);
    }

    ll ans = 0;
    for(int i = 0; i < k; i++){
        int id = a[i];
        if(id > i) ans += sum[id] - sum[i];
        else ans += sum[i] - sum[id];
    }

    for(int i = 0; i < k; i++){
        int res= get(1, 0, k-1, a[i]+1, k-1);

        ans += res;
        //cout << a[i] << " " << res << "\n";
        upd(1, 0, k-1, a[i]);
    }
//  cout << endl;
    cout << ans << endl;

    





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}