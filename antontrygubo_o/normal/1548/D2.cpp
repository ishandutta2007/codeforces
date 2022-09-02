#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

const int MOD =  1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));

/*
const int LIM = 3000005;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

ll C3(ll n)
{
    return (n*(n-1)*(n-2))/6;
}

ll C2(ll n)
{
    return (n*(n-1))/2;
}

int parity(pair<int, int> a, pair<int, int> b)
{
    if (a==b) return 0;
    int kek = __gcd(abs(a.first-b.first), abs(a.second-b.second));
    return kek%4;
}

int area(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    b.first-=a.first; c.first-=a.first;
    b.second-=a.second; c.second-=a.second;

    int area = b.first*c.second - b.second*c.first;

    if (area<0) area = -area;
    return area%4;

}

ll calc(vector<pair<int, int>> a)
{
    int n = a.size();
    vector<vector<ll>> grid(4, vector<ll>(4));

    for (int i = 0; i<n; i++) grid[a[i].first%4][a[i].second%4]++;

    vector<pair<int, int>> cells;
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++) cells.push_back(mp(i, j));

    ll ans = 0;

    for (int i = 0; i<16; i++) if (grid[cells[i].first][cells[i].second])
        for (int j = i; j<16; j++) if (grid[cells[j].first][cells[j].second])
            for (int k = j; k<16; k++) if (grid[cells[k].first][cells[k].second])
            {
                ll ways = 1;
                if (i==k) ways = C3(grid[cells[i].first][cells[i].second]);
                else if (i==j)
                {
                    ways = C2(grid[cells[i].first][cells[i].second]) * grid[cells[k].first][cells[k].second];
                }
                else if (j==k)
                {
                    ways = C2(grid[cells[k].first][cells[k].second]) * grid[cells[i].first][cells[i].second];
                }
                else ways = grid[cells[i].first][cells[i].second]*grid[cells[j].first][cells[j].second]*grid[cells[k].first][cells[k].second];

                int tot = parity(cells[i], cells[j]) + parity(cells[j], cells[k]) + parity(cells[k], cells[i]);

                int A = area(cells[i], cells[j], cells[k]);

                if (A%2!=0) continue;

                if (A%4 == tot%4) ans += ways;

            }

    return ans;
}

//Want B = S+1 - /2 to be odd (!) <=> S-/2 to be even <=> 2*S- to be divisible by 4

const int MAXX = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    int n; cin>>n;
    vector<pair<int, int>> a(n); for (int i = 0; i<n; i++) cin>>a[i].first>>a[i].second;

    vector<vector<pair<int, int>>> b(4);
    for (int i = 0; i<n; i++)
    {
        int tp = (a[i].first%2)*2 + (a[i].second%2);
        b[tp].push_back(a[i]);
    }

    ll ans = 0;
    for (int i = 0; i<4; i++) ans+=calc(b[i]);

    //cout<<ans<<endl;

    vector<vector<vector<int>>> cnt(4, vector<vector<int>>(4, vector<int>(4)));

    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++) if (i!=j)
        {
            for (auto pt: b[i])
            {
                vector<pair<int, int>> pts;
                for (auto it: b[j]) pts.push_back(mp(it.first-pt.first, it.second-pt.second));


                for (int x = 0; x<4; x++)
                    for (int y = 0; y<4; y++)
                        for (int z = 0; z<4; z++) cnt[x][y][z] = 0;

                for (auto it: pts)
                {
                    cnt[__gcd(abs(it.first), abs(it.second))%4][(it.first+MAXX)%4][(it.second+MAXX)%4]++;
                }

                for (int x1 = 0; x1<4; x1++)
                    for (int y1 = 0; y1<4; y1++)
                        for (int z1 = 0; z1<4; z1++) if (cnt[x1][y1][z1])
                            {
                                for (int x2 = 0; x2<4; x2++)
                                    for (int y2 = 0; y2<4; y2++)
                                        for (int z2 = 0; z2<4; z2++) if (cnt[x2][y2][z2])
                                        {
                                            if (16*x1 + 4*y1 + z1<16*x2 + 4*y2 + z2) continue;

                                            int A = area(mp(0, 0), mp(y1, z1), mp(y2, z2));
                                            if (A%2==1) continue;

                                            int gcd = x1+x2 + parity(mp(y1, z1), mp(y2, z2));
                                            if (gcd%4 != A%4) continue;

                                            if (16*x1 + 4*y1 + z1 == 16*x2 + 4*y2 + z2) ans+=C2(cnt[x1][y1][z1]);
                                            else ans+=1ll*cnt[x1][y1][z1]*cnt[x2][y2][z2];
                                        }
                            }
                //Now what dude???
            }
        }

    cout<<ans<<endl;
}