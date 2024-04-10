#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 1000000007;


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

/*const int N = 1000000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    bool check = true;
    for (int i = 1; i<n; i++) if (a[i]!=a[0]) check = false;

    if (check) {cout<<0; return 0;}


    vector<ll> pref(n+1);
    for (int i = 0; i<n; i++) pref[i+1] = pref[i] + a[i];

    vector<int> minn = {0, 1};
    for (int i = 2; i<=n; i++)
    {
        while (minn.size()>1)
        {
            int lst = minn[minn.size()-1];
            int prlst = minn[minn.size() - 2];
            if ((ld)(pref[lst]-pref[prlst])/(ld)(lst - prlst) > (ld)(pref[lst]-pref[i])/(ld)(lst - i)) minn.pop_back();
            else break;
        }
        minn.push_back(i);
    }

    vector<int> maxx = {n, n-1};
    for (int i = n-2; i>=0; i--)
    {
        while (maxx.size()>1)
        {
            int lst = maxx[maxx.size()-1];
            int prlst = maxx[maxx.size() - 2];
            if ((ld)(pref[lst]-pref[prlst])/(ld)(lst - prlst) > (ld)(pref[lst]-pref[i])/(ld)(lst - i)) maxx.pop_back();
            else break;
        }
        maxx.push_back(i);
    }

    vector<ld> up = {-1e9}, down = {-1e9};
    for (int i = 0; i<maxx.size()-1; i++) up.push_back((ld)(pref[maxx[i+1]]-pref[maxx[i]])/(ld)(maxx[i+1] - maxx[i]));
    for (int i = 0; i<minn.size()-1; i++) down.push_back((ld)(pref[minn[i+1]]-pref[minn[i]])/(ld)(minn[i+1] - minn[i]));

    up.push_back(1e9);
    down.push_back(1e9);

    /*for (auto it: maxx) cout<<it<<' ';
    cout<<endl;
    for (auto it: up) cout<<it<<' ';
    cout<<endl;
    for (auto it: minn) cout<<it<<' ';
    cout<<endl;
    for (auto it: down) cout<<it<<' ';
    cout<<endl;*/

    ld res = 1e18;

    int curup = 0;
    int curdown = 0;
    while (curup<maxx.size()-1||curdown<minn.size()-1)
    {
        //cout<<maxx[curup]<<' '<<minn[curdown]<<endl;
        if (up[curup+1]<down[curdown+1])
        {
            int D = minn[curdown];
            int U = maxx[curup];
            ld R = up[curup+1];
            ld L = max(up[curup], down[curdown]);
            res = min(res, (pref[U] - R*U) - (pref[D] - R*D));
            res = min(res, (pref[U] - L*U) - (pref[D] - L*D));
            curup++;
            //cout<<"bounds: "<<L<<' '<<R<<" res: "<<res<<endl;
        }
        else
        {
            int D = minn[curdown];
            int U = maxx[curup];
            ld R = down[curdown+1];
            ld L = max(up[curup], down[curdown]);
            res = min(res, (pref[U] - R*U) - (pref[D] - R*D));
            res = min(res, (pref[U] - L*U) - (pref[D] - L*D));
            curdown++;
            //cout<<"bounds: "<<L<<' '<<R<<" res: "<<res<<endl;
        }
    }

    cout<<setprecision(10)<<fixed<<res;


}