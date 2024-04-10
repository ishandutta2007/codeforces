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

string s;

int nxt(int start, int len)
{
    if (len==1) return start;

    int l = len/2;
    int r = len - l;

    start = nxt(start, l);
    if (start==-1) return -1;

    start = nxt(start, r);
    if (start==-1) return -1;

    while (l>0 && r>0)
    {
        if (start>=s.size()) return -1;
        if (s[start]=='0') l--;
        else r--;
        start++;
    }
    return start;
}

bool check(int n)
{
    int tmp = nxt(0, n);
    return (tmp!=-1);
}

vector<int> permutator(int start, int len)
{
    if (len==1) return {0};

    int l = len/2;
    int r = len-l;

    vector<int> a = permutator(start, l);
    start = nxt(start, l);
    vector<int> b = permutator(start, r);
    start = nxt(start, r);

    vector<int> vals_a, vals_b;
    int cur = 0;
    while (l>0 && r>0)
    {
        if (s[start]=='0') {vals_a.push_back(cur); l--;}
        else {vals_b.push_back(cur); r--;}

        cur++; start++;
    }

    while (l>0)
    {
        vals_a.push_back(cur); cur++; l--;
    }

    while (r>0)
    {
        vals_b.push_back(cur); cur++; r--;
    }

    vector<int> ans;
    for (auto it: a) ans.push_back(vals_a[it]);
    for (auto it: b) ans.push_back(vals_b[it]);

    /*cout<<start<<' '<<len<<": "<<endl;
    for (auto it: ans) cout<<it<<' ';
    cout<<endl;*/

    return ans;
}

void solver(int n)
{
    auto res = permutator(0, n);
    cout<<n<<endl;
    for (auto it: res) cout<<it+1<<' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>s;

    int L = 1;
    int R = s.size() + 10;
    while (R-L>1)
    {
        int mid = (L+R)/2;
        if (check(mid)) L = mid;
        else R = mid;
    }

    solver(L);

}