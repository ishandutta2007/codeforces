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

vector<int> inv(vector<int> prm)
{
    int n = prm.size();
    vector<int> res(n);
    for (int i = 0; i<n; i++) res[prm[i]] = i;
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> l(n), r(n);
    for (int i = 0; i<n; i++)
    {
        cin>>l[i]>>r[i];
        l[i]--; r[i]--;
    }

    vector<vector<pair<int, int>>> a(n);

    for (int i = 0; i<n; i++) a[l[i]].push_back(mp(r[i], i));

    set<pair<int, int>> guys;

    vector<pair<int, int>> to_try;


    vector<int> prm;

    for (int i = 0; i<n; i++)
    {
        for (auto it: a[i]) guys.insert(it);

        if (guys.size()>=2)
        {
            auto it = guys.begin();
            int x = it->second;
            it = next(it);
            int y = it->second;
            to_try.push_back(mp(x, y));
        }

        auto it = *guys.begin();

        prm.push_back(it.second);
        //cout<<it.second+1<<' ';
        guys.erase(it);
    }

    vector<int> invpos(n);
    for (int i = 0; i<n; i++) invpos[prm[i]] = i;

    vector<vector<int>> kek;
    kek.push_back(inv(prm));


    //cout<<to_try.size()<<endl;

    for (auto it: to_try)
    {

        int x = it.first; int y = it.second;

        //cout<<x<<' '<<y<<endl;

        if (l[y]<=invpos[x] && invpos[x]<=r[y] && l[x]<=invpos[y] && invpos[y]<=r[x])
        {
            swap(prm[invpos[x]], prm[invpos[y]]);
            kek.push_back(inv(prm));
            break;
        }
    }

    if (kek.size()==1)
    {
        cout<<"YES"<<endl;
        for (auto it: kek[0]) cout<<it+1<<' ';
    }
    else
    {
        cout<<"NO"<<endl;
        for (auto it: kek[0]) cout<<it+1<<' ';
        cout<<endl;
        for (auto it: kek[1]) cout<<it+1<<' ';
    }



}