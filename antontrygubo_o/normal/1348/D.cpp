#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 998244353;


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

    int maxx = 1;

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
        maxx = max(maxx, sz[a]);
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    };
};*/

void solve()
{

    int n;
    cin>>n;
    n--;
    int cur = 1;
    vector<int> guys = {1};
    while (cur*4<=n)
    {
        cur*=2;
        guys.push_back(cur);
        n-=cur;
    }
    if (n<=2*cur)
    {
        guys.push_back(n);
    }
    else
    {
        guys.push_back(n/2); guys.push_back(n - n/2);
    }

    cout<<guys.size() - 1<<endl;
    for (int i = 0; i+1<guys.size(); i++) cout<<guys[i+1]-guys[i]<<' ';
    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();


}