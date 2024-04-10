#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500001;
const int K = 26;
const vector<int> TOFILL(K, 0);
vector<int> tr[N], h[N];
vector<vector<int> > seg[N];
int timer = 0, hmax = 0, in[N], out[N];
char a[N];

inline void dfs(int v, int d)
{
    hmax = max(hmax, d);
    in[v] = timer++;
    h[d].push_back(v);
    for(int i=0, sz=(int)tr[v].size(); i<sz; i++)
        dfs(tr[v][i], d+1);
    out[v] = timer++;
}

inline void upd(vector<vector<int> > &tr, int n, int pos, int let)
{
    tr[pos+=n][let]++;
    for(pos >>= 1; pos; pos >>=1)
        tr[pos][let]++;
}

inline bool can(int v, vector<vector<int> > &tr, vector<int> &ar)
{
    int n = (int) ar.size();
    if(in[ar.back()]<in[v] || out[ar[0]]>out[v]) return true; // NE MOZHEM BIN POISK
    int left, right; // GRANICY OTREZKA
    int l = 0, r = n-1;
    while(l < r) {
        int m = (l+r)>>1;
        if(in[ar[m]] >= in[v]) r = m;
        else l = m + 1;
    }
    left = l;
    l = 0; r = n - 1;
    while(l < r) {
        int m = (l+r)>>1;
        if(l==m) m++;
        if(out[ar[m]] <= out[v]) l = m;
        else r = m - 1;
    }
    right = l;
    int cnt = 0;
    for(int i=0; i<K; i++)  { // SEG TREE
        int cur=0;
         l = left; r = right;
         for(l += n, r += n; l<=r; l=(l+1)>>1, r=(r-1)>>1)
         {
             if(l&1) cur += tr[l][i];
             if(!(r&1)) cur += tr[r][i];
         }
         cnt += cur%2;
    }
    return (cnt < 2);
}

int main()
{
    int n, q;
    scanf_s("%d%d", &n, &q);
    for(int i=1, u; i<n; i++) { scanf_s("%d", &u); tr[u-1].push_back(i); }
    dfs(0, 1); scanf_s("%c", &a[0]);
    if(n==1) scanf_s("%c", &a[0]);
    for(int i=0; i<n; i++) scanf_s("%c", &a[i]);
    for(int i=1; i<=hmax; i++)
        if(h[i].size() != 0)
        {
            int m = (int) h[i].size();
            seg[i].resize(2*m, TOFILL);
            for(int j=0; j<m; j++)
                upd(seg[i], m, j, a[h[i][j]]-'a');
        }
    for(int i=0, v, deep; i<q; i++)
    {
        scanf_s("%d%d", &v, &deep);
        printf("%s", (deep > hmax ? "Yes\n" : can(v-1, seg[deep], h[deep]) ? "Yes\n" : "No\n"));
    }
    return 0;
}