#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


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


const int LIM = 400005;

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
}

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

void print(vector<int> a)
{
    for (auto x: a) cout<<x<<' ';
    cout<<endl;
}

void print(vector<ll> a)
{
    for (auto x: a) cout<<x<<' ';
    cout<<endl;
}

bool check(vector<int> a)
{
    int cur = 0;
    for (int i = 0; i<a.size(); i++)
    {
        cur = a[i] - cur;
        if (cur<0) return false;
    }
    return (cur==0);
}

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    vector<int> R(n, n);

    vector<int> even;
    vector<ll> even_val(n);
    ll adder = 0;
    for (int i = n-1; i>=0; i--)
    {
        if (i%2 == 0)
        {
            adder+=a[i];
            even_val[i] = a[i]-adder;
            while (!even.empty() && even_val[i]<=even_val[even.back()]) even.pop_back();
            even.push_back(i);
        }
        else adder-=a[i];

        /*cout<<i<<": "<<adder<<endl;
        print(even);
        //print(even_val);
        for (auto it: even) cout<<even_val[it]<<' ';
        cout<<endl<<endl;*/

        if (even.size()==0 || even_val[even[0]]+adder>=0) continue;
        int l = 0; int r = even.size();
        while (r-l>1)
        {
            int mid = (l+r)/2;
            if (even_val[even[mid]]+adder<0) l = mid;
            else r = mid;
        }
        R[i] = min(R[i], even[l]);
    }

    vector<int> odd;
    vector<ll> odd_val(n);
    adder = 0;
    for (int i = n-1; i>=0; i--)
    {
        if (i%2 == 1)
        {
            adder+=a[i];
            odd_val[i] = a[i]-adder;
            while (!odd.empty() && odd_val[i]<=odd_val[odd.back()]) odd.pop_back();
            odd.push_back(i);
        }
        else adder-=a[i];

        if (odd.size()==0 || odd_val[odd[0]]+adder>=0) continue;
        int l = 0; int r = odd.size();
        while (r-l>1)
        {
            int mid = (l+r)/2;
            if (odd_val[odd[mid]]+adder<0) l = mid;
            else r = mid;
        }
        R[i] = min(R[i], odd[l]);
    }

    //cout<<"Here"<<endl;
    //print(R);

    vector<ll> pref(n+1);
    for (int i = 0; i<n; i++)
    {
        pref[i+1] = pref[i];
        if (i%2) pref[i+1]+=a[i];
        else pref[i+1]-=a[i];
    }

    map<ll, vector<int>> where;
    for (int i = 0; i<=n; i++) where[pref[i]].push_back(i);

    ll ans = 0;

    for (auto it: where)
    {
        auto vec = it.second;
        int k = vec.size();
        for (int i = 0; i<k; i++)
        {
            if (vec[i]==n) continue;
            int R1 = R[vec[i]] + 1;
            int t = lower_bound(vec.begin(), vec.end(), R1) - vec.begin();
            ans+=(t-i-1);
        }
    }
    cout<<ans<<endl;
    /*for (int i = 0; i<n; i++)
    {
        vector<int> b;
        for (int j = i; j<n; j++)
        {
            b.push_back(a[j]);
            if (check(b))
            {
                cout<<i<<' '<<j<<endl;
                if (R[i]<=j) cout<<"BAD"<<endl;
            }

        }
    }*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}

/*
1
11
1 1 1 1 0 1 0 1 2 1 2

1
7
1 1 1 1 0 1 0
 */