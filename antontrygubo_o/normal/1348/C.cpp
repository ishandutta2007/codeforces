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
    int n, k;
    cin>>n>>k;
    string s; cin>>s;

    sort(s.begin(), s.end());

    if (s[0]!=s[k-1])
    {
        cout<<s[k-1]<<endl;
        return;
    }
    bool eq = true;
    for (int i = k; i+1<s.size(); i++) if (s[i]!=s[i+1]) eq = false;
    if (!eq) cout<<s[0] + s.substr(k)<<endl;
    else {
        string ans;
        for (int i = 0; i<s.size(); i+=k) ans+=s[i];
        cout<<ans<<endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();


}