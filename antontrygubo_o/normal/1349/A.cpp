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

const int N = 500000;

vector<bool> notprime(N);
vector<int> smallest(N, -1);

vector<int> primes;


void init()
{
    for (int i = 2; i<N; i++) if (!notprime[i])
    {
        smallest[i] = i;
        primes.push_back(i);
        for (int j = 2*i; j<N; j+=i)
        {
            notprime[j] = true;
            if (smallest[j]==-1) smallest[j] = i;
        }
    }
}

vector<vector<int>> A(N);

void process(int n)
{
    while (n!=1)
    {
        int q = smallest[n];
        int cnt = 0;
        while (n%q==0)
        {
            cnt++; n/=q;
        }
        A[q].push_back(cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();


    int n;
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i]; process(a[i]);}

    ll res = 1;
    for (auto q: primes)
    {
        if (A[q].size()<=n-2) continue;
        /*cout<<q<<endl;
        for (auto it: A[q]) cout<<it<<' ';
        cout<<endl;*/
        if (A[q].size()<n) A[q].push_back(0);
        sort(A[q].begin(), A[q].end());
        for (int i = 0; i<A[q][1]; i++) res*=q;
    }

    cout<<res;


}