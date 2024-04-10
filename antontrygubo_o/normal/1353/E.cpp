#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 999983;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


mt19937 rnd(time(0));

/*struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
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

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

//1 - 8
//2 - 16

//(2*k+1)^2 - (2*k-1)^2 = 8*k

int solve1(vector<int> a)
{
    int tot = 0;
    int n = a.size();
    for (int i = 0; i<n; i++) tot+=a[i];

    for (int i = 0; i<n; i++) if (a[i]==0) a[i] = -1;

    int best = 0;
    int minn = 0;
    int cur = 0;
    for (auto it: a)
    {
        cur+=it;
        best = max(best, cur - minn);
        minn = min(minn, cur);
    }
    //cout<<tot<<' '<<best<<endl;

    return tot - best;
}

void solve()
{
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;
    int tot = 0;

    for (int i = 0; i<n; i++) if (s[i]=='1') tot++;

    int res = 1e9;

    for (int i = 0; i<k; i++)
    {
        vector<int> kek;
        int subtot = 0;
        for (int j = i; j<n; j+=k)
        {
            if (s[j]=='1')
            {
                subtot++; kek.push_back(1);
            }
            else kek.push_back(0);
        }
        res = min(res, tot-subtot + solve1(kek));

        /*cout<<i<<": ";
        for (auto it: kek) cout<<it<<' ';
        cout<<endl;
        cout<<solve1(kek)<<endl;*/

    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();

}

/*
1
9 2
010001010
 */