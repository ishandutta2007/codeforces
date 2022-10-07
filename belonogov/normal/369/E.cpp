#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 4e6 + 2;
const int inf = 1e9;


int n, m;
pair < int, int > a[maxn];
vector < vector < int > > b;
vector < int > tree[maxn];
int c[maxn];


void build(int v, int ll, int rr){
    if (ll + 1 == rr){
        tree[v].pb(a[ll].sc);
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v].resize(tree[v * 2 + 1].size() + tree[v * 2 + 2].size());
    merge(tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(), tree[v * 2 + 2].begin(), tree[v * 2 + 2].end(), tree[v].begin());
}

int getCnt(int v, int ll, int rr, int l, int r, int k){
    if (ll >= r || l >= rr) return 0;
    if (l <= ll && rr <= r)
        return lower_bound(tree[v].begin(), tree[v].end(), k) - tree[v].begin();            
    
    return getCnt(v * 2 + 1, ll, (ll + rr) / 2, l, r, k) +
           getCnt(v * 2 + 2, (ll + rr) / 2, rr, l, r, k);
}

void read(){
    int k;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].fr, &a[i].sc);
    b.resize(m);
    for (int i = 0; i < m; i++){
        scanf("%d", &k);
        b[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &b[i][j]);      
    }
}

vector < int > solve(){
    int l, r, res;
    vector < int > ans;
    sort(a, a + n);
//  for (int i = 0; i < n; i++, cout << endl)
//      printf("%d %d", a[i].fr, a[i].sc);
//  
//  
    
    build(0, 0, n); 
//  for (int i = 0; i < n * 2; i++, cerr << endl){
//      cerr << "i sz : " << i << "   " << tree[i].size() << " ";
//      for (int j = 0; j < (int)tree[i].size(); j++)
//          cerr << tree[i][j] << " ";
//      
//  }
    
    for (int i = 0; i < m; i++){
        int k = b[i].size();
        c[0] = -1;
        for (int j = 0; j < k; j++)
            c[j + 1] = b[i][j];
        c[k + 1] = inf;
        k += 2;
        res = n;
        for (int j = 0; j < k - 1; j++){
            l = lower_bound(a, a + n, mp(c[j] + 1, -1)) - a;
            r = lower_bound(a, a + n, mp(c[j + 1], -1)) - a;
//          cerr << "l r: " << l << " " << r << endl;
            res -= getCnt(0, 0, n, l, r, c[j + 1]);
//          cerr << "res " << res << endl;
        }
        ans.pb(res);
    }
    return ans;
    
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    vector < int > ans;
    read();
    ans = solve();
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d\n", ans[i]);
    
    return 0;
}