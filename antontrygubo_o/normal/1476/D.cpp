#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair
/*
int p =  1e9 + 7;

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

int po(int a, ll deg)
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
*/

mt19937 rnd(time(0));

/*
const int N = 2000005;

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
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<bool> cycle;
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
        if (a==b) cycle[a] = true;
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            if (cycle[b]) cycle[a] = true;
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        cycle.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/


void solve()
{
    int n;
    string s;
    cin>>n>>s;

    string t;
    for (int i = 0; i<n; i++)
    {
        if (i%2==0) t+=s[i];
        else
        {
            if (s[i]=='R') t+='L';
            else t+='R';
        }
    }

    vector<int> answer(n+1, 1);

    int cur = 0;

    while (cur<n)
    {
        char kek = t[cur];
        int pos = cur;
        while (pos<n && t[pos]==kek) pos++;

        for (int i = cur; i<=pos; i++)
        {
            if (i%2==0 && kek=='R') answer[i]+=(pos-cur);
            else if (i%2==1 && kek=='L') answer[i]+=(pos-cur);
        }
        cur = pos;
    }
    for (auto it: answer) cout<<it<<' ';
    cout<<endl;

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();
}