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

int MOD =  1e9 + 7;

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
const int LIM = 300000;

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

const int MAX = 1e9;

int n, k;
string s;

vector<vector<int>> ending;

bool check(int len)
{
    for (int letter = 0; letter<k; letter++)
    {
        char c = char('a'+letter);
        int streak = 0;

        int best = MAX;

        for (int i = n-1; i>=0; i--)
        {
            if (s[i]=='?'||s[i]==c) streak++; else streak = 0;
            if (streak>=len) best = i+len-1;
            ending[letter][i] = best;
        }
    }


    vector<int> ans(1<<k);

    ans[0] = -1;
    for (int mask = 1; mask<(1<<k); mask++)
    {
        ans[mask] = MAX;
        for (int bit = 0; bit<k; bit++) if (mask&(1<<bit))
        {
            int st1 = ans[mask^(1<<bit)]+1;
            if (st1>=n) continue;
            ans[mask] = min(ans[mask], ending[bit][st1]);
        }
    }
    return (ans[(1<<k)-1]<MAX);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>k;

    ending = vector<vector<int>>(k, vector<int>(n));

    cin>>s;

    int q = 0; set<char> setik;
    for (auto c: s)
    {
        if (c=='?') q++;
        else setik.insert(c);
    }

    if (setik.size()+q<k) {cout<<0; return 0;}

    int L = 1; int R = (n+k)/k;

    while (R-L>1)
    {
        int mid = (L+R)/2;
        if (check(mid)) L = mid; else R = mid;
    }

    cout<<L<<endl;


}