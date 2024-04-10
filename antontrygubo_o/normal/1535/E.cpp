#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

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


int MOD =  998244353;



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
const int LIM = 1000;

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


/*struct DSU
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

const int N = 3e5 + 10;

const int M = 20;

vector<int> cnt(N), cost(N);
vector<vector<int>> lift(N, vector<int>(M));

/*int nxt(int v, int len)
{
    for (int i = M-1; i>=0; i--) if (len>=(1<<i))
    {
        if (lift[v][i]==-1) return -1;
        else
        {
            v = lift[v][i];
            len-=(1<<i);
        }
    }
    return v;
}*/

int find_up(int v)
{
    for (int i = M-1; i>=0; i--) if (lift[v][i]!=-1 && cnt[lift[v][i]]>0)
    {
            v = lift[v][i];
    }
    return v;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int q; cin>>q>>cnt[0]>>cost[0];

    for (int i = 0; i<20; i++) lift[0][i] = -1;
    for (int i = 1; i<=q; i++)
    {
        int op; cin>>op;
        if (op==1)
        {
            int p, a, c; cin>>p>>a>>c;
            cnt[i] = a; cost[i] = c;
            lift[i][0] = p;
            for (int dep = 1; dep<M; dep++)
            {
                if (lift[i][dep-1]==-1) lift[i][dep] = -1;
                else lift[i][dep] = lift[lift[i][dep-1]][dep-1];
            }
        }
        else
        {
            int v, w; cin>>v>>w;
            ll tot = 0;

            ll able = 0;

            while (w)
            {
                int cur = find_up(v);
                int take = min(cnt[cur], w);
                w-=take; cnt[cur]-=take;
                able+=take; tot+=1ll*take*cost[cur];
                if (cur==v) break;
            }

            cout<<able<<' '<<tot<<endl;

        }
    }

}