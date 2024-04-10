#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 1'010;
int n, m, q;

struct seg
{
    int t[N << 2];

    seg(){memset(t, -1, sizeof t);}

    void set(int i, int v, int l, int r, int b, int e)
    {
        if(l <= b && e <= r) {t[i] = v; return;}
        if(r <= b || e <= l) return;
        if(~t[i]) {t[2*i+1] = t[2*i+2] = t[i]; t[i] = -1;}
        set(2*i+1, v, l, r, b, (b+e)/2);
        set(2*i+2, v, l, r, (b+e)/2, e);
    }

    int get(int i, int p, int b, int e)
    {
        if(~t[i]) return t[i];
        if(p < (b+e)/2) return get(2*i+1, p, b, (b+e)/2);
        else            return get(2*i+2, p, (b+e)/2, e);
    }

    void set(int l, int r, int v){set(0, v, l, r, 0, N);}
    int get(int i){return get(0, i, 0, N);}
};

seg L[N], R[N], U[N], D[N];
set<int> H[N];
set<int> V[N];
bool g[N][N];

void init()
{
    Loop(i,1,n+1) H[i].insert(0), H[i].insert(m+1);
    Loop(i,1,m+1) V[i].insert(0), V[i].insert(n+1);
    Loop(i,1,n+1) L[i].set(0, m+1, 0), R[i].set(0, m+1, m+1);
    Loop(i,1,m+1) U[i].set(0, n+1, 0), D[i].set(0, n+1, n+1);
}

void add(int i, int j)
{
    set<int>::iterator it1 = H[i].insert(j).F;
    set<int>::iterator it2 = V[j].insert(i).F;
    int l = *(--it1); ++it1;
    int r = *(++it1); --it1;
    int u = *(--it2); ++it2;
    int d = *(++it2); --it2;
    L[i].set(j, r, j);
    R[i].set(l+1, j+1, j);
    U[j].set(i, d, i);
    D[j].set(u+1, i+1, i);
}
void del(int i, int j)
{
    H[i].erase(j); V[j].erase(i);
    auto it1 = H[i].upper_bound(j);
    auto it2 = V[j].upper_bound(i);
    int r = *it1;
    int l = *(--it1);
    int d = *it2;
    int u = *(--it2);
    L[i].set(j, r, l);
    R[i].set(l+1, j+1, r);
    U[j].set(i, d, u);
    D[j].set(u+1, i+1, d);
}

int Do(seg* S, int l, int r, int i, int j, int c){
    int h = (S[i].get(j) - j)*c;
    int ans = h;
    int b = i, e = i;
    while(h > 0)
    {
        int h1, h2;
        h1 = b-1 == l? 0: (S[b-1].get(j) - j)*c;
        h2 = e+1 == r? 0: (S[e+1].get(j) - j)*c;
        if(h1 > h2) h = min(h, h1), b--;
        else        h = min(h, h2), e++;
        ans = max(ans, h*(e-b+1));
    }
    return ans;
}

int main()
{
    FAST;
    cin >> n >> m >> q;
    init();
    Loop(i,1,n+1) Loop(j,1,m+1)
    {
        cin >> g[i][j];
        if(!g[i][j]) add(i, j);
    }
    while(q--)
    {
        int t, i, j;
        cin >> t >> i >> j;
        if(t == 1){
            if(g[i][j]){add(i, j);}
            else       {del(i, j);}
            g[i][j] ^= 1;
        }
        else
        {
            int ans = 0;
            ans = max(ans, Do(L, 0, n+1, i, j, -1));
            ans = max(ans, Do(R, 0, n+1, i, j,  1));
            ans = max(ans, Do(U, 0, m+1, j, i, -1));
            ans = max(ans, Do(D, 0, m+1, j, i,  1));
            cout << ans << '\n';
        }
    }
}